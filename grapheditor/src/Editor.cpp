#include "Editor.h"

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <tuple>

#include "utils.h"
#include "Commands/Command.h"
#include "Commands/HelpCommand.h"
#include "Commands/QuitCommand.h"
#include "Commands/ConnectCommand.h"
#include "Commands/EdgeAddCommand.h"
#include "Commands/EdgeRemoveCommand.h"
#include "Commands/VertexAddCommand.h"
#include "Commands/VertexEditCommand.h"
#include "Commands/VertexInfoCommand.h"
#include "Commands/VertexListCommand.h"
#include "Commands/VertexRemoveCommand.h"
#include "Commands/AttributeAdd.h"
#include "Commands/AttributeRemove.h"
#include "Commands/AttributeSet.h"
#include "SimpleGraphOperationObserver.h"
#include "SimpleGraphOperationHandler.h"
#include "collabdata/custom/SimpleGraph.h"


#define WELCOME_MENU_TEXT     \
"________________________________________________________________________________\n"\
"                                                                                \n"\
"          ___|                 |       ____|     |_) |                          \n"\
"         |      __| _` | __ \\  __ \\    __|    _` | | __|  _ \\   __|          \n"\
"         |   | |   (   | |   | | | |   |     (   | | |   (   | |                \n"\
"        \\____|_|  \\__,_| .__/ _| |_|  _____|\\__,_|_|\\__|\\___/ _|           \n"\
"                        _|                                                      \n"\
"________________________________________________________________________________"


Editor::Editor() {
    Command *cmd = nullptr;

    cmd = new QuitCommand(this);
    _commands[cmd->getName()] = cmd;
    cmd = new EdgeAddCommand();
    _commands[cmd->getName()] = cmd;
    cmd = new EdgeRemoveCommand();
    _commands[cmd->getName()] = cmd;
    cmd = new AttributeAdd();
    _commands[cmd->getName()] = cmd;
    cmd = new AttributeRemove();
    _commands[cmd->getName()] = cmd;
    cmd = new AttributeSet();
    _commands[cmd->getName()] = cmd;
    cmd = new VertexAddCommand();
    _commands[cmd->getName()] = cmd;
    cmd = new VertexRemoveCommand();
    _commands[cmd->getName()] = cmd;
    cmd = new VertexListCommand();
    _commands[cmd->getName()] = cmd;
    cmd = new VertexInfoCommand();
    _commands[cmd->getName()] = cmd;
    cmd = new ConnectCommand();
    _commands[cmd->getName()] = cmd;
    cmd = new HelpCommand(&_commands);
    _commands[cmd->getName()] = cmd;
}

Editor::~Editor() {
    this->stop();
    for (const auto& command : _commands) {
        free(command.second);
    }
}

void Editor::start() {
    assert(!_commands.empty());
    assert(_running == false);

    if(_running == true) { return; }
    _running = true;

    collab::SimpleGraph dataStructure = collab::SimpleGraph();
    SimpleGraphOperationHandler opHandler = SimpleGraphOperationHandler();
    SimpleGraphOperationObserver opObserver = SimpleGraphOperationObserver(opHandler);
    dataStructure.addOperationObserver(opObserver);

    std::cout << WELCOME_MENU_TEXT << "\n";
    std::cout << "To display the help, type \"help\"\n";

    std::string word;
    std::string arguments;
    std::vector<std::string> argumentsList;
    utils::config conf = utils::config();
    conf.setDataStructure(&dataStructure);
    conf.flipLoaded();

    while(_running) {
        std::cout << "=> ";
        std::cin >> word;
        argumentsList.clear();
        if (_commands.count(word) == 1) {
            std::getline(std::cin, arguments);
            argumentsList = utils::split_no_quotes(arguments.begin(), arguments.end());
            _commands[word]->exec(conf, argumentsList);
        }
        else {
            std::getline(std::cin, arguments);
            std::cout << "Unknown command. "
                      << "To see all available commands, type \"help\".\n";
        }
    }
}

void Editor::stop() {
    _running = false;
}

