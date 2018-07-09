#include "Commands/VertexInfoCommand.h"

VertexInfoCommand::VertexInfoCommand()
    : Command("vertexInfo", "this is the info vertex command", "Adipisicing enim nulla laboris aliquip cillum. Exercitation enim adipisicing sunt duis ut nostrud consectetur sit ut aute ullamco. Exercitation consequat et eu esse anim est excepteur dolor ex voluptate proident laborum sit. Sit consectetur ex adipisicing consequat duis anim. Est ad reprehenderit nostrud id enim eu consectetur sit laboris sit cupidatat irure cillum."){};


int VertexInfoCommand::exec(utils::config config, std::vector<std::string> arguments){
    //@TODO
    std::cout << "Vertex :" << std::endl;
    return 0;
}