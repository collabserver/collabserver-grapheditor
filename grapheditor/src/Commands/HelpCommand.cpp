#include "Commands/HelpCommand.h"

HelpCommand::HelpCommand(const std::map<std::string, Command *> *commandList)
    : Command("help", "Display this help or the help of a specified command", "Name :\n\t help - Display the list of available commands or the help of a specified command.\nUsage :\n\thelp\n\thelp [command name]")
{
    if (commandList->size() > 0)
    {
        this->commandList = commandList;
    }
    else
    {
        throw new std::invalid_argument("Error : commandList cannot be empty");
    }
}

int HelpCommand::exec(utils::config config, const std::vector<std::string> &arguments)
{
    if (arguments.size() == 0)
    {
        std::cout << "Available commands :" << std::endl;
        for (auto const &command : (*this->commandList))
        {
            std::cout << "\t- " << command.second->getName() << " : " << command.second->getHelp() << std::endl;
        }
    }
    else if (arguments.size() == 1)
    {
        if (this->commandList->count(arguments[0]) == 1)
        {
            std::cout << this->commandList->find(arguments[0])->second->getResume() << std::endl;
        }else{
            std::cout << arguments[0] << " is not a function" << std::endl;
        }
    }
    else{
        std::cout << "error : too many arguments" << std::endl;
        return -1;
    }
    return 0;
}