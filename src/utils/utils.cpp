#include "utils/utils.h"

#include <ctime>
#include <iostream>

std::string generateNewUUID() {
    std::srand(std::time(nullptr));
    const std::string CHARS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string uuid = std::string(36, ' ');
    int rnd = 0;

    uuid[8] = '-';
    uuid[13] = '-';
    uuid[18] = '-';
    uuid[23] = '-';

    uuid[14] = '4';

    for (int i = 0; i < 36; i++) {
        if (i != 8 && i != 13 && i != 18 && i != 14 && i != 23) {
            if (rnd <= 0x02) {
                rnd = (0x2000000 + (std::rand() * 0x1000000)) | 0;
            }
            rnd >>= 4;
            uuid[i] = CHARS[(i == 19) ? ((rnd & 0xf) & 0x3) | 0x8 : rnd & 0xf];
        }
    }
    return uuid;
}

// See
// www.physicsforums.com/threads/c-function-to-split-a-string-by-whitespace-ignoring-any-whitespace-in-quotes.778920/
std::vector<std::string> split_no_quotes(const std::string::const_iterator first,
                                         const std::string::const_iterator last) {
    std::vector<std::string> result;
    bool in_quotes = false;
    std::string curr_word;  // Walk over the range, collecting words along the way.
    for (std::string::const_iterator it = first; it < last; ++it) {
        char c = *it;  // Non-separator character: Add it to the current word, and toggle flag if needed.
        if (in_quotes || (c != ' ')) {
            if (c != '"') curr_word.push_back(c);
            in_quotes = (c == '"') != in_quotes;  // OK. I'll admit this is a bit hackish.
        }
        // First unquoted space after a word: Add word to result and reset word.
        else if (!curr_word.empty()) {
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
        /*
        std::cerr << "Warning: In split_no_quotes():\n"
                  << "Input string contains non-terminated quote.\n"
                  << "Input string: " << std::string(first, last) << std::endl;
        */
    }
    return result;
}
