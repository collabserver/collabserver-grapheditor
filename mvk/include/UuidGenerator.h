#pragma once

#include <ctime>
#include <iostream>


class UuidGenerator {
    public:

        /**
         * \brief basic uuidGenerator for Modelverse identification.
         *
         * Source code from internet resource. (See link)
         *
         * @see https://gist.github.com/fernandomv3/46a6d7656f50ee8d39dc#file-uuid-hpp
         * @return the uuid generated
         */
        static std::string basicGenerator();
};


