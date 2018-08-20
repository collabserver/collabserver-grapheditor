#pragma once

#include <cassert>
#include <string>
#include <vector>
#include <iostream>

#include "utils.h"


/**
 * @brief
 * Abstract Command class to help format command specific class 
 */
class Command {
    private:
        std::string _name;
        std::string _help;
        std::string _resume;

    public:
        Command(const char* name, const char* help, const char* resume) {
            assert(name != nullptr && help != nullptr && resume != nullptr);
            assert(name != "" && help != "");
            _name   = name;
            _help   = help;
            _resume = resume;
        }

    public:
        virtual int exec(utils::config config, const std::vector<std::string> &arguments) = 0;

    public:
        const std::string& getName() const { return _name; }
        const std::string& getHelp() const { return _help; }
        const std::string& getResume() const { return _resume; }
};


