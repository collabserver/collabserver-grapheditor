#pragma once

#include <vector>
#include <string>

/**
 * \brief basic uuidGenerator for Modelverse identification.
 *
 * Source code from internet resource. (See link)
 *
 * @see https://gist.github.com/fernandomv3/46a6d7656f50ee8d39dc#file-uuid-hpp
 * @return the uuid generated
 */
std::string generateNewUUID();

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


