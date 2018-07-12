/**
 * @brief 
 * 
 * @file SimpleGraphOperationObserver.h
 * @author (The Intern)
 * @date 2018-07-10
 */

#include "collabdata/custom/SimpleGraph.h"

class SimpleGraphOperationObserver : public collab::OperationObserver
{
  public:
    SimpleGraphOperationObserver();
    void onOperation(const collab::Operation &op) override;

  private:
    void applyOperation(const collab::SimpleGraph::AttributeAddOperation op);
    void applyOperation(const collab::SimpleGraph::AttributeRemoveOperation op);
    void applyOperation(const collab::SimpleGraph::AttributeSetOperation op);
    void applyOperation(const collab::SimpleGraph::EdgeAddOperation op);
    void applyOperation(const collab::SimpleGraph::EdgeRemoveOperation op);
    void applyOperation(const collab::SimpleGraph::VertexAddOperation op);
    void applyOperation(const collab::SimpleGraph::VertexRemoveOperation op);
};