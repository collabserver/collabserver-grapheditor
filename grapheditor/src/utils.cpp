#include "utils.h"

#include <iostream>

namespace utils {


// See www.physicsforums.com/threads/c-function-to-split-a-string-by-whitespace-ignoring-any-whitespace-in-quotes.778920/
std::vector<std::string> split_no_quotes(
    const std::string::const_iterator first,
    const std::string::const_iterator last)
{
    std::vector<std::string> result;
    bool in_quotes = false;
    std::string curr_word; // Walk over the range, collecting words along the way.
    for(std::string::const_iterator it = first; it < last; ++it) {
        char c = *it; // Non-separator character: Add it to the current word, and toggle flag if needed.
        if (in_quotes || (c != ' ')) {
            if (c != '"')
                curr_word.push_back(c);
            in_quotes = (c == '"') != in_quotes; // OK. I'll admit this is a bit hackish.
        }
        // First unquoted space after a word: Add word to result and reset word.
        else if (!curr_word.empty()) {
            result.push_back(curr_word);
            curr_word.clear();
        }
        // No else: This represents consecutive unquotes spaces. There's nothing to do.
    }

    // The last word has not been added to the result. Do so.
    if(!curr_word.empty()) {
        result.push_back(curr_word);
    }

    // Check for and report a violation of the paired quotes assumption.
    if(in_quotes) {
        std::cerr << "Warning: In split_no_quotes():\n"
                  << "Input string contains non-terminated quote.\n"
                  << "Input string: " << std::string(first, last) << std::endl;
    }
    return result;
}


} // End namespace


// -----------------------------------------------------------------------------
// SimpleGraphOperationHandler
// -----------------------------------------------------------------------------

void SimpleGraphOperationHandler::handleOperation(const collab::SimpleGraph::VertexAddOperation &op){
    std::cout << "Vertex \"" << op.vertexID() << "\" added" << std::endl;
}
void SimpleGraphOperationHandler::handleOperation(const collab::SimpleGraph::VertexRemoveOperation &op){
    std::cout << "Vertex \"" << op.vertexID() << "\" removed" << std::endl;
}
void SimpleGraphOperationHandler::handleOperation(const collab::SimpleGraph::EdgeAddOperation &op){
    std::cout << "Edge added bewteen \"" << op.fromID() << "\" and \"" << op.toID() << "\"" << std::endl;
}
void SimpleGraphOperationHandler::handleOperation(const collab::SimpleGraph::EdgeRemoveOperation &op){
    std::cout << "Edge removed bewteen \"" << op.fromID() << "\" and \"" << op.toID() << "\"" << std::endl;
}
void SimpleGraphOperationHandler::handleOperation(const collab::SimpleGraph::AttributeAddOperation &op){
    std::cout << "Attribute \"" << op.attributeName() << "\" added to vertex \"" << op.vertexID() << "\" with value \"" << op.attributeValue() << "\"" << std::endl;
}
void SimpleGraphOperationHandler::handleOperation(const collab::SimpleGraph::AttributeRemoveOperation &op){
    std::cout << "Attribute \"" << op.attributeName() << "\" removed from vertex \"" << op.vertexID() << "\"" << std::endl;
}
void SimpleGraphOperationHandler::handleOperation(const collab::SimpleGraph::AttributeSetOperation &op){
    std::cout << "Attribute \"" << op.attributeName() << "\" from vertex \"" << op.vertexID() << "\" set with value \"" << op.newValue() << "\"" << std::endl;
}


// -----------------------------------------------------------------------------
// SimpleGraphOperationObserver
// -----------------------------------------------------------------------------

SimpleGraphOperationObserver::SimpleGraphOperationObserver(SimpleGraphOperationHandler opHandler) {
    this->opHandler = opHandler;
}

void SimpleGraphOperationObserver::onOperation(const collab::Operation &op) {
   op.accept(this->opHandler);
}


