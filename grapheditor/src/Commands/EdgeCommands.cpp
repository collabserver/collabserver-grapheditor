#include "Commands/EdgeCommands.h"

#include "collabdata/custom/SimpleGraph.h"


int EdgeRemoveCommand::exec(utils::config config,
                            const std::vector<std::string> &arguments){
    if(arguments.size()!=2) {
        std::cout << "Error : missing or too many arguments" << std::endl;
        std::cout << "Usage : edgeRemove \"from\" \"to\"" << std::endl;
        return -1;
    }

    config.getDataStructure()->removeEdge(arguments[0], arguments[1]);
    return 0;
}

int EdgeAddCommand::exec(utils::config config,
                         const std::vector<std::string> &arguments) {
    if (arguments.size() != 2) {
        std::cout << "Error : missing or too many arguments" << std::endl;
        std::cout << "Usage : edgeAdd \"from\" \"to\"" << std::endl;
        return -1;
    }

    config.getDataStructure()->addEdge(arguments[0], arguments[1]);
    return 0;
}
