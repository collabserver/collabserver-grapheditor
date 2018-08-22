#include "Commands/EdgeCommands.h"

#include "Global.h"


static Editor&              editor  = Global::get().editor(); // Simple alias
static collab::Client&      client  = Global::get().collabclient();
static collab::SimpleGraph* graph   = Global::get().graphdata();


int EdgeRemoveCommand::exec(const std::vector<std::string> &args){
    if(args.size() != 2) {
        std::cout << "ERROR: invalid arguments\n";
        std::cout << "USAGE: " << getUsage() << "\n";
        return -1;
    }

    if(!client.isConnected()) {
        std::cout << "ERROR: You must be connected to a server first\n";
        std::cout << "HINT: See connect command\n";
        return -1;
    }

    if(!client.isDataLoaded()) {
        std::cout << "ERROR: No data loaded yet\n";
        return -1;
    }

    graph->removeEdge(args[0], args[1]);
    return 0;
}

int EdgeAddCommand::exec(const std::vector<std::string> &args) {
    if (args.size() != 2) {
        std::cout << "ERROR: invalid arguments\n";
        std::cout << "USAGE: " << getUsage() << "\n";
        return -1;
    }

    if(!client.isConnected()) {
        std::cout << "ERROR: You must be connected to a server first\n";
        std::cout << "HINT: See connect command\n";
        return -1;
    }

    if(!client.isDataLoaded()) {
        std::cout << "ERROR: No data loaded yet\n";
        return -1;
    }

    graph->addEdge(args[0], args[1]);
    return 0;
}


