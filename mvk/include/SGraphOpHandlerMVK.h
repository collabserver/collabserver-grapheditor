#pragma once

#include <collabdata/custom/SimpleGraph.h>

#include "SGraphMVKMapper.h"


/**
 * \brief
 * Handle operation from SimpleGraph to be sent on MVK database.
 *
 * Any operation handled are sent to the MVK.
 * If an operation is not valid, operation is reverted and applied
 * to the simple graph.
 */
class SGraphOpHandlerMVK : public collab::SimpleGraph::OpHandler {
    private:
        typedef collab::SimpleGraph SGraph;
        SGraphMVKMapper*        _mapperMVK;
        collab::SimpleGraph*    _graph;

    public:

        /**
         * SGraphOpHandlerMVK.
         *
         * \param mapper MVK mapper used to save changes.
         * \param graph Pointer to graph, this is ONLY used to revert operation.
         */
        SGraphOpHandlerMVK(SGraphMVKMapper* mapper, collab::SimpleGraph* graph);

    // ---------------------------------------------------------------------
    // Override
    // ---------------------------------------------------------------------

    public:
        void handleOperation(const SGraph::VertexAddOperation& op) override;
        void handleOperation(const SGraph::VertexRemoveOperation& op) override;
        void handleOperation(const SGraph::EdgeAddOperation& op) override;
        void handleOperation(const SGraph::EdgeRemoveOperation& op) override;
        void handleOperation(const SGraph::AttributeAddOperation& op) override;
        void handleOperation(const SGraph::AttributeRemoveOperation& op) override;
        void handleOperation(const SGraph::AttributeSetOperation& op) override;
};


