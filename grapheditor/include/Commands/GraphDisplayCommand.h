#pragma once

#include "Command.h"


class GraphDisplayCommand : public Command {
    public:
        GraphDisplayCommand(const CommandInfo& info) : Command(info) {}
        int exec(utils::config config, const std::vector<std::string> &arguments) override;
};
