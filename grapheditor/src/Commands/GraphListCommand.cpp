#include "Commands/GraphListCommand.h"

GraphListCommand::GraphListCommand()
    : Command("graphList",
              "this is the list graph command",
              "TODO"){
};


int GraphListCommand::exec(utils::config config, const std::vector<std::string> &arguments){
    //TODO To implement
    std::cout << "GraphList: (Not implemented yet)\n";
    return 0;
}
