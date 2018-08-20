#include "Commands/UserCommands.h"

#include <cassert>
#include <regex>

#include "utils.h"


int ConnectCommand::exec(utils::config config,
                         const std::vector<std::string> &arguments) {
    if (arguments.size() != 2) {
        std::cout << "Error : missing or too many arguments" << std::endl;
        std::cout << "Usage : connect \"ip\" \"port\"" << std::endl;
        return -1;
    }
    std::regex reg("^([01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])\\.([01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])\\.([01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])\\.([01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])$");

    if (!std::regex_match(arguments[0], reg)) {
        std::cout << "Error : invalid IP address" << std::endl;
        return -4;
    }

    int port = atoi(arguments[1].c_str());
    if (port == 0) {
        std::cout << "Error : invalid port number" << std::endl;
        return -5;
    }

    //TODO use the collab-client-interface connect
    std::cout << "Connecting to " << arguments[0]
              << ":" << port << " ...\n";
    return 0;
}

HelpCommand::HelpCommand(const CommandInfo& info,
                         const std::map<std::string, Command*> *commandList)
  : Command(info) {
      assert(commandList->size() > 0);
}

int HelpCommand::exec(utils::config config,
                      const std::vector<std::string> &arguments) {
    if(arguments.size() == 0) {
        std::cout << "Commands:" << std::endl;
        for (const auto& command : *_commandList) {
            std::cout << "    "  << command.second->getName()
                      << ":\t\t" << command.second->getUsage() << "\n";
        }
    }
    else if(arguments.size() == 1) {
        if(_commandList->count(arguments[0]) == 1) {
            std::cout << _commandList->find(arguments[0])->second->getDescription() << std::endl;
        }
        else {
            std::cout << arguments[0] << " is not a function" << std::endl;
        }
    }
    else {
        std::cout << "Error : too many arguments" << std::endl;
        return -1;
    }
    return 0;
}

QuitCommand::QuitCommand(const CommandInfo& info, Editor* editor)
  : Command(info) {
        this->editor = editor;
    }

int QuitCommand::exec(utils::config config,
                      const std::vector<std::string> &arguments) {
    this->editor->stop();
    return 0;
}
