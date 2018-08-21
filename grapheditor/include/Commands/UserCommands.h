#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <tuple>

#include "Command.h"
#include "CommandInfo.h"
#include "Editor.h"
#include "collabclient/Client.h"


class ConnectCommand : public Command {
    private:
        collab::Client* _client;
    public:
        ConnectCommand(const CommandInfo& info, collab::Client& client);
        int exec(utils::config config,
                 const std::vector<std::string>& args) override;
};

class HelpCommand : public Command {
    private:
        const std::map<std::string, Command*>* _commands;
    public:
        HelpCommand(const CommandInfo& info,
                    const std::map<std::string, Command*> *commands);
        int exec(utils::config config,
                 const std::vector<std::string>& args) override;
};

class QuitCommand : public Command {
    private:
        Editor* editor;
    public:
        QuitCommand(const CommandInfo& info, Editor* editor);
        int exec(utils::config config,
                 const std::vector<std::string>& args) override;
};


