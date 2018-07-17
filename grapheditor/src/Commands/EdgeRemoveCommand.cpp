#include "Commands/EdgeRemoveCommand.h"
#include "collabdata/custom/SimpleGraph.h"

EdgeRemoveCommand::EdgeRemoveCommand()
    : Command("edgeRemove", "Remove the edge between two vertexes", "Name :\n\tedgeRemove - Remove the edge between a source vertex and a destination vertex.\nUsage :\n\tedgeRemove [vertex source id] [vertex destination id]"){}; 


int EdgeRemoveCommand::exec(utils::config config, const std::vector<std::string> &arguments){
    
    if(arguments.size()!=2){
        std::cout << "Error : missing or too many arguments" << std::endl;
        std::cout << "Usage : edgeRemove \"from\" \"to\"" << std::endl;
        return -1;
    }
    config.getDataStructure()->removeEdge(arguments[0], arguments[1]);
    //std::cout << "Edge removed" << std::endl;
    return 0;
}