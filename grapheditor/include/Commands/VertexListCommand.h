#pragma once

#include "Command.h"


class VertexListCommand : public Command {
    public:
        VertexListCommand(const CommandInfo& info) : Command(info) {}
        int exec(utils::config config, const std::vector<std::string> &arguments) override;
};
