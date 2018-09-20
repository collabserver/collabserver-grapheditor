#pragma once

#include <string>

#include <collabdata/custom/SimpleGraph.h>

#include "SGraphMvkMapper.h"


/**
 * \brief
 * Handle operation from SimpleGraph to be sent on MVK database.
 *
 * Any operation handled are sent to the MVK.
 * If an operation is not valid, operation is reverted and applied
 * to the simple graph.
 */
class SGraphMvkOpHandler : public collab::SimpleGraph::OpHandler {
    private:
        typedef collab::SimpleGraph SGraph;

        const SGraphMvkMapper*  _mapperMVK;
        collab::SimpleGraph*    _graph;
        std::string             _model;
        std::string             _metamodel;

    public:

        /**
         * SGraphMvkOpHandler.
         *
         * \param mapper MVK mapper used to save changes.
         * \param graph Pointer to graph, this is ONLY used to revert operation.
         */
        SGraphMvkOpHandler(const SGraphMvkMapper* mapper,
                           collab::SimpleGraph* graph,
                           const std::string& model,
                           const std::string&  metamodel);

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


