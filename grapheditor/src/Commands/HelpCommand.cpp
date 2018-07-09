#include "Commands/HelpCommand.h"

HelpCommand::HelpCommand(const std::map<std::string, Command *> *commandList)
    : Command("help", "This is the help command", "Non qui ut exercitation dolore consectetur nisi occaecat minim aliqua nulla sint est labore consectetur. Voluptate labore sit nulla Lorem eu officia do ad eiusmod qui cupidatat. Dolore sint deserunt sunt duis magna nulla ad aute deserunt officia sunt sint voluptate occaecat. Minim esse irure incididunt reprehenderit aute enim id ut adipisicing anim pariatur veniam irure. Adipisicing elit nostrud non exercitation in dolore. Consequat officia aliquip ex consectetur reprehenderit labore consectetur ullamco dolor aliqua reprehenderit. Deserunt nulla cupidatat deserunt ex non qui.")
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

int HelpCommand::exec(utils::config config, std::vector<std::string> arguments)
{
    std::cout << "Available commands :" << std::endl;
    for(auto const &command : (*this->commandList) ){
        std::cout << "\t- " << command.second->getName() << " : " << command.second->getHelp() << std::endl;
    }
    return 0;
}