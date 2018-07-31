/**
 * @brief class handling all the operation between the MVK and a simple graph
 *      instance
 */

#ifndef COLLAB_POC_MVKSIMPLEGRAPHOPERATION_H
#define COLLAB_POC_MVKSIMPLEGRAPHOPERATION_H

#include "DatabaseSimpleGraphOperationHandler.h"
#include "MVKWrapper.h"
#include "cJSON.h"

class MVKSimpleGraphOperationHandler
        : public DatabaseSimpleGraphOperationHandler {

private:
    /**
     * @brief the model on which we work
     */
    std::string workingModel = "models/BaseSimpleGraph";
    /**
     * @brief the metamodel used
     */
    std::string metaModel = "formalisms/SimpleGraph";
    /**
     * @brief the connection with the database
     */
    MVKWrapper *mvkConnector;

    /**
     * @brief basic action done by every constructor
     */
    void baseConstructor();

    /**
     * @brief generate the SimpleGraph metamodel
     */
    void generateMetamodel();

    /**
     * @brief get all the model in a cJson pointer
     * @return a cJson pointer with all the model in it
     */
    cJSON * getJSON();

    /**
     * @brief get the value of the attribute in parameter
     * @param attributeId the id of the value's attribute
     * @return the value of the attribute
     */
    std::string getAttributeValue(std::string attributeId);

public:

    MVKSimpleGraphOperationHandler();

    MVKSimpleGraphOperationHandler(collab::SimpleGraph *graph);

    MVKSimpleGraphOperationHandler(collab::SimpleGraph *graph,
                                   const std::string savePath);

    ~MVKSimpleGraphOperationHandler();

    void
    applyOperation(
            const collab::SimpleGraph::VertexAddOperation operation) override;

    void applyOperation(
            const collab::SimpleGraph::VertexRemoveOperation operation) override;

    void
    applyOperation(
            const collab::SimpleGraph::EdgeAddOperation operation) override;

    void
    applyOperation(
            const collab::SimpleGraph::EdgeRemoveOperation operation) override;

    void applyOperation(
            const collab::SimpleGraph::AttributeAddOperation operation) override;

    void applyOperation(
            const collab::SimpleGraph::AttributeRemoveOperation operation) override;

    void applyOperation(
            const collab::SimpleGraph::AttributeSetOperation operation) override;

    /**
     * @brief check if the model is correct
     * @return true if the model is correct
     */
    bool isModelCorrect();

    /**
     * @brief send all the content of the database model to the graph
     * @post the database model and the graph should be in same state
     */
    void loadModel();
};


#endif //COLLAB_POC_MVKSIMPLEGRAPHOPERATION_H
