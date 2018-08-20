#pragma once

#include "Command.h"


class EdgeRemoveCommand : public Command {
    public:
        EdgeRemoveCommand();
        int exec(utils::config config, const std::vector<std::string> &arguments);
};
