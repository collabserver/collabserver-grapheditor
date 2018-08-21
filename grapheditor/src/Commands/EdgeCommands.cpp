#include "Commands/EdgeCommands.h"

#include "collabdata/custom/SimpleGraph.h"


int EdgeRemoveCommand::exec(utils::config config,
                            const std::vector<std::string> &args){
    if(args.size()!=2) {
        std::cout << "ERROR: invalid arguments\n";
        std::cout << "USAGE: " << getUsage() << "\n";
        return -1;
    }

    config.getDataStructure()->removeEdge(args[0], args[1]);
    return 0;
}

int EdgeAddCommand::exec(utils::config config,
                         const std::vector<std::string> &args) {
    if (args.size() != 2) {
        std::cout << "ERROR: invalid arguments\n";
        std::cout << "USAGE: " << getUsage() << "\n";
        return -1;
    }

    config.getDataStructure()->addEdge(args[0], args[1]);
    return 0;
}
