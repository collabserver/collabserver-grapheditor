#include "Commands/EdgeAddCommand.h"
#include "collabdata/custom/SimpleGraph.h"

EdgeAddCommand::EdgeAddCommand()
    : Command("edgeAdd", "Add an oriented edge between two vertexes", "Name :\n\tedgeAdd - Add an edge between a source vertex and a destination vertex.\nUsage :\n\tedgeAdd [vertex source id] [vertex destination id]"){};

int EdgeAddCommand::exec(utils::config config, const std::vector<std::string> &arguments)
{
    if (arguments.size() != 2)
    {
        std::cout << "Error : missing or too many arguments" << std::endl;
        std::cout << "Usage : edgeAdd \"from\" \"to\"" << std::endl;
        return -1;
    }
    config.getDataStructure().addEdge(arguments[0], arguments[1]);
    return 0;
}