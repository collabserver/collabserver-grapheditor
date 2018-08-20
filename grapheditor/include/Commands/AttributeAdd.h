#pragma once

#include "Command.h"
#include "CommandInfo.h"


class AttributeAdd : public Command {
    public:
        AttributeAdd(const CommandInfo& info) : Command(info) {}
        int exec(utils::config config, const std::vector<std::string> &arguments) override;
};
