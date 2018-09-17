#pragma once

#include "DatabaseSimpleGraphOperationHandler.h"
#include "MVKWrapper.h"
#include "cJSON.h"

/**
 * \brief Handle operation from SimpleGraph to be sent on MVK database.
 *
 */
class MVKSimpleGraphOperationHandler : public DatabaseSimpleGraphOperationHandler {
    private:

        /**
         * The model on which we work
         */
        std::string workingModel = "models/BaseSimpleGraph";
        /**
         * The metamodel used
         */
        std::string metaModel = "formalisms/SimpleGraph";
        /**
         * The connection with the database
         */
        MVKWrapper *mvkConnector;

        /**
         * Basic action done by every constructor
         */
        void baseConstructor();

        /**
         * Generate the SimpleGraph metamodel
         */
        void generateMetamodel();

        /**
         * Get all the model in a cJson pointer
         * \return a cJson pointer with all the model in it
         */
        cJSON * getJSON();

        /**
         * Get the value of the attribute in parameter
         * \param attributeId the id of the value's attribute
         * \return the value of the attribute
         */
        std::string getAttributeValue(std::string attributeId);

    public:

        MVKSimpleGraphOperationHandler();

        MVKSimpleGraphOperationHandler(collab::SimpleGraph *graph);

        MVKSimpleGraphOperationHandler(collab::SimpleGraph *graph,
                                       const std::string savePath);

        ~MVKSimpleGraphOperationHandler();

        void applyOperation(
                const collab::SimpleGraph::VertexAddOperation operation) override;

        void applyOperation(
                const collab::SimpleGraph::VertexRemoveOperation operation) override;

        void applyOperation(
                const collab::SimpleGraph::EdgeAddOperation operation) override;

        void applyOperation(
                const collab::SimpleGraph::EdgeRemoveOperation operation) override;

        void applyOperation(
                const collab::SimpleGraph::AttributeAddOperation operation) override;

        void applyOperation(
                const collab::SimpleGraph::AttributeRemoveOperation operation) override;

        void applyOperation(
                const collab::SimpleGraph::AttributeSetOperation operation) override;

        /**
         * Check if the model is correct
         * \return true if the model is correct
         */
        bool isModelCorrect();

        /**
         * send all the content of the database model to the graph
         * \post the database model and the graph should be in same state
         */
        void loadModel();
};


