#include "Commands/HelpCommand.h"

#include <cassert>


HelpCommand::HelpCommand(const CommandInfo& info,
                         const std::map<std::string, Command*> *commandList)
  : Command(info) {
      assert(commandList->size() > 0);
}

int HelpCommand::exec(utils::config config, const std::vector<std::string> &arguments) {
    if (arguments.size() == 0) {
        std::cout << "Commands:" << std::endl;
        for (const auto& command : *_commandList) {
            std::cout << "    "
                      << command.second->getName()
                      << ":\t\t"
                      << command.second->getUsage()
                      << "\n";
        }
    }

    else if (arguments.size() == 1) {
        if (_commandList->count(arguments[0]) == 1) {
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
