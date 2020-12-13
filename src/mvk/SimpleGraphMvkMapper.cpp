#include "mvk/SimpleGraphMvkMapper.h"

#include <cJSON.h>

#include <cassert>
#include <cstring>

// -----------------------------------------------------------------------------
// Internal
// -----------------------------------------------------------------------------

#define ELEMENT_TYPE "Vertex"
#define EDGE_TYPE "Edge"
#define ATTRIBUTE_TYPE "Attribute"
#define ATTRIBUTE_VERTEX "Vertex"
#define ATTRIBUTE_NAME "Name"
#define ATTRIBUTE_VALUE "Value"

static bool isModelValid(MvkWrapper* mvk, const std::string& model, const std::string& mmodel) {
    // DevNote: you already entered model
    assert(mvk != nullptr);
    mvk->modelVerify(model, mmodel);
    return mvk->isSuccess();
}

// -----------------------------------------------------------------------------
// INIT
// -----------------------------------------------------------------------------

SimpleGraphMvkMapper::SimpleGraphMvkMapper(MvkWrapper* mvk) : _mvk(mvk) { assert(mvk != nullptr); }

// -----------------------------------------------------------------------------
// CRUD
// -----------------------------------------------------------------------------

bool SimpleGraphMvkMapper::vertexAdd(const std::string& model, const std::string& metamodel,
                                     const std::string& name) const {
    _mvk->modelEnter(model, metamodel);
    _mvk->elementCreate(ELEMENT_TYPE, name);

    bool success = isModelValid(_mvk, model, metamodel);
    _mvk->modelExit();
    return success;
}

bool SimpleGraphMvkMapper::vertexRemove(const std::string& model, const std::string& metamodel,
                                        const std::string& name) const {
    _mvk->modelEnter(model, metamodel);
    _mvk->elementDelete(name);

    bool success = isModelValid(_mvk, model, metamodel);
    _mvk->modelExit();
    return success;
}

bool SimpleGraphMvkMapper::edgeAdd(const std::string& model, const std::string& metamodel, const std::string& from,
                                   const std::string& to) const {
    std::string uniqueID = (from + to);  // This creates a unique name

    _mvk->modelEnter(model, metamodel);
    _mvk->edgeCreate(EDGE_TYPE, uniqueID, from, to);

    bool success = isModelValid(_mvk, model, metamodel);
    _mvk->modelExit();
    return success;
}

bool SimpleGraphMvkMapper::edgeRemove(const std::string& model, const std::string& metamodel, const std::string& from,
                                      const std::string& to) const {
    std::string uniqueID = (from + to);

    _mvk->modelEnter(model, metamodel);
    _mvk->elementDelete(uniqueID);

    bool success = isModelValid(_mvk, model, metamodel);
    _mvk->modelExit();
    return success;
}

bool SimpleGraphMvkMapper::attributeAdd(const std::string& model, const std::string& metamodel,
                                        const std::string& vertexID, const std::string& attrName,
                                        const std::string& attrValue) const {
    std::string attributeID = vertexID + attrName;  // Creates internal MVK id.

    _mvk->modelEnter(model, metamodel);
    _mvk->elementCreate(ATTRIBUTE_TYPE, attributeID);
    _mvk->attributeSet(attributeID, ATTRIBUTE_NAME, attrName);
    _mvk->attributeSet(attributeID, ATTRIBUTE_VALUE, attrValue);
    _mvk->attributeSet(attributeID, ATTRIBUTE_VERTEX, vertexID);

    bool success = isModelValid(_mvk, model, metamodel);
    _mvk->modelExit();
    return success;
}

bool SimpleGraphMvkMapper::attributeRemove(const std::string& model, const std::string& metamodel,
                                           const std::string& vertexID, const std::string& attrName) const {
    std::string attributeID = vertexID + attrName;

    _mvk->modelEnter(model, metamodel);
    _mvk->elementDelete(attributeID);

    bool success = isModelValid(_mvk, model, metamodel);
    _mvk->modelExit();
    return success;
}

bool SimpleGraphMvkMapper::attributeSet(const std::string& model, const std::string& metamodel,
                                        const std::string& vertexID, const std::string& attrName,
                                        const std::string& attrValue) const {
    std::string attributeID = vertexID + attrName;

    _mvk->modelEnter(model, metamodel);
    _mvk->attributeSet(attributeID, ATTRIBUTE_VALUE, attrValue);

    bool success = isModelValid(_mvk, model, metamodel);
    _mvk->modelExit();
    return success;
}

bool SimpleGraphMvkMapper::loadGraph(const std::string& model, const std::string& metamodel, SimpleGraph& graph) const {
    _mvk->modelEnter(model, metamodel);
    if (!_mvk->isSuccess()) {
        // Means model/metamodel doesn't exists :'(
        return false;
    }

    // Get JSON from MvkWrapper
    _mvk->elementListJSON();
    std::string buffer = _mvk->getResponseBuffer();
    if (buffer.length() > 11) {
        // Check MVK message format content for further information
        buffer = buffer.substr(10, buffer.length() - 11);
    }
    for (int i = 0; i < buffer.length(); i++) {
        if (buffer.at(i) == '\\') {
            buffer = buffer.erase(i, 1);
            i--;
        }
    }
    cJSON* bufferJSON = cJSON_Parse(buffer.c_str());
    if (bufferJSON == nullptr) {
        return false;
    }

    // Parse JSON
    cJSON* eltJSON = nullptr;
    char* type = nullptr;

    for (int i = 0; i < cJSON_GetArraySize(bufferJSON); i++) {
        eltJSON = cJSON_GetArrayItem(bufferJSON, i);
        type = cJSON_GetStringValue(cJSON_GetObjectItem(eltJSON, "__type"));

        if (std::strcmp(type, ELEMENT_TYPE)) {
            cJSON* elt = cJSON_GetObjectItem(eltJSON, "__id");
            graph.addVertex(cJSON_GetStringValue(elt));
        } else if (std::strcmp(type, EDGE_TYPE)) {
            cJSON* src = cJSON_GetObjectItem(eltJSON, "__source");
            cJSON* dest = cJSON_GetObjectItem(eltJSON, "__target");

            graph.addEdge(cJSON_GetStringValue(src), cJSON_GetStringValue(dest));
        } else {
            cJSON* vertex = cJSON_GetObjectItem(eltJSON, "Vertex");
            cJSON* name = cJSON_GetObjectItem(eltJSON, "Name");
            cJSON* value = cJSON_GetObjectItem(eltJSON, "Value");

            graph.addAttribute(cJSON_GetStringValue(vertex), cJSON_GetStringValue(name), cJSON_GetStringValue(value));
        }
        delete type;
    }

    delete bufferJSON;
    return true;
}
