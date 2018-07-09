#include "Commands/GraphOpenCommand.h"

GraphOpenCommand::GraphOpenCommand()
    : Command("graphOpen", "this is the graph open command", "Aliquip magna qui amet do ex labore nostrud id elit consectetur. Irure incididunt aliquip anim nulla laborum voluptate pariatur enim et do aute incididunt officia commodo. Non minim minim labore culpa officia. Aliquip laborum consequat tempor ipsum ad tempor irure consectetur nulla nostrud incididunt Lorem laborum non."){};


int GraphOpenCommand::exec(utils::config config, std::vector<std::string> arguments){
    //@TODO
    std::cout << "Graph Openned" << std::endl;
    return 0;
}