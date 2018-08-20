#pragma once

#include "Command.h"


class GraphOpenCommand : public Command {
    public:
        GraphOpenCommand();
        int exec(utils::config config, const std::vector<std::string> &arguments);
};
