#pragma once

#include "Command.h"


class VertexRemoveCommand : public Command {
    public:
        VertexRemoveCommand();
        int exec(utils::config config, const std::vector<std::string> &arguments);
};
