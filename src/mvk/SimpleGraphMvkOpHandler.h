#pragma once

#include <string>

#include "mvk/SimpleGraphMvkMapper.h"
#include "simplegraph/SimpleGraph.h"

/**
 * \brief
 * Handle operation from SimpleGraph to be sent on MVK database.
 *
 * Any operation handled are sent to the MVK.
 * If an operation is not valid, operation is reverted and applied
 * to the simple graph.
 */
class SimpleGraphMvkOpHandler : public SimpleGraph::OpHandler {
   private:
    const SimpleGraphMvkMapper* _mapperMVK;
    SimpleGraph* _graph;
    std::string _model;
    std::string _metamodel;

   public:
    /**
     * SimpleGraphMvkOpHandler.
     *
     * \param mapper MVK mapper used to save changes.
     * \param graph Pointer to graph, this is ONLY used to revert operation.
     */
    SimpleGraphMvkOpHandler(const SimpleGraphMvkMapper* mapper, SimpleGraph* graph, const std::string& model,
                            const std::string& metamodel);

    // ---------------------------------------------------------------------
    // Override
    // ---------------------------------------------------------------------

   public:
    void handleOperation(const SimpleGraph::VertexAddOperation& op) override;
    void handleOperation(const SimpleGraph::VertexRemoveOperation& op) override;
    void handleOperation(const SimpleGraph::EdgeAddOperation& op) override;
    void handleOperation(const SimpleGraph::EdgeRemoveOperation& op) override;
    void handleOperation(const SimpleGraph::AttributeAddOperation& op) override;
    void handleOperation(const SimpleGraph::AttributeRemoveOperation& op) override;
    void handleOperation(const SimpleGraph::AttributeSetOperation& op) override;
};
