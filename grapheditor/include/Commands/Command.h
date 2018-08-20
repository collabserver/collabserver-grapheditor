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
        std::string name;
        std::string help;
        std::string resume;

    public:
        Command(std::string name, std::string help, std::string resume) {
            assert(name != "" && help != "");
            this->name = name;
            this->help = help;
            this->resume = resume;
        }

    public:
        std::string getName() { return this->name; }
        std::string getHelp() { return this->help; }
        std::string getResume() { return this->resume; }

        bool cmp(Command *cmd) { return this->name == cmd->getName(); }

    public:
        virtual int exec(utils::config config, const std::vector<std::string> &arguments)=0;
};


