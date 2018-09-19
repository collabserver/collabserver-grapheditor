#include "MVKSimpleGraphOperationHandler.h"

#include <cassert>


#define ELEMENT_TYPE        "Vertex"
#define EDGE_TYPE           "Edge"
#define ATTRIBUTE_TYPE      "Attribute"
#define ATTRIBUTE_VERTEX    "Vertex"
#define ATTRIBUTE_NAME      "Name"
#define ATTRIBUTE_VALUE     "Value"

typedef collab::SimpleGraph SGraph;


MVKSimpleGraphOperationHandler::MVKSimpleGraphOperationHandler() {
    graph = collab::SimpleGraph::buildNew(42); // 42 is dummy ID: see SimpleGraph doc
    baseConstructor();
}

MVKSimpleGraphOperationHandler::MVKSimpleGraphOperationHandler(
        collab::SimpleGraph *graph) {
    this->graph = graph;
    baseConstructor();
}

MVKSimpleGraphOperationHandler::MVKSimpleGraphOperationHandler(
        collab::SimpleGraph* graph, const std::string savePath) {
    this->graph = graph;
    workingModel = savePath;
    baseConstructor();
}

MVKSimpleGraphOperationHandler::~MVKSimpleGraphOperationHandler() {
    mvkConnector->modelExit();

    assert(mvkConnector != nullptr);
    assert(graph != nullptr);

    delete mvkConnector;
    delete graph;
    mvkConnector = nullptr;
    graph = nullptr;
}

typedef SGraph::VertexAddOperation VertexAddOP;
void MVKSimpleGraphOperationHandler::applyOperation(const VertexAddOP op) {
    mvkConnector->elementCreate(ELEMENT_TYPE, op.vertexID());
    if (!isModelCorrect()) {
        mvkConnector->elementDelete(op.vertexID());
        graph->removeVertex(op.vertexID());
    }
}

typedef SGraph::VertexRemoveOperation VertexRemOP;
void MVKSimpleGraphOperationHandler::applyOperation(const VertexRemOP op) {
    mvkConnector->elementDelete(op.vertexID());
    if (!isModelCorrect()) {
        mvkConnector->elementCreate(ELEMENT_TYPE, op.vertexID());
        graph->addVertex(op.vertexID());
    }
}

typedef SGraph::EdgeAddOperation EdgeAddOP;
void MVKSimpleGraphOperationHandler::applyOperation(const EdgeAddOP op) {
    mvkConnector->edgeCreate(EDGE_TYPE, (op.fromID() + op.toID()),
                             op.fromID(), op.toID());
    if(!isModelCorrect()) {
        mvkConnector->elementDelete(op.fromID() + op.toID());
        graph->removeEdge(op.fromID(), op.toID());
    }
}

typedef SGraph::EdgeRemoveOperation EdgeRemOP;
void MVKSimpleGraphOperationHandler::applyOperation(const EdgeRemOP op) {
    mvkConnector->elementDelete(op.fromID() + op.toID());
    if (!isModelCorrect()) {
        mvkConnector->edgeCreate(EDGE_TYPE, (op.fromID() + op.toID()),
                                 op.fromID(), op.toID());
        graph->addEdge(op.fromID(), op.toID());
    }
}

typedef SGraph::AttributeAddOperation AttrAddOP;
void MVKSimpleGraphOperationHandler::applyOperation(const AttrAddOP op) {
    mvkConnector->elementCreate(ATTRIBUTE_TYPE, op.vertexID() + op.attributeName());
    mvkConnector->attributeSet(op.vertexID() + op.attributeName(), ATTRIBUTE_NAME,
                               op.attributeName());
    mvkConnector->attributeSet(op.vertexID() + op.attributeName(), ATTRIBUTE_VALUE,
                               op.attributeValue());
    mvkConnector->attributeSet(op.vertexID() + op.attributeName(), ATTRIBUTE_VERTEX,
                               op.vertexID());
    if(!isModelCorrect()) {
        mvkConnector->elementDelete(op.vertexID() + op.attributeName());
        graph->removeAttribute(op.vertexID(), op.attributeName());
    }
}

typedef SGraph::AttributeRemoveOperation AttrRemOP;
void MVKSimpleGraphOperationHandler::applyOperation(const AttrRemOP op) {
    std::string value = getAttributeValue(op.vertexID() + op.attributeName());

    mvkConnector->elementDelete(op.vertexID() + op.attributeName());

    if(!isModelCorrect()) {
        graph->addAttribute(op.vertexID(), op.attributeName(),
                            value);
        mvkConnector->elementCreate(ATTRIBUTE_TYPE,
                                    op.vertexID() + op.attributeName());
        mvkConnector->attributeSet(op.vertexID() + op.attributeName(),
                                   ATTRIBUTE_NAME, op.attributeName());
        mvkConnector->attributeSet(op.vertexID() + op.attributeName(),
                                   ATTRIBUTE_VALUE, value);
        mvkConnector->attributeSet(op.vertexID() + op.attributeName(),
                                   ATTRIBUTE_VERTEX, op.vertexID());
    }
}

typedef SGraph::AttributeSetOperation AttrSetOP;
void MVKSimpleGraphOperationHandler::applyOperation(const AttrSetOP op) {
    std::string value = getAttributeValue(op.vertexID() + op.attributeName());
    mvkConnector->attributeSet(op.vertexID() + op.attributeName(), ATTRIBUTE_VALUE,
                               op.newValue());
    if(!isModelCorrect()) {
        graph->setAttribute(op.vertexID(), op.attributeName(), value);
        mvkConnector->attributeSet(op.vertexID() + op.attributeName(),
                                   ATTRIBUTE_VALUE, value);
    }
}

bool MVKSimpleGraphOperationHandler::isModelCorrect() {
    bool res = true;
    mvkConnector->modelExit();
    mvkConnector->modelVerify(workingModel, metaModel);
    if (mvkConnector->getDatabaseAnswer() != "\"Success: OK\"") {
        res = false;
    }
    mvkConnector->modelEnter(workingModel, metaModel);
    return res;
}

void MVKSimpleGraphOperationHandler::loadModel() {
    cJSON *modelJSON = getJSON();
    cJSON *elementJson;

    char *type;
    std::string realType;
    for (int i = 0; i < cJSON_GetArraySize(modelJSON); i++) {
        elementJson = cJSON_GetArrayItem(modelJSON, i);
        type = cJSON_GetStringValue(
                cJSON_GetObjectItem(elementJson, "__type"));
        realType = type;
        if (realType == ELEMENT_TYPE) {
            graph->addVertex(cJSON_GetStringValue(
                    cJSON_GetObjectItem(elementJson, "__id")));
        } else if (realType == EDGE_TYPE) {
            graph->addEdge(cJSON_GetStringValue(
                    cJSON_GetObjectItem(elementJson, "__source")),
                           cJSON_GetStringValue(
                                   cJSON_GetObjectItem(elementJson,
                                                       "__target")));
        } else {
            graph->addAttribute(cJSON_GetStringValue(
                    cJSON_GetObjectItem(elementJson, "Vertex")),
                                cJSON_GetStringValue(
                                        cJSON_GetObjectItem(elementJson,
                                                            "Name")),
                                cJSON_GetStringValue(
                                        cJSON_GetObjectItem(elementJson,
                                                            "Value")));
        }
        delete type;
    }
    type = nullptr;
    delete modelJSON;
    modelJSON = nullptr;
}

void MVKSimpleGraphOperationHandler::baseConstructor() {
    mvkConnector = new MVKWrapper();
    mvkConnector->connect("localhost", 8001, "admin", "admin");
    generateMetamodel();

    mvkConnector->modelAdd(workingModel, metaModel, "");
    if (mvkConnector->getDatabaseAnswer() ==
        "\"Model exists: " + workingModel + "\"") {
        //TODO if model exist load it
        std::cout<<graph->nbVertices()<<"\n";
        mvkConnector->modelEnter(workingModel, metaModel);
        loadModel();
        std::cout<<graph->nbVertices()<<"\n";
    } else {
        mvkConnector->modelEnter(workingModel, metaModel);
    }
}

void MVKSimpleGraphOperationHandler::generateMetamodel() {
    // TODO Add constraint about Edge between same Vertex
    const std::string workingMetaModel = "formalisms/SimpleGraph";
    const std::string metaMetaModel = "formalisms/SimpleClassDiagrams";
    const std::string vertex = "Vertex";
    const std::string edge = "Edge";
    const std::string attribute = "Attribute";
    const std::string string = "String";

    mvkConnector->modelAdd(workingMetaModel, metaMetaModel, "");
    if (mvkConnector->getDatabaseAnswer() !=
        "\"Model exists: " + workingMetaModel + "\"") {
        mvkConnector->modelEnter(workingMetaModel, metaMetaModel);

        mvkConnector->elementCreate("Class", vertex);
        mvkConnector->edgeCreate("Association", edge, vertex, vertex);
        mvkConnector->elementCreate("Class", attribute);

        mvkConnector->elementCreate(string, string);
        mvkConnector->attributeDefine(attribute, vertex, string);
        mvkConnector->attributeDefine(attribute, "Name", string);
        mvkConnector->attributeDefine(attribute, "Value", string);

        mvkConnector->modelExit();
    }
}

cJSON *MVKSimpleGraphOperationHandler::getJSON() {
    mvkConnector->elementListJSON();
    std::string modelStringJSON = mvkConnector->getCleanDatabaseAnswer();
    for (int i = 0; i < modelStringJSON.length(); i++) {
        if (modelStringJSON.at(i) == '\\') {
            modelStringJSON = modelStringJSON.erase(i, 1);
            i--;
        }
    }
    modelStringJSON = modelStringJSON;
    cJSON *modelJSON = cJSON_Parse(modelStringJSON.c_str());
    if (modelJSON == nullptr) {
        return 0;
    }
    return modelJSON;
}

std::string MVKSimpleGraphOperationHandler::getAttributeValue(std::string attributeId) {
    cJSON *modelJSON = getJSON();
    cJSON *elementJSON;
    int i = 0;
    char *id;
    std::string realId;
    do {
        elementJSON = cJSON_GetArrayItem(modelJSON, i);
        id = cJSON_GetStringValue(
                cJSON_GetObjectItem(elementJSON, "__id"));
        realId = id;

        i++;
        delete id;
    } while (i < cJSON_GetArraySize(modelJSON) &&
             (realId != attributeId));
    id = cJSON_GetStringValue(
            cJSON_GetObjectItem(elementJSON, "Value"));
    std::string value = id;

    delete id;
    id = nullptr;
    delete modelJSON;
    modelJSON = nullptr;

    return value;
}
