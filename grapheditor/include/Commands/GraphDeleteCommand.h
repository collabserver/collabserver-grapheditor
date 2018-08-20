#pragma once

#include "Command.h"


class GraphDeleteCommand : public Command {
    public:
        GraphDeleteCommand();
        int exec(utils::config config, const std::vector<std::string> &arguments);
};
