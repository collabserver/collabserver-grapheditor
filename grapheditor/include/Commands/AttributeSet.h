#pragma once

#include "Command.h"


class AttributeSet : public Command {
    public:
        AttributeSet();
        int exec(utils::config config, const std::vector<std::string> &arguments);
};
