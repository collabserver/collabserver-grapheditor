#pragma once

#include "Command.h"


class VertexInfoCommand : public Command {
    public:
        VertexInfoCommand();
        int exec(utils::config config, const std::vector<std::string> &arguments);
};
