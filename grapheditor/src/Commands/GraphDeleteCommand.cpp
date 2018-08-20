#include "Commands/GraphDeleteCommand.h"

GraphDeleteCommand::GraphDeleteCommand()
    : Command("graphDelete",
              "this is the delete graph command",
              "TODO"){
};


int GraphDeleteCommand::exec(utils::config config, const std::vector<std::string> &arguments){
    //TODO
    std::cout << "Graph Deleted (Not implemented yet)" << std::endl;
    return 0;
}
