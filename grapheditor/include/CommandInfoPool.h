#pragma once

#include <unordered_map>

#include "CommandInfo.h"


class CommandInfoPool {
    public:
        typedef std::string ReferenceID;

    private:
        std::unordered_map<ReferenceID, CommandInfo> _pool;
        const char  _delim = ',';           // csv delim
        const int   _headerSize = 1;        // Nb of row for header

    public:
        int loadFromFile(const char* path);
        const CommandInfo& get(const ReferenceID id) const;
};
