/**
 * @file UuidGenerator.h
 * @author Robin Donnay
 * @date 28/06/18
 * @brief Class for uuid generation
 */

#ifndef FIRSTWRAPPER_UUIDGENERATOR_H
#define FIRSTWRAPPER_UUIDGENERATOR_H

#include <iostream>
#include <ctime>

class UuidGenerator {
public:
    /**
     * \brief basic uuidGenerator for Modelverse identification, taken from :
     *      https://gist.github.com/fernandomv3/46a6d7656f50ee8d39dc#file-uuid-hpp
     * @return the uuid generated
     */
    static std::string basicGenerator();
};


#endif //FIRSTWRAPPER_UUIDGENERATOR_H
