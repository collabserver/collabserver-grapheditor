#include "editor/commands/EdgeCommands.h"

#include <iostream>

#include "Global.h"

int EdgeRemoveCommand::exec(const std::vector<std::string> &args) {
    if (args.size() != 2) {
        std::cout << "ERROR: invalid arguments\n";
        std::cout << "USAGE: " << getUsage() << "\n";
        return -1;
    }

    if (!Global::get().collabclient().isConnected()) {
        std::cout << "ERROR: You must be connected to a server first\n";
        std::cout << "HINT: See connect command\n";
        return -1;
    }

    if (!Global::get().collabclient().isDataLoaded()) {
        std::cout << "ERROR: No data loaded yet\n";
        return -1;
    }

    Global::get().graphdata().removeEdge(args[0], args[1]);
    return 0;
}

int EdgeAddCommand::exec(const std::vector<std::string> &args) {
    if (args.size() != 2) {
        std::cout << "ERROR: invalid arguments\n";
        std::cout << "USAGE: " << getUsage() << "\n";
        return -1;
    }

    if (!Global::get().collabclient().isConnected()) {
        std::cout << "ERROR: You must be connected to a server first\n";
        std::cout << "HINT: See connect command\n";
        return -1;
    }

    if (!Global::get().collabclient().isDataLoaded()) {
        std::cout << "ERROR: No data loaded yet\n";
        return -1;
    }

    Global::get().graphdata().addEdge(args[0], args[1]);
    return 0;
}
