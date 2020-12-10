#pragma once

#include <vector>

#include "editor/Command.h"
#include "editor/CommandInfo.h"

class ConnectCommand : public Command {
   public:
    ConnectCommand(const CommandInfo& info) : Command(info) {}
    int exec(const std::vector<std::string>& args) override;
};

class DisconnectCommand : public Command {
   public:
    DisconnectCommand(const CommandInfo& info) : Command(info) {}
    int exec(const std::vector<std::string>& args) override;
};

class CreateDataCommand : public Command {
   public:
    CreateDataCommand(const CommandInfo& info) : Command(info) {}
    int exec(const std::vector<std::string>& args) override;
};

class JoinDataCommand : public Command {
   public:
    JoinDataCommand(const CommandInfo& info) : Command(info) {}
    int exec(const std::vector<std::string>& args) override;
};

class LeaveDataCommand : public Command {
   public:
    LeaveDataCommand(const CommandInfo& info) : Command(info) {}
    int exec(const std::vector<std::string>& args) override;
};

class InfoCommand : public Command {
   public:
    InfoCommand(const CommandInfo& info) : Command(info) {}
    int exec(const std::vector<std::string>& args) override;
};

class QuitCommand : public Command {
   public:
    QuitCommand(const CommandInfo& info) : Command(info) {}
    int exec(const std::vector<std::string>& args) override;
};

class HelpCommand : public Command {
   public:
    HelpCommand(const CommandInfo& info) : Command(info) {}
    int exec(const std::vector<std::string>& args) override;
};

class UglyCommand : public Command {
   public:
    UglyCommand(const CommandInfo& info) : Command(info) {}
    int exec(const std::vector<std::string>& args) override;
};
