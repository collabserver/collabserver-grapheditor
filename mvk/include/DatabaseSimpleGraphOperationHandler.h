/**
 * @brief Abstract class handling operation for any database for the
 *      SimpleGraph Metamodel
 */

#ifndef COLLAB_POC_DATABASESIMPLEGRAPHOPERATION_H
#define COLLAB_POC_DATABASESIMPLEGRAPHOPERATION_H

#include <collabdata/custom/SimpleGraph.h>
#include "DatabaseOperationHandler.h"

class DatabaseSimpleGraphOperationHandler : public DatabaseOperationHandler {
protected:
    /**
     * @brief the data on which we work
     */
    collab::SimpleGraph* graph;

public:
    /**
     * @brief Add a vertex in the database
     * @param operation the operation with everything we need to apply it
     */
    virtual void
    applyOperation(const collab::SimpleGraph::VertexAddOperation operation) = 0;

    /**
     * @brief Remove a vertex in the database
     * @param operation the operation with everything we need to apply it
     */
    virtual void applyOperation(
            const collab::SimpleGraph::VertexRemoveOperation operation) = 0;

    /**
     * @brief Add an edge in the database
     * @param operation the operation with everything we need to apply it
     */
    virtual void
    applyOperation(const collab::SimpleGraph::EdgeAddOperation operation) = 0;

    /**
     * @brief Remove an edge in the database
     * @param operation the operation with everything we need to apply it
     */
    virtual void applyOperation(
            const collab::SimpleGraph::EdgeRemoveOperation operation) = 0;

    /**
     * @brief Add an attribute in a vertex in the database
     * @param operation the operation with everything we need to apply it
     */
    virtual void applyOperation(
            const collab::SimpleGraph::AttributeAddOperation operation) = 0;

    /**
     * @brief Remove an attribute in a vertex in the database
     * @param operation the operation with everything we need to apply it
     */
    virtual void applyOperation(
            const collab::SimpleGraph::AttributeRemoveOperation operation) = 0;

    /**
     * @brief Modify an attribute in a vertex in the database
     * @param operation the operation with everything we need to apply it
     */
    virtual void applyOperation(
            const collab::SimpleGraph::AttributeSetOperation operation) = 0;
};


#endif //COLLAB_POC_DATABASESIMPLEGRAPHOPERATION_H
