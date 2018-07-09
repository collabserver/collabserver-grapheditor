#include "Commands/GraphCloseCommand.h"

GraphCloseCommand::GraphCloseCommand()
    : Command("graphClose", "this is the close graph command", "Esse eiusmod ipsum sint exercitation velit nulla id mollit officia. Fugiat dolor ad laborum est proident quis non. Fugiat quis culpa nostrud irure proident. Ipsum veniam ea in irure laborum anim enim ex tempor mollit eiusmod. Laborum ullamco aliquip minim minim et fugiat mollit consectetur cillum ad velit culpa. Consequat qui pariatur deserunt sint in."){};


int GraphCloseCommand::exec(utils::config config, std::vector<std::string> arguments){
    //@TODO
    std::cout << "Graph closed" << std::endl;
    return 0;
}