#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <tuple>

#include "Command.h"
#include "CommandInfo.h"


class ConnectCommand : public Command {
    public:
        ConnectCommand(const CommandInfo& info) : Command(info) {}
        int exec(const std::vector<std::string> &args) override;
};

class QuitCommand : public Command {
    public:
        QuitCommand(const CommandInfo& info) : Command(info) {}
        int exec(const std::vector<std::string> &args) override;
};

class HelpCommand : public Command {
    public:
        HelpCommand(const CommandInfo& info) : Command(info) {}
        int exec(const std::vector<std::string> &args) override;
};


