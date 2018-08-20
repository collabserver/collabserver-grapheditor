#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <tuple>

#include "Command.h"
#include "CommandInfo.h"
#include "Editor.h"


class HelpCommand : public Command {
    private:
        const std::map<std::string, Command*>* _commandList;

    public:
        HelpCommand(const CommandInfo& info,
                    const std::map<std::string, Command*> *commandList);
        int exec(utils::config config,
                 const std::vector<std::string> &arguments);
};

class ConnectCommand : public Command {
    private:
        Editor* editor;

    public:
        ConnectCommand(const CommandInfo& info) : Command(info) {}
        int exec(utils::config config,
                 const std::vector<std::string> &arguments) override;
};

class QuitCommand : public Command {
    private:
        Editor* editor;

    public:
        QuitCommand(const CommandInfo& info, Editor* editor);
        int exec(utils::config config,
                 const std::vector<std::string> &arguments);
};


