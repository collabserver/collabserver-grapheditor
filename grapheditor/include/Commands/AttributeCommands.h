#pragma once

#include "Command.h"
#include "CommandInfo.h"


class AttributeAdd : public Command {
    public:
        AttributeAdd(const CommandInfo& info) : Command(info) {}
        int exec(utils::config config,
                 const std::vector<std::string> &arguments) override;
};

class AttributeRemove : public Command {
    public:
        AttributeRemove(const CommandInfo& info) : Command(info) {}
        int exec(utils::config config,
                 const std::vector<std::string> &arguments) override;
};

class AttributeSet : public Command {
    public:
        AttributeSet(const CommandInfo& info) : Command(info) {}
        int exec(utils::config config,
                 const std::vector<std::string> &arguments) override;
};
