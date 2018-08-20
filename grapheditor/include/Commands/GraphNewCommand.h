#pragma once

#include "Command.h"


class GraphNewCommand : public Command {
    public:
        GraphNewCommand();
        int exec(utils::config config, const std::vector<std::string> &arguments);
};
