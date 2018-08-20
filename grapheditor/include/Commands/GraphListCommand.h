#pragma once

#include "Command.h"


class GraphListCommand : public Command {
    public:
        GraphListCommand(const CommandInfo& info) : Command(info) {}
        int exec(utils::config config, const std::vector<std::string> &arguments) override;
};
