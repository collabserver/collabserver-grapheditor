#include "utils/utils.h"

#include <iostream>


// -----------------------------------------------------------------------------
// SGraphOpHandlerDebug
// -----------------------------------------------------------------------------

void SGraphOpHandlerDebug::handleOperation(const SGraph::VertexAddOperation &op) {
    std::cout << "Vertex added (" << op.vertexID() << ")";
    std::cout << std::endl;
}

void SGraphOpHandlerDebug::handleOperation(const SGraph::VertexRemoveOperation &op) {
    std::cout << "Vertex removed (" << op.vertexID() << ")";
    std::cout << std::endl;
}

void SGraphOpHandlerDebug::handleOperation(const SGraph::EdgeAddOperation &op) {
    std::cout << "Edge added (" << op.fromID() << " -> " << op.toID() << ")";
    std::cout << std::endl;
}

void SGraphOpHandlerDebug::handleOperation(const SGraph::EdgeRemoveOperation &op) {
    std::cout << "Edge removed (" << op.fromID() << " -> " << op.toID() << ")";
    std::cout << std::endl;
}

void SGraphOpHandlerDebug::handleOperation(const SGraph::AttributeAddOperation &op) {
    std::cout << "Attribute added to vertex (" << op.vertexID() << ": "
              << op.attributeName() << " = " << op.attributeValue() << ")";
    std::cout << std::endl;
}

void SGraphOpHandlerDebug::handleOperation(const SGraph::AttributeRemoveOperation &op) {
    std::cout << "Attribute removed from vertex (" << op.vertexID() << ": "
              << op.attributeName() << ")";
    std::cout << std::endl;
}

void SGraphOpHandlerDebug::handleOperation(const SGraph::AttributeSetOperation &op) {
    std::cout << "Attribute set in vertex (" << op.vertexID() << ": "
              << op.attributeName() << " = " << op.newValue() << ")";
    std::cout << std::endl;
}

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
        /*
        std::cerr << "Warning: In split_no_quotes():\n"
                  << "Input string contains non-terminated quote.\n"
                  << "Input string: " << std::string(first, last) << std::endl;
        */
    }
    return result;
}


