#include "sgraph/SGraphDebugOpHandler.h"

#include <iostream>


// -----------------------------------------------------------------------------
// SGraphDebugOpHandler
// -----------------------------------------------------------------------------

void SGraphDebugOpHandler::handleOperation(const SGraph::VertexAddOperation &op) {
    std::cout << "Vertex added (" << op.getVertexID() << ")";
    std::cout << std::endl;
}

void SGraphDebugOpHandler::handleOperation(const SGraph::VertexRemoveOperation &op) {
    std::cout << "Vertex removed (" << op.getVertexID() << ")";
    std::cout << std::endl;
}

void SGraphDebugOpHandler::handleOperation(const SGraph::EdgeAddOperation &op) {
    std::cout << "Edge added (" << op.getFromID() << " -> " << op.getToID() << ")";
    std::cout << std::endl;
}

void SGraphDebugOpHandler::handleOperation(const SGraph::EdgeRemoveOperation &op) {
    std::cout << "Edge removed (" << op.getFromID() << " -> " << op.getToID() << ")";
    std::cout << std::endl;
}

void SGraphDebugOpHandler::handleOperation(const SGraph::AttributeAddOperation &op) {
    std::cout << "Attribute added to vertex (" << op.getVertexID() << ": "
              << op.getAttributeName() << " = " << op.getAttributeValue() << ")";
    std::cout << std::endl;
}

void SGraphDebugOpHandler::handleOperation(const SGraph::AttributeRemoveOperation &op) {
    std::cout << "Attribute removed from vertex (" << op.getVertexID() << ": "
              << op.getAttributeName() << ")";
    std::cout << std::endl;
}

void SGraphDebugOpHandler::handleOperation(const SGraph::AttributeSetOperation &op) {
    std::cout << "Attribute set in vertex (" << op.getVertexID() << ": "
              << op.getAttributeName() << " = " << op.getAttributeValue() << ")";
    std::cout << std::endl;
}


