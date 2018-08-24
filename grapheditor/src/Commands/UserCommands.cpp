#include "Commands/UserCommands.h"

#include <cassert>

#include "Global.h"


// -----------------------------------------------------------------------------
// Connect
// -----------------------------------------------------------------------------

int ConnectCommand::exec(const std::vector<std::string> &args) {
    if(args.size() != 2) {
        std::cout << "ERROR: invalid arguments\n";
        std::cout << "USAGE: " << getUsage() << "\n";
        return -1;
    }

    if(Global::get().collabclient().isConnected()) {
        std::cout << "ERROR: You are already connected\n";
        return -1;
    }

    int port = atoi(args[1].c_str());
    if (port == 0) {
        std::cout << "ERROR: invalid port number\n";
        std::cout << "USAGE: " << getUsage() << "\n";
        return -1;
    }

    std::cout << "Connecting to " << args[0] << ":" << port << "... ";
    bool success = Global::get().collabclient().connect(args[0].c_str(), port);
    if(success && Global::get().collabclient().isConnected()) {
        std::cout << "OK\n";
        std::cout << "Successfully connected\n";
        return 0;
    }
    else {
        std::cout << "ERROR\n";
        std::cout << "Unable to establish connect\n";
        return -1;
    }
    return 0;
}


// -----------------------------------------------------------------------------
// CreateDataVolatile
// -----------------------------------------------------------------------------

int CreateDataVolatileCommand::exec(const std::vector<std::string>& args) {
    // TODO
    std::cout << "TODO: No implemented yet\n";
    return 0;
}


// -----------------------------------------------------------------------------
// JoinData
// -----------------------------------------------------------------------------

int JoinDataCommand::exec(const std::vector<std::string>& args) {
    // TODO
    std::cout << "TODO: No implemented yet\n";
    return 0;
}


// -----------------------------------------------------------------------------
// Info
// -----------------------------------------------------------------------------

int LeaveDataCommand::exec(const std::vector<std::string>& args) {
    // TODO
    std::cout << "TODO: No implemented yet\n";
    return 0;
}


// -----------------------------------------------------------------------------
// Info
// -----------------------------------------------------------------------------

int InfoCommand::exec(const std::vector<std::string>& args) {
    std::cout << "Status: "
              << (Global::get().collabclient().isConnected()
                      ? "connected" : "disconnected") << "\n"
              << "Data:   "
              << (Global::get().collabclient().isDataLoaded()
                      ? "loaded" : "no data loaded") << "\n"
              << "DataID: "
              << Global::get().collabclient().getDataID() << "\n";
    return 0;
}

// -----------------------------------------------------------------------------
// Quit
// -----------------------------------------------------------------------------

int QuitCommand::exec(const std::vector<std::string> &args) {
    Global::get().editor().stop();
    return 0;
}


// -----------------------------------------------------------------------------
// Help
// -----------------------------------------------------------------------------

int HelpCommand::exec(const std::vector<std::string> &args) {
    auto commands = Global::get().editor().getCommands();
    if(args.size() == 0) {
        std::cout << "COMMANDS:\n";
        for (const auto& command : commands) {
            int spaces = 15 - command.second->getName().size();
            if(command.first == command.second->getName()) {
                std::cout << "    "  << command.second->getName();
                for(int k = 0; k < spaces; ++k) {
                    std::cout << " ";
                }
                std::cout << "    "  << command.second->getDescription() << "\n";
            }
        }
        std::cout << "INFORMATION:\n";
        std::cout << "    Use \"help COMMAND_NAME\" to display command specific help.\n";
        std::cout << "    You may use the sort version of command name.\n"
                  << "    (ex: vadd for vertexAdd)\n";
    }
    else if(args.size() == 1) {
        if(commands.count(args[0]) != 1) {
            std::cout << args[0] << " is not a valid command\n";
            return -1;
        }
        Command* cmd = commands.find(args[0])->second;
        std::cout << "NAME:   "  << cmd->getName() << "\n"
                  << "SHORT:  " << cmd->getShortName() << "\n"
                  << "USAGE:  " << cmd->getUsage() << "\n"
                  << "INFO:   "  << cmd->getDescription() << std::endl;
    }
    else {
        std::cout << "ERROR: invalid arguments\n";
        std::cout << "USAGE: " << getUsage() << "\n";
        return -1;
    }
    return 0;
}
