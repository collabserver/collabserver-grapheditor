#include <iostream>
#include "SimpleGraphOperationHandler.h"

void SimpleGraphOperationHandler::handleOperation(const collab::SimpleGraph::VertexAddOperation &op){
std::cout << "Vertex \"" << op.vertexID() << "\" added" << std::endl;
}
void SimpleGraphOperationHandler::handleOperation(const collab::SimpleGraph::VertexRemoveOperation &op){
std::cout << "Vertex \"" << op.vertexID() << "\" removed" << std::endl;
}
void SimpleGraphOperationHandler::handleOperation(const collab::SimpleGraph::EdgeAddOperation &op){
    std::cout << "Edge added bewteen \"" << op.fromID() << "\" and \"" << op.toID() << "\"" << std::endl;
}
void SimpleGraphOperationHandler::handleOperation(const collab::SimpleGraph::EdgeRemoveOperation &op){
    std::cout << "Edge removed bewteen \"" << op.fromID() << "\" and \"" << op.toID() << "\"" << std::endl;
}
void SimpleGraphOperationHandler::handleOperation(const collab::SimpleGraph::AttributeAddOperation &op){
    std::cout << "Attribute \"" << op.attributeName() << "\" added to vertex \"" << op.vertexID() << "\" with value \"" << op.attributeValue() << "\"" << std::endl;
}
void SimpleGraphOperationHandler::handleOperation(const collab::SimpleGraph::AttributeRemoveOperation &op){
    std::cout << "Attribute \"" << op.attributeName() << "\" removed from vertex \"" << op.vertexID() << "\"" << std::endl;
}
void SimpleGraphOperationHandler::handleOperation(const collab::SimpleGraph::AttributeSetOperation &op){
    std::cout << "Attribute \"" << op.attributeName() << "\" from vertex \"" << op.vertexID() << "\" set with value \"" << op.newValue() << "\"" << std::endl;
}