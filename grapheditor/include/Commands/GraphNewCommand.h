#pragma once

#include "Command.h"


class GraphNewCommand : public Command {
    public:
        GraphNewCommand(const CommandInfo& info) : Command(info) {}
        int exec(utils::config config, const std::vector<std::string> &arguments) override;
};
