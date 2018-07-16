#include "Commands/VertexEditCommand.h"

VertexEditCommand::VertexEditCommand()
    : Command("vertexEdit", "this is the edit vertex command", "Velit labore enim duis in eiusmod irure irure voluptate qui tempor et ea. Elit ut occaecat sunt nisi commodo magna aliqua veniam. Laborum fugiat esse nostrud voluptate. Sunt minim laboris exercitation cillum ipsum proident consequat elit Lorem. Ex culpa incididunt laborum nulla id quis ad do elit fugiat do."){};


int VertexEditCommand::exec(utils::config config, const std::vector<std::string> &arguments){    
    std::cout << "Vertex Edited" << std::endl;
    return 0;
}