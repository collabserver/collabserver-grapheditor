#include "Commands/AttributeCommands.h"

#include "Global.h"


static collab::Client&      client  = Global::get().collabclient();
static collab::SimpleGraph& graph   = Global::get().graphdata();


int AttributeAdd::exec(const std::vector<std::string> &args) {
    if (args.size() != 3) {
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

    graph.addAttribute(args[0], args[1], args[2]);
    return 0;
}

int AttributeRemove::exec(const std::vector<std::string> &args) {
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

    graph.removeAttribute(args[0], args[1]);
    return 0;
}

int AttributeSet::exec(const std::vector<std::string> &args) {
    if (args.size() != 3) {
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

    graph.setAttribute(args[0], args[1], args[2]);
    return 0;
}


