#include "debug/SimpleGraphDebugOpHandler.h"

#include <iostream>

// -----------------------------------------------------------------------------
// SimpleGraphDebugOpHandler
// -----------------------------------------------------------------------------

void SimpleGraphDebugOpHandler::handleOperation(const SimpleGraph::VertexAddOperation &op) {
    std::cout << "Vertex added (" << op.getVertexID() << ")";
    std::cout << std::endl;
}

void SimpleGraphDebugOpHandler::handleOperation(const SimpleGraph::VertexRemoveOperation &op) {
    std::cout << "Vertex removed (" << op.getVertexID() << ")";
    std::cout << std::endl;
}

void SimpleGraphDebugOpHandler::handleOperation(const SimpleGraph::EdgeAddOperation &op) {
    std::cout << "Edge added (" << op.getFromID() << " -> " << op.getToID() << ")";
    std::cout << std::endl;
}

void SimpleGraphDebugOpHandler::handleOperation(const SimpleGraph::EdgeRemoveOperation &op) {
    std::cout << "Edge removed (" << op.getFromID() << " -> " << op.getToID() << ")";
    std::cout << std::endl;
}

void SimpleGraphDebugOpHandler::handleOperation(const SimpleGraph::AttributeAddOperation &op) {
    std::cout << "Attribute added to vertex (" << op.getVertexID() << ": " << op.getAttributeName() << " = "
              << op.getAttributeValue() << ")";
    std::cout << std::endl;
}

void SimpleGraphDebugOpHandler::handleOperation(const SimpleGraph::AttributeRemoveOperation &op) {
    std::cout << "Attribute removed from vertex (" << op.getVertexID() << ": " << op.getAttributeName() << ")";
    std::cout << std::endl;
}

void SimpleGraphDebugOpHandler::handleOperation(const SimpleGraph::AttributeSetOperation &op) {
    std::cout << "Attribute set in vertex (" << op.getVertexID() << ": " << op.getAttributeName() << " = "
              << op.getAttributeValue() << ")";
    std::cout << std::endl;
}
