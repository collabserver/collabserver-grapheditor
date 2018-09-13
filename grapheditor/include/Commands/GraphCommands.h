#pragma once

#include "Command.h"
#include "CommandInfo.h"


class GraphShowCommand : public Command {
    public:
        GraphShowCommand(const CommandInfo& info) : Command(info) {}
        int exec(const std::vector<std::string>& args) override;
};

class GraphInfoCommand : public Command {
    public:
        GraphInfoCommand(const CommandInfo& info) : Command(info) {}
        int exec(const std::vector<std::string>& args) override;
};


