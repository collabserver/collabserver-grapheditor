#include "Commands/UserCommands.h"

#include <cassert>
#include <regex>

#include "utils.h"


// -----------------------------------------------------------------------------
// Connect
// -----------------------------------------------------------------------------

int ConnectCommand::exec(utils::config config,
                         const std::vector<std::string> &args) {
    if (args.size() != 2) {
        std::cout << "ERROR: invalid arguments\n";
        std::cout << "USAGE: " << getUsage() << "\n";
        return -1;
    }
    std::regex reg("^([01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])\\.([01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])\\.([01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])\\.([01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])$");

    if (!std::regex_match(args[0], reg)) {
        std::cout << "ERROR: invalid IP address\n";
        std::cout << "USAGE: " << getUsage() << "\n";
        return -4;
    }

    int port = atoi(args[1].c_str());
    if (port == 0) {
        std::cout << "ERROR: invalid port number\n";
        return -5;
    }

    //TODO use the collab-client-interface connect
    std::cout << "Connecting to " << args[0] << ":" << port << " ...\n";
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
        std::cout << "  COMMANDS:\n";
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
        std::cout << "  INFORMATION:\n";
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
        std::cout << "  NAME:\t"  << cmd->getName() << "\n"
                  << "  SHORT:\t" << cmd->getShortName() << "\n"
                  << "  USAGE:\t" << cmd->getUsage() << "\n"
                  << "  INFO:\t"  << cmd->getDescription() << std::endl;
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
