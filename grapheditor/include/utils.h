/**
 * @brief The utils namepsace contain "tool" classes used all around the project. 
 * 
 * @file utils.h
 * @author (The Intern)
 * @date 2018-07-04
 */
#ifndef UTILS_H
#define UTILS_H

#include <exception>
#include <vector>
#include <string>
#include <tuple>
#include <iostream>

namespace utils
{

class config
{
  private:
    std::vector<std::tuple<int, int>> dataStructure;
    bool loaded;

  public:
    config();
    bool isLoaded();
    void flipLoaded();
    void setDataStructure(std::vector<std::tuple<int, int>> dataStructure);
    std::vector<std::tuple<int, int>> getDataStructure();

};


//Reference https: //www.physicsforums.com/threads/c-function-to-split-a-string-by-whitespace-ignoring-any-whitespace-in-quotes.778920/
/** * @brief Collect words in the range [@c first, @c last). 
 *  
 * @details Words are separated by one or more unquoted spaces. 
 * Spaces between double quotes are not separators. 
 * They are instead part of a word. 
 *
 * @return Collected words as a vector of strings. 
 *
 * @warning @c first and @c last must form a valid range. 
 * Behavior is undefined if this is not the case. 
 * 
 * @warning Quotes are assumed to be paired. 
 * A warning is issued if the range contains an odd number of quotes. 
 */
std::vector<std::string> split_no_quotes(
    const std::string::const_iterator first, //!< Start of range.
    const std::string::const_iterator last);  //!< End of range.


} // namespace utils

#endif