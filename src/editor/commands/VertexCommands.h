#pragma once

#include <vector>

#include "editor/Command.h"
#include "editor/CommandInfo.h"

class VertexAddCommand : public Command {
   public:
    VertexAddCommand(const CommandInfo& info) : Command(info) {}
    int exec(const std::vector<std::string>& args) override;
};

class VertexRemoveCommand : public Command {
   public:
    VertexRemoveCommand(const CommandInfo& info) : Command(info) {}
    int exec(const std::vector<std::string>& args) override;
};

class VertexInfoCommand : public Command {
   public:
    VertexInfoCommand(const CommandInfo& info) : Command(info) {}
    int exec(const std::vector<std::string>& args) override;
};

class VertexListCommand : public Command {
   public:
    VertexListCommand(const CommandInfo& info) : Command(info) {}
    int exec(const std::vector<std::string>& args) override;
};
