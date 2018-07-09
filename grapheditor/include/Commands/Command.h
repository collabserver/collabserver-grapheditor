/**
 * @brief Abstract Command class to help format command specific class 
 * 
 * @file command.h
 * @author (The Intern)
 * @date 2018-06-26
 */

#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <stdexcept>
#include <vector>
#include <iostream>
#include "utils.h"

class Command
{
  private:
    std::string name;
    std::string help;
    std::string resume;

  public:
    Command(std::string name, std::string help, std::string resume)
    {
        if (name != "" && help != "")
        {
            this->name = name;
            this->help = help;
            this->resume = resume;
        }
        else
        {
            throw new std::invalid_argument("Error : name, help and resume of the command must be set");
        }
    }

    std::string getName() { return this->name; }
    std::string getHelp() { return this->help; }
    std::string getResume() { return this->resume; }
    bool cmp(Command *cmd) { return this->name == cmd->getName(); }

    virtual int exec(utils::config config, std::vector<std::string> arguments)=0;
};

#endif