#pragma once

#include "Command.h"


class VertexEditCommand : public Command {
    public:
        VertexEditCommand();
        int exec(utils::config config, const std::vector<std::string> &arguments);
};
