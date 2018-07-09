#include "Commands/VertexAddCommand.h"

VertexAddCommand::VertexAddCommand()
    : Command("vertexAdd", "this is the new graph command", "Dolor do ut sint sint minim id officia amet velit id ea officia. Ex qui incididunt laborum eiusmod incididunt ipsum dolore velit minim. Nostrud voluptate est velit sint ut. Nisi officia excepteur consectetur laborum velit ea occaecat excepteur culpa do fugiat. Incididunt quis adipisicing dolor ex enim fugiat et ex. Deserunt nostrud occaecat tempor amet est mollit irure nulla consectetur."){};


int VertexAddCommand::exec(utils::config config, std::vector<std::string> parameters){
    //@TODO
    std::cout << "Vertex added" << std::endl;
    return 0;
}