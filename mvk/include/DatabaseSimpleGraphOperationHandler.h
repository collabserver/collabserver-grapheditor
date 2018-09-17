#pragma once

#include <collabdata/custom/SimpleGraph.h>
#include "DatabaseOperationHandler.h"

/**
 * \brief Abs class to handle operations from any Database (SimpleGraph data).
 *
 * Abstract class handling operation for any database for the
 * SimpleGraph Metamodel.
 */
class DatabaseSimpleGraphOperationHandler : public DatabaseOperationHandler {
    protected:
        collab::SimpleGraph* graph;


    public:

        virtual void applyOperation(
                const collab::SimpleGraph::VertexAddOperation operation) = 0;

        virtual void applyOperation(
                const collab::SimpleGraph::VertexRemoveOperation operation) = 0;

        virtual void applyOperation(
                const collab::SimpleGraph::EdgeAddOperation operation) = 0;

        virtual void applyOperation(
                const collab::SimpleGraph::EdgeRemoveOperation operation) = 0;

        virtual void applyOperation(
                const collab::SimpleGraph::AttributeAddOperation operation) = 0;

        virtual void applyOperation(
                const collab::SimpleGraph::AttributeRemoveOperation operation) = 0;

        virtual void applyOperation(
                const collab::SimpleGraph::AttributeSetOperation operation) = 0;
};


