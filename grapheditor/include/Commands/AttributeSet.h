#pragma once

#include "Command.h"


class AttributeSet : public Command {
    public:
        AttributeSet(const CommandInfo& info) : Command(info) {}
        int exec(utils::config config, const std::vector<std::string> &arguments) override;
};
