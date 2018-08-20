#pragma once

#include "Command.h"


class EdgeAddCommand : public Command {
    public:
        EdgeAddCommand();
        int exec(utils::config config, const std::vector<std::string> &arguments);
};
