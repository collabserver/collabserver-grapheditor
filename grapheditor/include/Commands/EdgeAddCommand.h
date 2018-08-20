#pragma once

#include "Command.h"


class EdgeAddCommand : public Command {
    public:
        EdgeAddCommand(const CommandInfo& info) : Command(info) {}
        int exec(utils::config config, const std::vector<std::string> &arguments) override;
};
