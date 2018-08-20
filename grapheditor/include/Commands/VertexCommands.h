#pragma once

#include "Command.h"


class VertexAddCommand : public Command {
    public:
        VertexAddCommand(const CommandInfo& info) : Command(info) {}
        int exec(utils::config config,
                 const std::vector<std::string> &arguments) override;
};

class VertexEditCommand : public Command {
    public:
        VertexEditCommand(const CommandInfo& info) : Command(info) {}
        int exec(utils::config config,
                 const std::vector<std::string> &arguments) override;
};

class VertexInfoCommand : public Command {
    public:
        VertexInfoCommand(const CommandInfo& info) : Command(info) {}
        int exec(utils::config config,
                 const std::vector<std::string> &arguments) override;
};

class VertexListCommand : public Command {
    public:
        VertexListCommand(const CommandInfo& info) : Command(info) {}
        int exec(utils::config config,
                 const std::vector<std::string> &arguments) override;
};

class VertexRemoveCommand : public Command {
    public:
        VertexRemoveCommand(const CommandInfo& info) : Command(info) {}
        int exec(utils::config config,
                 const std::vector<std::string> &arguments) override;
};
