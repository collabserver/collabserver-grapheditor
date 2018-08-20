#include "utils.h"


utils::config::config() {
    this->loaded = false;
};

bool utils::config::isLoaded() {
    return this->loaded;
}

void utils::config::flipLoaded() {
    this->loaded = !this->loaded;
}

void utils::config::setDataStructure(collab::SimpleGraph* dataStructure) {
    this->dataStructure = dataStructure;
}

collab::SimpleGraph* utils::config::getDataStructure() {
    return this->dataStructure;
}

std::vector<std::string> utils::split_no_quotes(
    const std::string::const_iterator first,
    const std::string::const_iterator last)
{
    std::vector<std::string> result;
    bool in_quotes = false;
    std::string curr_word; // Walk over the range, collecting words along the way.
    for (std::string::const_iterator it = first; it < last; ++it) {
        char c = *it; // Non-separator character: Add it to the current word, and toggle flag if needed.
        if (in_quotes || (c != ' '))
        {
            if (c != '"')
                curr_word.push_back(c);
            in_quotes = (c == '"') != in_quotes; // OK. I'll admit this is a bit hackish.
        }
        // First unquoted space after a word: Add word to result and reset word.
        else if (!curr_word.empty())
        {
            result.push_back(curr_word);
            curr_word.clear();
        }
        // No else: This represents consecutive unquotes spaces. There's nothing to do.
    }

    // The last word has not been added to the result. Do so.
    if (!curr_word.empty()) {
        result.push_back(curr_word);
    }

    // Check for and report a violation of the paired quotes assumption.
    if (in_quotes) {
        std::cerr << "Warning: In split_no_quotes():\n"
                  << "Input string contains non-terminated quote.\n"
                  << "Input string: " << std::string(first, last) << std::endl;
    }
    return result;
}
