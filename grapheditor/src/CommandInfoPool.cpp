#include "CommandInfoPool.h"

#include <cassert>
#include <string> // std::getline
#include <fstream>
#include <sstream>


int CommandInfoPool::loadFromFile(const char* path) {
    std::fstream cmdFile;

    try {
        cmdFile.open(path, std::ios::in);

        _pool.clear();

        for(int k = 0; k < _headerSize; ++k) {
            cmdFile.ignore(65535, '\n');
        }

        std::string referenceID;
        std::string name;
        std::string shortname;
        std::string usage;
        std::string description;

        while(std::getline(cmdFile, referenceID, _delim)) {
            std::getline(cmdFile, name,        _delim);
            std::getline(cmdFile, shortname,   _delim);
            std::getline(cmdFile, usage,       _delim);
            std::getline(cmdFile, description, '\n');

            assert(!name.empty() && !shortname.empty());
            assert(!usage.empty() && !description.empty());

            CommandInfo info = {name, shortname, usage, description};
            _pool.emplace(referenceID.c_str(), info);
        }

        cmdFile.close();
        return 1;
    }
    catch(...) {
        return -1;
    }
}

const CommandInfo& CommandInfoPool::get(const ReferenceID id) const {
    assert(_pool.count(id) == 1);
    return _pool.at(id);
}


