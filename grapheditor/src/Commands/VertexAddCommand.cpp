#include "Commands/VertexAddCommand.h"

#include "collabdata/custom/SimpleGraph.h"


int VertexAddCommand::exec(utils::config config, const std::vector<std::string> &arguments) {
    if (arguments.size() != 1) {
        std::cout << "Error : missing or too many arguments" << std::endl;
        std::cout << "Usage : vertexAdd \"vertex\"" << std::endl;
        return -1;
    }
    config.getDataStructure()->addVertex(arguments[0]);
    return 0;
}
