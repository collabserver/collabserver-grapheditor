#include "sgraph/SGraphMvkMapper.h"

#include <cassert>


// -----------------------------------------------------------------------------
// Internal
// -----------------------------------------------------------------------------

#define ELEMENT_TYPE        "Vertex"
#define EDGE_TYPE           "Edge"
#define ATTRIBUTE_TYPE      "Attribute"
#define ATTRIBUTE_VERTEX    "Vertex"
#define ATTRIBUTE_NAME      "Name"
#define ATTRIBUTE_VALUE     "Value"

static bool isModelValid(MvkWrapper* mvk,
                         const std::string& model,
                         const std::string& mmodel) {
    // DevNote: you already entered model
    assert(mvk != nullptr);
    mvk->modelVerify(model, mmodel);
    return mvk->isSuccess();
}


// -----------------------------------------------------------------------------
// INIT
// -----------------------------------------------------------------------------

SGraphMvkMapper::SGraphMvkMapper(MvkWrapper* mvk) : _mvk(mvk) {
    assert(mvk != nullptr);
}


// -----------------------------------------------------------------------------
// CRUD
// -----------------------------------------------------------------------------

bool SGraphMvkMapper::vertexAdd(const std::string& model,
                                const std::string& metamodel,
                                const std::string& name) const {
    _mvk->modelEnter(model, metamodel);
    _mvk->elementCreate(ELEMENT_TYPE, name);

    bool success = isModelValid(_mvk, model, metamodel);
    _mvk->modelExit();
    return success;
}

bool SGraphMvkMapper::vertexRemove(const std::string& model,
                                   const std::string& metamodel,
                                   const std::string& name) const {
    _mvk->modelEnter(model, metamodel);
    _mvk->elementDelete(name);

    bool success = isModelValid(_mvk, model, metamodel);
    _mvk->modelExit();
    return success;
}

bool SGraphMvkMapper::edgeAdd(const std::string& model,
                              const std::string& metamodel,
                              const std::string& from,
                              const std::string& to) const {
    std::string uniqueID = (from + to); // This creates a unique name

    _mvk->modelEnter(model, metamodel);
    _mvk->edgeCreate(EDGE_TYPE, uniqueID, from, to);

    bool success = isModelValid(_mvk, model, metamodel);
    _mvk->modelExit();
    return success;
}

bool SGraphMvkMapper::edgeRemove(const std::string& model,
                                 const std::string& metamodel,
                                 const std::string& from,
                                 const std::string& to) const {
    std::string uniqueID = (from + to);

    _mvk->modelEnter(model, metamodel);
    _mvk->elementDelete(uniqueID);

    bool success = isModelValid(_mvk, model, metamodel);
    _mvk->modelExit();
    return success;
}

bool SGraphMvkMapper::attributeAdd(const std::string& model,
                                   const std::string& metamodel,
                                   const std::string& vertexID,
                                   const std::string& attrName,
                                   const std::string& attrValue) const {
    std::string attributeID = vertexID + attrName; // Creates internal MVK id.

    _mvk->modelEnter(model, metamodel);
    _mvk->elementCreate(ATTRIBUTE_TYPE, attributeID);
    _mvk->attributeSet(attributeID, ATTRIBUTE_NAME, attrName);
    _mvk->attributeSet(attributeID, ATTRIBUTE_VALUE, attrValue);
    _mvk->attributeSet(attributeID, ATTRIBUTE_VERTEX, vertexID);

    bool success = isModelValid(_mvk, model, metamodel);
    _mvk->modelExit();
    return success;
}

bool SGraphMvkMapper::attributeRemove(const std::string& model,
                                      const std::string& metamodel,
                                      const std::string& vertexID,
                                      const std::string& attrName) const {
    std::string attributeID = vertexID + attrName;

    _mvk->modelEnter(model, metamodel);
    _mvk->elementDelete(attributeID);

    bool success = isModelValid(_mvk, model, metamodel);
    _mvk->modelExit();
    return success;
}

bool SGraphMvkMapper::attributeSet(const std::string& model,
                                   const std::string& metamodel,
                                   const std::string& vertexID,
                                   const std::string& attrName,
                                   const std::string& attrValue) const {
    std::string attributeID = vertexID + attrName;

    _mvk->modelEnter(model, metamodel);
    _mvk->attributeSet(attributeID, ATTRIBUTE_VALUE, attrValue);

    bool success = isModelValid(_mvk, model, metamodel);
    _mvk->modelExit();
    return success;
}


