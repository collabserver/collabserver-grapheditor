#pragma once

#include "Command.h"


class VertexRemoveCommand : public Command {
    public:
        VertexRemoveCommand(const CommandInfo& info) : Command(info) {}
        int exec(utils::config config, const std::vector<std::string> &arguments) override;
};
