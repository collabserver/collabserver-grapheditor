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
        collab::Client _collabclient;

    public:
        Editor();
        ~Editor();

        void start();
        void stop();
};


