//
// Created by robin on 04/07/18.
//

#include "MVKSimpleGraphOperationHandler.h"

#define NODETYPE "Vertex"
#define EDGETYPE "Edge"
#define ATTRIBUTETYPE "Attribute"
#define ATTRIBUTEVERTEX "Vertex"
#define ATTRIBUTENAME  "Name"
#define ATTRIBUTEVALUE "Value"

MVKSimpleGraphOperationHandler::MVKSimpleGraphOperationHandler() {
    graph = new collab::SimpleGraph;
    baseConstructor();
}

MVKSimpleGraphOperationHandler::MVKSimpleGraphOperationHandler(
        collab::SimpleGraph *graph) {
    this->graph = graph;
    baseConstructor();
}

MVKSimpleGraphOperationHandler::MVKSimpleGraphOperationHandler(
        collab::SimpleGraph *graph, const std::string savePath) {
    this->graph = graph;
    workingModel = savePath;
    baseConstructor();
}

MVKSimpleGraphOperationHandler::~MVKSimpleGraphOperationHandler() {
    mvkConnector->modelExit();

    delete mvkConnector;
    mvkConnector = nullptr;
    delete graph;
    graph = nullptr;
}

void MVKSimpleGraphOperationHandler::applyOperation(
        const collab::SimpleGraph::VertexAddOperation operation) {
    mvkConnector->instantiateNode(NODETYPE, operation.vertexID());
    if (!isModelCorrect()) {
        mvkConnector->deleteElement(operation.vertexID());
        graph->removeVertex(operation.vertexID());
    }
}

void MVKSimpleGraphOperationHandler::applyOperation(
        const collab::SimpleGraph::VertexRemoveOperation operation) {
    mvkConnector->deleteElement(operation.vertexID());
    if (!isModelCorrect()) {
        mvkConnector->instantiateNode(NODETYPE, operation.vertexID());
        graph->addVertex(operation.vertexID());
    }
}

void MVKSimpleGraphOperationHandler::applyOperation(
        const collab::SimpleGraph::EdgeAddOperation operation) {
    mvkConnector->instantiateEdge(EDGETYPE,
                                  operation.fromID() + operation.toID(),
                                  operation.fromID(), operation.toID());
    if (!isModelCorrect()) {
        mvkConnector->deleteElement(operation.fromID() + operation.toID());
        graph->removeEdge(operation.fromID(), operation.toID());
    }
}

void MVKSimpleGraphOperationHandler::applyOperation(
        const collab::SimpleGraph::EdgeRemoveOperation operation) {
    mvkConnector->deleteElement(operation.fromID() + operation.toID());
    if (!isModelCorrect()) {
        mvkConnector->instantiateEdge(EDGETYPE,
                                      operation.fromID() + operation.toID(),
                                      operation.fromID(), operation.toID());
        graph->addEdge(operation.fromID(), operation.toID());
    }
}

void MVKSimpleGraphOperationHandler::applyOperation(
        const collab::SimpleGraph::AttributeAddOperation operation) {
    mvkConnector->instantiateNode(ATTRIBUTETYPE, operation.vertexID() +
                                                 operation.attributeName());
    mvkConnector->attributeAddModify(operation.vertexID() +
                                     operation.attributeName(), ATTRIBUTENAME,
                                     operation.attributeName());
    mvkConnector->attributeAddModify(operation.vertexID() +
                                     operation.attributeName(), ATTRIBUTEVALUE,
                                     operation.attributeValue());
    mvkConnector->attributeAddModify(
            operation.vertexID() + operation.attributeName(), ATTRIBUTEVERTEX,
            operation.vertexID());
    if (!isModelCorrect()) {
        mvkConnector->deleteElement(
                operation.vertexID() + operation.attributeName());
        graph->removeAttribute(operation.vertexID(), operation.attributeName());
    }
}

void MVKSimpleGraphOperationHandler::applyOperation(
        const collab::SimpleGraph::AttributeRemoveOperation operation) {
    std::string value = getAttributeValue(
            operation.vertexID() + operation.attributeName());
    mvkConnector->deleteElement(
            operation.vertexID() + operation.attributeName());
    if (!isModelCorrect()) {
        graph->addAttribute(operation.vertexID(), operation.attributeName(),
                            value);
        mvkConnector->instantiateNode(ATTRIBUTETYPE, operation.vertexID() +
                                                     operation.attributeName());
        mvkConnector->attributeAddModify(operation.vertexID() +
                                         operation.attributeName(),
                                         ATTRIBUTENAME,
                                         operation.attributeName());
        mvkConnector->attributeAddModify(operation.vertexID() +
                                         operation.attributeName(),
                                         ATTRIBUTEVALUE,
                                         value);
        mvkConnector->attributeAddModify(
                operation.vertexID() + operation.attributeName(),
                ATTRIBUTEVERTEX,
                operation.vertexID());
    }
}

void MVKSimpleGraphOperationHandler::applyOperation(
        const collab::SimpleGraph::AttributeSetOperation operation) {
    std::string value = getAttributeValue(
            operation.vertexID() + operation.attributeName());
    mvkConnector->attributeAddModify(
            operation.vertexID() + operation.attributeName(), ATTRIBUTEVALUE,
            operation.newValue());
    if (!isModelCorrect()) {
        graph->setAttribute(operation.vertexID(), operation.attributeName(),
                            value);
        mvkConnector->attributeAddModify(
                operation.vertexID() + operation.attributeName(),
                ATTRIBUTEVALUE, value);
    }
}

bool MVKSimpleGraphOperationHandler::isModelCorrect() {
    bool res = true;
    mvkConnector->modelExit();
    mvkConnector->modelVerify(workingModel, metaModel);
    if (mvkConnector->getDatabaseAnswer() != "\"Success: OK\"") {
        res = false;
    }
    mvkConnector->modelModify(workingModel, metaModel);
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
        if (realType == NODETYPE) {
            graph->addVertex(cJSON_GetStringValue(
                    cJSON_GetObjectItem(elementJson, "__id")));
        } else if (realType == EDGETYPE) {
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
    //mvkConnector = new MVKWrapper(LOCALCONNECTIONADRESS, true);
    mvkConnector = new MVKWrapper;
    mvkConnector->connect("admin", "admin");
    generateMetamodel();

    //TODO if model exist
    mvkConnector->modelAdd(workingModel, metaModel, "");
    mvkConnector->modelModify(workingModel, metaModel);
}

void MVKSimpleGraphOperationHandler::generateMetamodel() {
    // TODO Add constraint about Edge between same Vertex
    const std::string workingModel = "formalisms/SimpleGraph";
    const std::string metamodel = "formalisms/SimpleClassDiagrams";
    const std::string vertex = "Vertex";
    const std::string edge = "Edge";
    const std::string attribute = "Attribute";
    const std::string string = "String";

    mvkConnector->modelAdd(workingModel, metamodel, "");
    if (mvkConnector->getDatabaseAnswer() !=
        "\"Model exists: formalisms/SimpleGraph\"") {
        mvkConnector->modelModify(workingModel, metamodel);

        mvkConnector->instantiateNode("Class", vertex);
        mvkConnector->instantiateEdge("Association", edge, vertex, vertex);
        mvkConnector->instantiateNode("Class", attribute);

        mvkConnector->instantiateNode(string, string);
        mvkConnector->defineAttribute(attribute, vertex, string);
        mvkConnector->defineAttribute(attribute, "Name", string);
        mvkConnector->defineAttribute(attribute, "Value", string);

        mvkConnector->modelExit();
    }
}

cJSON *MVKSimpleGraphOperationHandler::getJSON() {
    mvkConnector->JSON();
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

std::string
MVKSimpleGraphOperationHandler::getAttributeValue(std::string attributeId) {
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