#include "Commands/EdgeRemoveCommand.h"

#include "collabdata/custom/SimpleGraph.h"


int EdgeRemoveCommand::exec(utils::config config, const std::vector<std::string> &arguments){
    if(arguments.size()!=2) {
        std::cout << "Error : missing or too many arguments" << std::endl;
        std::cout << "Usage : edgeRemove \"from\" \"to\"" << std::endl;
        return -1;
    }
    config.getDataStructure()->removeEdge(arguments[0], arguments[1]);
    return 0;
}
