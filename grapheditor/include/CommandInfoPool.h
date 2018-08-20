#pragma once

#include <unordered_map>

#include "CommandInfo.h"


class CommandInfoPool {
    public:
        typedef const char* ReferenceID;
    private:
        std::unordered_map<const char*, CommandInfo> _pool;
        const char  _delim = ',';           // csv delim
        const int   _headerSize = 1;        // Nb of row for header

    public:
        int loadFromFile(const char* path);
        const CommandInfo& getCommandInfo(ReferenceID id) const;
};
