#pragma once

#include "Command.h"


class GraphOpenCommand : public Command {
    public:
        GraphOpenCommand(const CommandInfo& info) : Command(info) {}
        int exec(utils::config config, const std::vector<std::string> &arguments) override;
};
