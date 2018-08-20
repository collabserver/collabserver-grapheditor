#pragma once

#include "Command.h"


class EdgeRemoveCommand : public Command {
    public:
        EdgeRemoveCommand(const CommandInfo& info) : Command(info) {}
        int exec(utils::config config, const std::vector<std::string> &arguments) override;
};
