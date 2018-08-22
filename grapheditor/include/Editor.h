#pragma once

#include <map>
#include <string>

#include "Command.h"
#include "collabclient/Client.h"


/**
 * \brief
 * The Editor class that manage le lifeCycle of the program
 */
class Editor {
    private:
        bool _running = false;
        std::map<std::string, Command*> _commands;

    public:
        Editor();
        ~Editor();

    public:
        void start();
        void stop();

    public:
        const std::map<std::string, Command*>& getCommands() const {
            return _commands;
        }
};


