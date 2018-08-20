#pragma once

#include <map>
#include <string>

#include "Commands/Command.h"


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

        void start();
        void stop();
};


