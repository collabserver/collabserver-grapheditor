#pragma once

#include "Command.h"


class AttributeRemove : public Command {
    public:
        AttributeRemove();
        int exec(utils::config config, const std::vector<std::string> &arguments);
};
