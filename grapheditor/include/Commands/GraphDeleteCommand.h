#pragma once

#include "Command.h"


class GraphDeleteCommand : public Command {
    public:
        GraphDeleteCommand(const CommandInfo& info) : Command(info) {}
        int exec(utils::config config, const std::vector<std::string> &arguments) override;
};
