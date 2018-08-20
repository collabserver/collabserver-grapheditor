#include "Editor.h"

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <tuple>

#include "utils.h"
#include "CommandInfoPool.h"
#include "Commands/UserCommands.h"
#include "Commands/EdgeCommands.h"
#include "Commands/VertexCommands.h"
#include "Commands/AttributeCommands.h"
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

    CommandInfoPool pool;
    pool.loadFromFile("resources/commands.csv");

    Command* cmd = nullptr;

    cmd = new QuitCommand(pool.get("QUIT"), this);
    _commands[cmd->getName()] = cmd;
    _commands[cmd->getShortName()] = cmd;

    cmd = new ConnectCommand(pool.get("CONNECT"));
    _commands[cmd->getName()] = cmd;
    _commands[cmd->getShortName()] = cmd;

    cmd = new EdgeAddCommand(pool.get("EDGE_ADD"));
    _commands[cmd->getName()] = cmd;
    _commands[cmd->getShortName()] = cmd;

    cmd = new EdgeRemoveCommand(pool.get("EDGE_REM"));
    _commands[cmd->getName()] = cmd;
    _commands[cmd->getShortName()] = cmd;

    cmd = new AttributeAdd(pool.get("ATTR_ADD"));
    _commands[cmd->getName()] = cmd;
    _commands[cmd->getShortName()] = cmd;

    cmd = new AttributeRemove(pool.get("ATTR_REM"));
    _commands[cmd->getName()] = cmd;
    _commands[cmd->getShortName()] = cmd;

    cmd = new AttributeSet(pool.get("ATTR_SET"));
    _commands[cmd->getName()] = cmd;
    _commands[cmd->getShortName()] = cmd;

    cmd = new VertexAddCommand(pool.get("VERTEX_ADD"));
    _commands[cmd->getName()] = cmd;
    _commands[cmd->getShortName()] = cmd;

    cmd = new VertexRemoveCommand(pool.get("VERTEX_REM"));
    _commands[cmd->getName()] = cmd;
    _commands[cmd->getShortName()] = cmd;

    cmd = new VertexListCommand(pool.get("VERTEX_LIST"));
    _commands[cmd->getName()] = cmd;
    _commands[cmd->getShortName()] = cmd;

    cmd = new VertexInfoCommand(pool.get("VERTEX_INFO"));
    _commands[cmd->getName()] = cmd;
    _commands[cmd->getShortName()] = cmd;

    cmd = new HelpCommand(pool.get("HELP"), &_commands);
    _commands[cmd->getName()] = cmd;
    _commands[cmd->getShortName()] = cmd;
}

Editor::~Editor() {
    this->stop();
    for (auto command : _commands) {
        if(command.second->getName() == command.first) {
            delete command.second;
        }
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

