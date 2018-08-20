#pragma once

#include "Command.h"


class GraphDisplayCommand : public Command {
    public:
        GraphDisplayCommand();
        int exec(utils::config config, const std::vector<std::string> &arguments);
};
