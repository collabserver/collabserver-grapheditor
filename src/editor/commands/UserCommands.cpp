#include "editor/commands/UserCommands.h"

#include <iostream>

#include "Global.h"
#include "utils/constants.h"


// -----------------------------------------------------------------------------
// Connect
// -----------------------------------------------------------------------------

int ConnectCommand::exec(const std::vector<std::string>& args) {
    if(args.size() != 2) {
        std::cout << "ERROR: invalid arguments\n";
        std::cout << "USAGE: " << getUsage() << "\n";
        return -1;
    }
    else if(Global::get().collabclient().isConnected()) {
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
    if(!success) {
        std::cout << "FAILED\n";
        std::cout << "Unable to establish connection\n";
        return -1;
    }
    std::cout << "SUCCESS\n";
    std::cout << "Successfully connected\n";
    return 0;
}


// -----------------------------------------------------------------------------
// Disconnect
// -----------------------------------------------------------------------------

int DisconnectCommand::exec(const std::vector<std::string>& args) {
    if(args.size() > 0) {
        std::cout << "ERROR: invalid arguments\n";
        std::cout << "USAGE: " << getUsage() << "\n";
        return -1;
    }
    else if(!Global::get().collabclient().isConnected()) {
        std::cout << "ERROR: You are not connected\n";
        return -1;
    }
    else if(Global::get().collabclient().isDataLoaded()) {
        std::cout << "ERROR: You are connected to a collab data\n";
        std::cout << "INFO:  You must leave the collab data before disconnect\n";
        return -1;
    }

    std::cout << "Disconnecting... ";
    bool success = Global::get().collabclient().disconnect();
    if(!success) {
        std::cout << "FAILED\n";
        std::cout << "ERROR: Unable to disconnect. Error occurred\n";
        return -1;
    }
    std::cout << "SUCCESS\n";
    std::cout << "Successfully disconnected\n";

    return 0;
}


// -----------------------------------------------------------------------------
// CreateData
// -----------------------------------------------------------------------------

int CreateDataCommand::exec(const std::vector<std::string>& args) {
    if(args.size() != 0 && args.size() != 5) {
        std::cout << "ERROR: Invalid arguments\n";
        std::cout << "USAGE: " << getUsage() << "\n";
        return -1;
    }
    else if(args.size() > 0 && args[0] != "--mvk") {
        std::cout << "ERROR: Invalid arguments\n";
        std::cout << "USAGE: " << getUsage() << "\n";
        return -1;
    }
    else if(!Global::get().collabclient().isConnected()) {
        std::cout << "ERROR: You are not connected\n";
        return -1;
    }
    else if(Global::get().collabclient().isDataLoaded()) {
        std::cout << "ERROR: You are already connected to a collab data\n";
        std::cout << "INFO:  You must leave the collab data first\n";
        return -1;
    }

    if(args.size() == 5) {
        // Just some aliases
        const std::string& ip           = args[1];
        const int port                  = atoi(args[2].c_str());
        const std::string& model        = args[3];
        const std::string& mmodel       = args[4];
        const std::string& username     = COLLAB_MVK_DEFAULT_USER;
        const std::string& pswd         = COLLAB_MVK_DEFAULT_USER_PSWD;

        std::cout << "Connecting to MVK Database server... " << std::endl;
        Global::get().mvk().connect(ip, port, username, pswd);
        std::cout << "Successfully connected to MVK\n";

        Global::get().resetGraphData(model, mmodel);
    }
    else {
        Global::get().resetGraphData();
    }

    collab::SimpleGraph& graph = Global::get().graphdata();

    std::cout << "Creating collab data on server... ";
    bool success = Global::get().collabclient().createData(&graph);
    if(!success) {
        std::cout << "FAILED\n";
        std::cout << "ERROR: Unable to create the data. Error occurred\n";
        return -1;
    }
    std::cout << "SUCCESS\n";
    std::cout << "Data successfully created and joined\n";
    return 0;
}


// -----------------------------------------------------------------------------
// JoinData
// -----------------------------------------------------------------------------

int JoinDataCommand::exec(const std::vector<std::string>& args) {
    if(args.size() != 1) {
        std::cout << "ERROR: Invalid arguments\n";
        std::cout << "USAGE: " << getUsage() << "\n";
        return -1;
    }
    else if(!Global::get().collabclient().isConnected()) {
        std::cout << "ERROR: You are not connected\n";
        return -1;
    }
    else if(Global::get().collabclient().isDataLoaded()) {
        std::cout << "ERROR: You are already connected to a collab data\n";
        std::cout << "INFO:  You must leave the collab data first\n";
        return -1;
    }

    int dataID = atoi(args[0].c_str());
    if (dataID == 0) {
        std::cout << "ERROR: Invalid data ID value (Number required)\n";
        std::cout << "USAGE: " << getUsage() << "\n";
        return -1;
    }

    Global::get().resetGraphData();
    collab::SimpleGraph& graph = Global::get().graphdata();

    std::cout << "Joining data (" << dataID << ")... ";
    bool success = Global::get().collabclient().joinData(&graph, dataID);
    if(!success) {
        std::cout << "FAILED\n";
        std::cout << "ERROR: Unable to join. Error occurred\n";
        return -1;
    }
    std::cout << "SUCCESS\n";
    std::cout << "Collaborative data successfully joined\n";
    return 0;
}


// -----------------------------------------------------------------------------
// Info
// -----------------------------------------------------------------------------

int LeaveDataCommand::exec(const std::vector<std::string>& args) {
    if(args.size() > 0) {
        std::cout << "ERROR: Invalid arguments\n";
        std::cout << "USAGE: " << getUsage() << "\n";
        return -1;
    }
    else if(!Global::get().collabclient().isConnected()) {
        std::cout << "ERROR: You are not connected\n";
        return -1;
    }
    else if(!Global::get().collabclient().isDataLoaded()) {
        std::cout << "ERROR: You are not connected to a collab data\n";
        return -1;
    }

    std::cout << "Leaving current collab data... ";
    bool success = Global::get().collabclient().leaveData();
    if(!success) {
        std::cout << "FAILED\n";
        std::cout << "ERROR: Unable to leave\n";
        return -1;
    }
    std::cout << "SUCCESS\n";
    std::cout << "Collab data successfully left\n";
    return 0;
}


// -----------------------------------------------------------------------------
// Info
// -----------------------------------------------------------------------------

int InfoCommand::exec(const std::vector<std::string>& args) {
    collab::Client& client = Global::get().collabclient();
    std::cout << "Status: "
              << (client.isConnected() ? "connected" : "disconnected") << "\n"
              << "Data:   "
              << (client.isDataLoaded() ? "loaded" : "no data loaded") << "\n"
              << "DataID: "
              << client.getDataID() << "\n";
    return 0;
}


// -----------------------------------------------------------------------------
// Quit
// -----------------------------------------------------------------------------

int QuitCommand::exec(const std::vector<std::string>& args) {
    if(Global::get().collabclient().isDataLoaded()) {
        std::cout << "Leaving collab data... ";
        bool success = Global::get().collabclient().leaveData();
        if(!success) {
            std::cout << "FAILED\n";
            std::cout << "ERROR: Unable to leave data\n";
            return -1;
        }
        std::cout << "SUCCESS\n";
    }
    if(Global::get().collabclient().isConnected()) {
        std::cout << "Disconnecting from server... ";
        bool success = Global::get().collabclient().disconnect();
        if(!success) {
            std::cout << "FAILED\n";
            std::cout << "ERROR: Unable to disconnect\n";
            return -1;
        }
        std::cout << "SUCCESS\n";
    }

    Global::get().editor().stop();

    return 0;
}


// -----------------------------------------------------------------------------
// Help
// -----------------------------------------------------------------------------

int HelpCommand::exec(const std::vector<std::string>& args) {
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


// -----------------------------------------------------------------------------
// AskGod (Ugly)
// -----------------------------------------------------------------------------

int UglyCommand::exec(const std::vector<std::string>& args) {
    if(!Global::get().collabclient().isConnected()) {
        std::cout << "ERROR: You are not connected\n";
        return -1;
    }
    std::cout << "Asking God if you are ugly...\n";
    bool isUgly = Global::get().collabclient().isUgly();
    if(isUgly) {
        std::cout << "Hum... Sounds like you are ugly...\n";
    }
    else {
        std::cout << "Incredible!! You are not ugly!!!!\n";
    }
    return 0;
}


