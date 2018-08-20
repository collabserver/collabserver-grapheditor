#include "Commands/VertexRemoveCommand.h"

#include "collabdata/custom/SimpleGraph.h"


VertexRemoveCommand::VertexRemoveCommand()
    : Command("vertexRemove",
              "Remove a vertex from the graph",
              "Name :\n\tvertexRemove - Add a new vertex to the graph.\nUsage :\n\tvertexRemove [vertex id]"){
};

int VertexRemoveCommand::exec(utils::config config, const std::vector<std::string> &arguments) {
    if (arguments.size() != 1) {
        std::cout << "Error : missing or too many arguments" << std::endl;
        std::cout << "Usage : vertexRemove \"vertex\"" << std::endl;
        return -1;
    }
    config.getDataStructure()->removeVertex(arguments[0]);
    return 0;
}
