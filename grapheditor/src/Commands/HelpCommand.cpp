#include "Commands/HelpCommand.h"


HelpCommand::HelpCommand(const std::map<std::string, Command*> *commandList)
  : Command("help",
            "Display this help or the help of a specified command",
            "Name:\n\t help - Display the list of available commands or the help of a specified command.\nUsage:\n\thelp\n\thelp [command name]") {
    if (commandList->size() > 0) {
        _commandList = commandList;
    }
    else {
        throw new std::invalid_argument("Error : commandList cannot be empty");
    }
}

int HelpCommand::exec(utils::config config, const std::vector<std::string> &arguments) {
    if (arguments.size() == 0) {
        std::cout << "Commands:" << std::endl;
        for (const auto& command : *_commandList) {
            std::cout << "    "
                      << command.second->getName()
                      << ":\t\t"
                      << command.second->getHelp()
                      << "\n";
        }
    }

    else if (arguments.size() == 1) {
        if (_commandList->count(arguments[0]) == 1) {
            std::cout << _commandList->find(arguments[0])->second->getResume() << std::endl;
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
