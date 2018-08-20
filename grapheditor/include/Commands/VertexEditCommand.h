#pragma once

#include "Command.h"


class VertexEditCommand : public Command {
    public:
        VertexEditCommand(const CommandInfo& info) : Command(info) {}
        int exec(utils::config config, const std::vector<std::string> &arguments) override;
};
