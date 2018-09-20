#pragma once

#include <collabdata/custom/SimpleGraph.h>


/**
 * SimpleGraph Operation Handler for debug purpose.
 * This print out each operation handled on stdout.
 */
class SGraphOpHandlerDebug : public collab::SimpleGraph::OpHandler {
    public:
        typedef collab::SimpleGraph SGraph;

        void handleOperation(const SGraph::VertexAddOperation& op) override;
        void handleOperation(const SGraph::VertexRemoveOperation& op) override;
        void handleOperation(const SGraph::EdgeAddOperation& op) override;
        void handleOperation(const SGraph::EdgeRemoveOperation& op) override;
        void handleOperation(const SGraph::AttributeAddOperation& op) override;
        void handleOperation(const SGraph::AttributeRemoveOperation& op) override;
        void handleOperation(const SGraph::AttributeSetOperation& op) override;
};


