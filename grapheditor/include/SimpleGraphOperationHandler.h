/**
 * @brief 
 * 
 * @file SimpleGraphOperationHandler.h
 * @author (The Intern)
 * @date 2018-07-12
 */
#ifndef SIMPLEGRAPHOPERATIONHANDLER_H
#define SIMPLEGRAPHOPERATIONHANDLER_H
#include "collabdata/custom/SimpleGraph.h"

class SimpleGraphOperationHandler : public collab::SimpleGraph::OpHandler
{
  public:
    virtual void handleOperation(const collab::SimpleGraph::VertexAddOperation &op);
    virtual void handleOperation(const collab::SimpleGraph::VertexRemoveOperation &op);
    virtual void handleOperation(const collab::SimpleGraph::EdgeAddOperation &op);
    virtual void handleOperation(const collab::SimpleGraph::EdgeRemoveOperation &op);
    virtual void handleOperation(const collab::SimpleGraph::AttributeAddOperation &op);
    virtual void handleOperation(const collab::SimpleGraph::AttributeRemoveOperation &op);
    virtual void handleOperation(const collab::SimpleGraph::AttributeSetOperation &op);
};

#endif