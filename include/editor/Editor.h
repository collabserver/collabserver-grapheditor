#pragma once

#include <map>
#include <string>

#include "Command.h"

/**
 * \brief
 * The Editor class that manage le lifeCycle of the program.
 *
 * Editor is a command line tool to work on SimpleGraph datastructure.
 */
class Editor {
   public:
    typedef std::map<std::string, Command*> MapCommands;

   private:
    bool _running = false;
    MapCommands _commands;

   public:
    Editor();
    ~Editor();

   public:
    void start();
    void stop();

   public:
    const MapCommands& getCommands() const { return _commands; }
};
