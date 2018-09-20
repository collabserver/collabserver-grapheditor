#include "SGraphMVKMapper.h"

#include <cassert>

#define ELEMENT_TYPE        "Vertex"
#define EDGE_TYPE           "Edge"
#define ATTRIBUTE_TYPE      "Attribute"
#define ATTRIBUTE_VERTEX    "Vertex"
#define ATTRIBUTE_NAME      "Name"
#define ATTRIBUTE_VALUE     "Value"


// -----------------------------------------------------------------------------
// INIT
// -----------------------------------------------------------------------------

SGraphMVKMapper::SGraphMVKMapper(MVKWrapper* mvk) : _mvk(mvk) {
    assert(mvk != nullptr);
}


// -----------------------------------------------------------------------------
// CRUD
// -----------------------------------------------------------------------------

bool SGraphMVKMapper::vertexAdd(const std::string& name) {
    _mvk->elementCreate(ELEMENT_TYPE, name);
    return isModelValid();
}

bool SGraphMVKMapper::vertexRemove(const std::string& name) {
    _mvk->elementDelete(name);
    return isModelValid();
}

bool SGraphMVKMapper::edgeAdd(const std::string& from, const std::string& to) {
    std::string name = (from + to); // This creates a unique name
    _mvk->edgeCreate(EDGE_TYPE, name, from, to);
    return isModelValid();
}

bool SGraphMVKMapper::edgeRemove(const std::string& from, const std::string& to) {
    std::string name = (from + to);
    _mvk->elementDelete(name);
    return isModelValid();
}

bool SGraphMVKMapper::attributeAdd(const std::string& elt,
                                   const std::string& attrName,
                                   const std::string& attrValue) {
    std::string attributeID = elt + attrName; // Creates internal MVK id.

    _mvk->elementCreate(ATTRIBUTE_TYPE, attributeID);
    _mvk->attributeSet(attributeID, ATTRIBUTE_NAME, attrName);
    _mvk->attributeSet(attributeID, ATTRIBUTE_VALUE, attrValue);
    _mvk->attributeSet(attributeID, ATTRIBUTE_VERTEX, elt);

    return isModelValid();
}

bool SGraphMVKMapper::attributeRemove(const std::string& elt,
                                      const std::string& attrName) {
    std::string attributeID = elt + attrName;
    _mvk->elementDelete(attributeID);
    return isModelValid();
}

bool SGraphMVKMapper::attributeSet(const std::string& elt,
                                   const std::string& attrName,
                                   const std::string& attrValue) {
    std::string attributeID = elt + attrName;
    _mvk->attributeSet(attributeID, ATTRIBUTE_VALUE, attrValue);
    return isModelValid();
}


// -----------------------------------------------------------------------------
// Internal
// -----------------------------------------------------------------------------

bool SGraphMVKMapper::isModelValid() {
    bool isValide = false;
    _mvk->modelExit();
    _mvk->modelVerify(_model, _metamodel);
    if(_mvk->getDatabaseAnswer() == "\"Success: OK\"") {
        isValide = true;
    }
    _mvk->modelEnter(_model, _metamodel);
    return isValide;
}


