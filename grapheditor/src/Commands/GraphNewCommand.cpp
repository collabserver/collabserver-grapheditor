#include "Commands/GraphNewCommand.h"


GraphNewCommand::GraphNewCommand()
    : Command("graphNew",
              "This is the new graph command",
              "TODO"){
};

int GraphNewCommand::exec(utils::config config, const std::vector<std::string> &arguments){
    std::string graphName;
    std::cout << "Graph name (must be unique) :";
    std::cin >> graphName;

    std::cout << "Graph " << graphName << " created." << std::endl;

    return 0;
}
