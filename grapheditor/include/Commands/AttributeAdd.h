#pragma once

#include "Command.h"


class AttributeAdd : public Command {
    public:
        AttributeAdd();
        int exec(utils::config config, const std::vector<std::string> &arguments);
};
