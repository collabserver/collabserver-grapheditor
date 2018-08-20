#pragma once

#include "Command.h"


class VertexAddCommand : public Command {
    public:
        VertexAddCommand(const CommandInfo& info) : Command(info) {}
        int exec(utils::config config, const std::vector<std::string> &arguments) override;
};
