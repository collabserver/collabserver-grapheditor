#pragma once

#include "simplegraph/SimpleGraph.h"

/**
 * SimpleGraph Operation Handler for debug purpose.
 * This print out each operation handled on stdout.
 */
class SimpleGraphDebugOpHandler : public SimpleGraph::OpHandler {
   public:
    void handleOperation(const SimpleGraph::VertexAddOperation& op) override;
    void handleOperation(const SimpleGraph::VertexRemoveOperation& op) override;
    void handleOperation(const SimpleGraph::EdgeAddOperation& op) override;
    void handleOperation(const SimpleGraph::EdgeRemoveOperation& op) override;
    void handleOperation(const SimpleGraph::AttributeAddOperation& op) override;
    void handleOperation(const SimpleGraph::AttributeRemoveOperation& op) override;
    void handleOperation(const SimpleGraph::AttributeSetOperation& op) override;
};
