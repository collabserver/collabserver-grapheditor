#include "Commands/GraphOpenCommand.h"

GraphOpenCommand::GraphOpenCommand()
    : Command("graphOpen",
              "this is the graph open command",
              "TODO"){
};

int GraphOpenCommand::exec(utils::config config, const std::vector<std::string> &arguments){
    //TODO To implement
    std::cout << "Graph Openned (Not implemented yet)\n";
    return 0;
}
