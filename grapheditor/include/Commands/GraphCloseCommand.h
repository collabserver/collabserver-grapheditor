#pragma once

#include <iostream>

#include "Command.h"


class GraphCloseCommand : public Command {
    public:
        GraphCloseCommand(const CommandInfo& info) : Command(info) {}
        int exec(utils::config config, const std::vector<std::string> &arguments) override;

};
