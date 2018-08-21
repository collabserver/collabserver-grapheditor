#include "Commands/UserCommands.h"

#include <cassert>

#include "utils.h"


// -----------------------------------------------------------------------------
// Connect
// -----------------------------------------------------------------------------

ConnectCommand::ConnectCommand(const CommandInfo& info, collab::Client& client)
  : Command(info) {
      _client = &client;
}

int ConnectCommand::exec(utils::config config,
                         const std::vector<std::string> &args) {
    if (args.size() != 2) {
        std::cout << "ERROR: invalid arguments\n";
        std::cout << "USAGE: " << getUsage() << "\n";
        return -1;
    }

    int port = atoi(args[1].c_str());
    if (port == 0) {
        std::cout << "ERROR: invalid port number\n";
        std::cout << "USAGE: " << getUsage() << "\n";
        return -5;
    }

    std::cout << "Connecting to " << args[0] << ":" << port << "...\n";
    bool success = _client->connect(args[0].c_str(), port);
    if(success) {
        std::cout << "Successfully connected!\n";
        return 0;
    }
    else {
        std::cout << "Unable to connect...\n";
        return -1;
    }
    return 0;
}


// -----------------------------------------------------------------------------
// Help
// -----------------------------------------------------------------------------

HelpCommand::HelpCommand(const CommandInfo& info,
                         const std::map<std::string, Command*> *commands)
  : Command(info) {
      assert(commands != nullptr && commands->size() > 0);
      _commands = commands;
}

int HelpCommand::exec(utils::config config,
                      const std::vector<std::string> &args) {
    if(args.size() == 0) {
        std::cout << "COMMANDS:\n";
        for (const auto& command : *_commands) {
            int spaces = 15 - command.second->getName().size();
            if(command.first == command.second->getName()) {
                std::cout << "    "  << command.second->getName();
                for(int k = 0; k < spaces; ++k) {
                    std::cout << " ";
                }
                std::cout << "    "  << command.second->getUsage() << "\n";
            }
        }
        std::cout << "INFORMATION:\n";
        std::cout << "    Use \"help COMMAND_NAME\" to display command specific help.\n";
        std::cout << "    You may use the sort version of command name.\n"
                  << "    (ex: vadd for vertexAdd)\n";
    }
    else if(args.size() == 1) {
        if(_commands->count(args[0]) != 1) {
            std::cout << args[0] << " is not a valid command\n";
            return -1;
        }
        Command* cmd = _commands->find(args[0])->second;
        std::cout << "NAME:   "  << cmd->getName() << "\n"
                  << "SHORT:  " << cmd->getShortName() << "\n"
                  << "USAGE:  " << cmd->getUsage() << "\n"
                  << "INFO:   "  << cmd->getDescription() << std::endl;
    }
    else {
        std::cout << "ERROR: invalid arguments\n";
        std::cout << "USAGE: " << getUsage() << "\n";
        return -1;
    }
    return 0;
}


// -----------------------------------------------------------------------------
// Quit
// -----------------------------------------------------------------------------

QuitCommand::QuitCommand(const CommandInfo& info, Editor* editor)
  : Command(info) {
        this->editor = editor;
    }

int QuitCommand::exec(utils::config config,
                      const std::vector<std::string> &args) {
    this->editor->stop();
    return 0;
}
