#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <tuple>

#include "Command.h"
#include "CommandInfo.h"


class HelpCommand : public Command {
    private:
        const std::map<std::string, Command*>* _commandList;

    public:
        HelpCommand(const CommandInfo& info,
                    const std::map<std::string, Command*> *commandList);
        int exec(utils::config config, const std::vector<std::string> &arguments);
};
