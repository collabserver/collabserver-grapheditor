#pragma once

#include "Command.h"


class GraphListCommand : public Command {
    public:
        GraphListCommand();
        int exec(utils::config config, const std::vector<std::string> &arguments);
};
