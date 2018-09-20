#pragma once

#include <vector>
#include <string>

#include <collabdata/custom/SimpleGraph.h>


/**
 * SimpleGraph Operation Handler for debug purpose.
 * This print out each operation handled on stdout.
 */
class SGraphOpHandlerDebug : public collab::SimpleGraph::OpHandler {
    private:
        typedef collab::SimpleGraph SGraph;
    public:
        void handleOperation(const SGraph::VertexAddOperation& op) override;
        void handleOperation(const SGraph::VertexRemoveOperation& op) override;
        void handleOperation(const SGraph::EdgeAddOperation& op) override;
        void handleOperation(const SGraph::EdgeRemoveOperation& op) override;
        void handleOperation(const SGraph::AttributeAddOperation& op) override;
        void handleOperation(const SGraph::AttributeRemoveOperation& op) override;
        void handleOperation(const SGraph::AttributeSetOperation& op) override;
};

/**
 * Observer for SimpleGraph operation and uses debug handler.
 */
class SGraphOpObserverDebug : public collab::OperationObserver {
    private:
        SGraphOpHandlerDebug _opHandler;
    public:
        SGraphOpObserverDebug() = default;
        void onOperation(const collab::Operation &op) override {
            op.accept(_opHandler);
        }
};


namespace utils {


/**
 * @brief
 * Collect words in the range [@c first, @c last).
 *
 * @details
 * Words are separated by one or more unquoted spaces.
 * Spaces between double quotes are not separators.
 * They are instead part of a word.
 *
 * @warning
 * @c first and @c last must form a valid range.
 * Behavior is undefined if this is not the case.
 *
 * @warning
 * Quotes are assumed to be paired.
 * A warning is issued if the range contains an odd number of quotes.
 *
 * @see
 * www.physicsforums.com/threads/c-function-to-split-a-string-by-whitespace-ignoring-any-whitespace-in-quotes.778920/
 *
 * @return
 * Collected words as a vector of strings.
 */
std::vector<std::string> split_no_quotes(
    const std::string::const_iterator first, //!< Start of range.
    const std::string::const_iterator last);  //!< End of range.


} // namespace utils


