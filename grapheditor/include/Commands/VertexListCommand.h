#pragma once

#include "Command.h"


class VertexListCommand : public Command {
    public:
        VertexListCommand();
        int exec(utils::config config, const std::vector<std::string> &arguments);
};
