#pragma once

#include "Command.h"


class AttributeRemove : public Command {
    public:
        AttributeRemove(const CommandInfo& info) : Command(info) {}
        int exec(utils::config config, const std::vector<std::string> &arguments) override;
};
