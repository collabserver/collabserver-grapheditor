#pragma once

#include "Command.h"
#include "CommandInfo.h"


class EdgeAddCommand : public Command {
    public:
        EdgeAddCommand(const CommandInfo& info) : Command(info) {}
        int exec(const std::vector<std::string> &args) override;
};

class EdgeRemoveCommand : public Command {
    public:
        EdgeRemoveCommand(const CommandInfo& info) : Command(info) {}
        int exec(const std::vector<std::string> &args) override;
};
