#include "Commands/VertexAddCommand.h"
#include "collabdata/custom/SimpleGraph.h"

VertexAddCommand::VertexAddCommand()
    : Command("vertexAdd", "this is the new graph command", "Dolor do ut sint sint minim id officia amet velit id ea officia. Ex qui incididunt laborum eiusmod incididunt ipsum dolore velit minim. Nostrud voluptate est velit sint ut. Nisi officia excepteur consectetur laborum velit ea occaecat excepteur culpa do fugiat. Incididunt quis adipisicing dolor ex enim fugiat et ex. Deserunt nostrud occaecat tempor amet est mollit irure nulla consectetur."){};

int VertexAddCommand::exec(utils::config config, std::vector<std::string> arguments)
{
    //@TODO
    if (arguments.size() != 1)
    {
        std::cout << "Error : missing or too many arguments" << std::endl;
        std::cout << "Usage : vertexAdd \"vertex\"" << std::endl;
        return -1;
    }
    config.getDataStructure().addVertex(arguments[0]);
    //cout << "Vertex added" << std::endl;
    return 0;
}