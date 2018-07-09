#include "Commands/VertexRemoveCommand.h"

VertexRemoveCommand::VertexRemoveCommand()
    : Command("removeVertex", "this is the remove vertex command", "Pariatur tempor aute tempor eiusmod sit enim excepteur eu ullamco commodo exercitation est. Ipsum velit voluptate commodo laboris tempor nulla ad excepteur sunt et dolore ex laboris. Veniam do laboris mollit elit ipsum elit magna deserunt ad dolor duis officia tempor nisi. Mollit reprehenderit ea Lorem ut mollit labore pariatur aliquip quis tempor magna. Irure nisi occaecat labore ea id mollit enim aliqua amet non ipsum laboris dolore esse. Sunt nisi anim pariatur non sit anim veniam enim quis ea."){};


int VertexRemoveCommand::exec(utils::config config, std::vector<std::string> arguments){
    //@TODO
    std::cout << "Vertex removed" << std::endl;
    return 0;
}