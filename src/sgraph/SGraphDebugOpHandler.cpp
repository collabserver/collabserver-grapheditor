#include "sgraph/SGraphDebugOpHandler.h"

#include <iostream>


// -----------------------------------------------------------------------------
// SGraphOpHandlerDebug
// -----------------------------------------------------------------------------

void SGraphOpHandlerDebug::handleOperation(const SGraph::VertexAddOperation &op) {
    std::cout << "Vertex added (" << op.vertexID() << ")";
    std::cout << std::endl;
}

void SGraphOpHandlerDebug::handleOperation(const SGraph::VertexRemoveOperation &op) {
    std::cout << "Vertex removed (" << op.vertexID() << ")";
    std::cout << std::endl;
}

void SGraphOpHandlerDebug::handleOperation(const SGraph::EdgeAddOperation &op) {
    std::cout << "Edge added (" << op.fromID() << " -> " << op.toID() << ")";
    std::cout << std::endl;
}

void SGraphOpHandlerDebug::handleOperation(const SGraph::EdgeRemoveOperation &op) {
    std::cout << "Edge removed (" << op.fromID() << " -> " << op.toID() << ")";
    std::cout << std::endl;
}

void SGraphOpHandlerDebug::handleOperation(const SGraph::AttributeAddOperation &op) {
    std::cout << "Attribute added to vertex (" << op.vertexID() << ": "
              << op.attributeName() << " = " << op.attributeValue() << ")";
    std::cout << std::endl;
}

void SGraphOpHandlerDebug::handleOperation(const SGraph::AttributeRemoveOperation &op) {
    std::cout << "Attribute removed from vertex (" << op.vertexID() << ": "
              << op.attributeName() << ")";
    std::cout << std::endl;
}

void SGraphOpHandlerDebug::handleOperation(const SGraph::AttributeSetOperation &op) {
    std::cout << "Attribute set in vertex (" << op.vertexID() << ": "
              << op.attributeName() << " = " << op.newValue() << ")";
    std::cout << std::endl;
}


