#pragma once

#include <iostream>

#include "Command.h"
#include "Editor.h"


class ConnectCommand : public Command {
    private:
        Editor* editor;

    public:
        ConnectCommand(const CommandInfo& info) : Command(info) {}
        int exec(utils::config config, const std::vector<std::string> &arguments) override;
};
