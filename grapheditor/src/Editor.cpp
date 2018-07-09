#include "Editor.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <cstdlib>

#include "utils.h"
#include "Commands/Command.h"
#include "Commands/HelpCommand.h"
#include "Commands/QuitCommand.h"
#include "Commands/EdgeAddCommand.h"
#include "Commands/EdgeRemoveCommand.h"
#include "Commands/GraphCloseCommand.h"
#include "Commands/GraphDeleteCommand.h"
#include "Commands/GraphListCommand.h"
#include "Commands/GraphNewCommand.h"
#include "Commands/GraphOpenCommand.h"
#include "Commands/VertexAddCommand.h"
#include "Commands/VertexEditCommand.h"
#include "Commands/VertexInfoCommand.h"
#include "Commands/VertexRemoveCommand.h"

#include "collabdata/custom/SimpleGraph.h"

Editor::Editor()
{
    this->running = false;
    ///////////////////  Editor commands loading  ///////////////////
    Command *command_;
    command_ = new QuitCommand(this);
    this->commands[command_->getName()] = command_;
    command_ = new EdgeAddCommand();
    this->commands[command_->getName()] = command_;
    command_ = new HelpCommand(&(this->commands));
    this->commands[command_->getName()] = command_;
    command_ = new EdgeRemoveCommand();
    this->commands[command_->getName()] = command_;
    command_ = new GraphCloseCommand();
    this->commands[command_->getName()] = command_;
    command_ = new GraphDeleteCommand();
    this->commands[command_->getName()] = command_;
    command_ = new GraphListCommand();
    this->commands[command_->getName()] = command_;
    command_ = new GraphNewCommand();
    this->commands[command_->getName()] = command_;
    command_ = new GraphOpenCommand();
    this->commands[command_->getName()] = command_;
    ///////////////////  Editor commands loading end ///////////////////
}

/**
 * @brief Start the graph editing
 *        Loop while Editor::stopRunning isn't called
 * 
 * @return int 
 */
int Editor::startRunning()
{
    if (commands.empty())
    {
        std::cerr << "Error : No commands available in the editor." << std::endl;
        return -1;
    }

    this->running = true;
    //FAKE datastructure :
    std::vector<std::tuple<int, int>> datastructure;

    std::cout << "***********************************************************************" << std::endl
              << "***********  Welcome in the collaborative CLI graph editor  ***********" << std::endl
              << "***********************************************************************"
              << std::endl;
    std::cout << std::endl
              << "Create and edit your graph by tipping the appropriate command" << std::endl;
    std::cout << "To display the help, type help" << std::endl;
    std::cout << "***********************************************************************"
              << std::endl
              << std::endl;

    std::string word;
    std::string arguments;
    std::vector<std::string> argumentsList;
    utils::config conf = utils::config();
    conf.setDataStructure(datastructure);
    conf.flipLoaded();
    while (this->running)
    {
        std::cout << "=> ";
        std::cin >> word;
        argumentsList.clear();
        if (commands.count(word) == 1)
        {
            std::getline(std::cin, arguments);
            argumentsList = utils::split_no_quotes(arguments.begin(), arguments.end());
            commands[word]->exec(conf, argumentsList);
        }
        else
        {
            std::getline(std::cin, arguments);
            std::cout << "Undefined command. To see all available commands, type \"help\"." << std::endl;
        }
    }

    return 0;
}

int Editor::stopRunning()
{
    this->running = false;
    return 0;
}

/**
 * @brief Destroy the Editor::Editor object
 *        Destroy all the commands object when the editor is destroyed
 * 
 */
Editor::~Editor()
{
    for (auto const &command : this->commands)
    {
        free(command.second);
    }
}