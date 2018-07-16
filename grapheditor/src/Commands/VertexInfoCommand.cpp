#include "Commands/VertexInfoCommand.h"

VertexInfoCommand::VertexInfoCommand()
    : Command("vertexInfo", "Display the information about the specified vertex", "Name :\n\tvertexInfo - Display the information about the specified vertex.\nUsage :\n\tvertexAdd [vertex id]"){};


int VertexInfoCommand::exec(utils::config config, const std::vector<std::string> &arguments){
    //@TODO
    std::cout << "Vertex :" << std::endl;
    return 0;
}