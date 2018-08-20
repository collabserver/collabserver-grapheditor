#include "Commands/VertexEditCommand.h"

VertexEditCommand::VertexEditCommand()
    : Command("vertexEdit",
              "this is the edit vertex command",
              "TODO"){
};

int VertexEditCommand::exec(utils::config config, const std::vector<std::string> &arguments){
    std::cout << "Vertex Edited" << std::endl;
    return 0;
}
