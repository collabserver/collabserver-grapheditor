#pragma once

#include <iostream>

#include "Command.h"


class GraphCloseCommand : public Command {
    private:

    public:
    GraphCloseCommand();
    int exec(utils::config config, const std::vector<std::string> &arguments);

};
