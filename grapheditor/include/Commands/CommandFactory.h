#pragma once

#include "Command.h"
#include "CommandInfo.h"


class CommandFactory {
    private:
        CommandFactory() = delete;
        CommandFactory(const CommandFactory& other) = delete;
        CommandFactory& operator=(const CommandFactory& other) = delete;

    public:
        Command* newCommand(const char* id) {
            return nullptr;
        }
};
