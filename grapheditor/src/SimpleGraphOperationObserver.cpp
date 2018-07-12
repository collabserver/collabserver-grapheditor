#include "SimpleGraphOperationObserver.h"
#include <iostream>

SimpleGraphOperationObserver::SimpleGraphOperationObserver(){};

void SimpleGraphOperationObserver::onOperation(const collab::Operation &op)
{

    std::cout << "Operation received" << std::endl;
   /* int type = op.getType();
    switch (type)
    {
    case static_cast<int>(collab::SimpleGraph::OPERATION_VERTEX_ADD):
    {
        applyOperation(dynamic_cast<const collab::SimpleGraph::VertexAddOperation &>(op));
    }
    break;
    case static_cast<int>(collab::SimpleGraph::VERTEX_REMOVE):
    {
        applyOperation(dynamic_cast<const collab::SimpleGraph::VertexRemoveOperation &>(op));
    }
    break;
    case static_cast<int>(collab::SimpleGraph::EDGE_ADD):
    {
        applyOperation(dynamic_cast<const collab::SimpleGraph::EdgeAddOperation &>(op));
    }
    break;
    case static_cast<int>(collab::SimpleGraph::OPERATION_VERTEX_ADD ):
    {
        applyOperation(dynamic_cast<const collab::SimpleGraph::EdgeRemoveOperation &>(op));
    }
    break;
    case static_cast<int>(collab::SimpleGraph::ATTRIBUTE_ADD):
    {
        applyOperation(dynamic_cast<const collab::SimpleGraph::AttributeAddOperation &>(op));
    }
    break;
    case static_cast<int>(collab::SimpleGraph::ATTRIBUTE_REMOVE):
    {
        applyOperation(dynamic_cast<const collab::SimpleGraph::AttributeRemoveOperation &>(op));
    }
    break;
    case static_cast<int>(collab::SimpleGraph::ATTRIBUTE_SET):
    {
        applyOperation(dynamic_cast<const collab::SimpleGraph::AttributeSetOperation &>(op));
    }
    break;
    default:{
        std::cout << "Error : Unknown operation received " << std::endl;
    }

    }*/
}

/*
void SimpleGraphOperationObserver::applyOperation(const collab::SimpleGraph::AttributeAddOperation op)
{
    std::cout << "Attribute " << op.attributeName() << " added to vertex " << op.vertexID() << " with value " << op.attributeValue() << std::endl;
}
void SimpleGraphOperationObserver::applyOperation(const collab::SimpleGraph::AttributeRemoveOperation op)
{
    std::cout << "Attribute " << op.attributeName() << " removed from vertex " << op.vertexID() << std::endl;
}
void SimpleGraphOperationObserver::applyOperation(const collab::SimpleGraph::AttributeSetOperation op)
{
    std::cout << "Attribute " << op.attributeName() << " from vertex " << op.vertexID() << " set with value " << op.newValue() << std::endl;
}
void SimpleGraphOperationObserver::applyOperation(const collab::SimpleGraph::EdgeAddOperation op)
{
    std::cout << "Edge added bewteen " << op.fromID() << " and " << op.toID() << std::endl;
}
void SimpleGraphOperationObserver::applyOperation(const collab::SimpleGraph::EdgeRemoveOperation op)
{
    std::cout << "Edge removed bewteen " << op.fromID() << " and " << op.toID() << std::endl;
}
void SimpleGraphOperationObserver::applyOperation(const collab::SimpleGraph::VertexAddOperation op)
{
    std::cout << "Vertex " << op.vertexID() << " added" << std::endl;
}
void SimpleGraphOperationObserver::applyOperation(const collab::SimpleGraph::VertexRemoveOperation op)
{
    std::cout << "Vertex " << op.vertexID() << " removed" << std::endl;
}*/