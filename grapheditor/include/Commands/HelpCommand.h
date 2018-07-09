/**
 * @brief 
 * 
 * @file HelpCommand.h
 * @author (The Intern)
 * @date 2018-06-26
 */
#include "Command.h"
#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <stdexcept>

class HelpCommand : public Command {
    private:
    const std::map<std::string, Command*> *commandList;

    public:
    HelpCommand(const std::map<std::string, Command*> *commandList);
    int exec(utils::config config, std::vector<std::string> parameters);

};