#pragma once

#include "Command.h"


class VertexAddCommand : public Command {
    public:
        VertexAddCommand();
        int exec(utils::config config, const std::vector<std::string> &arguments);
};
