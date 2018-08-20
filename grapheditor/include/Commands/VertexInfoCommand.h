#pragma once

#include "Command.h"


class VertexInfoCommand : public Command {
    public:
        VertexInfoCommand(const CommandInfo& info) : Command(info) {}
        int exec(utils::config config, const std::vector<std::string> &arguments) override;
};
