#pragma once

#include <iostream>

#include "Command.h"
#include "Editor.h"


class ConnectCommand : public Command {
    private:
        Editor* editor;

    public:
        ConnectCommand();
        int exec(utils::config config, const std::vector<std::string> &arguments);
};
