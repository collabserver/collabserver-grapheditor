#include "Commands/GraphDeleteCommand.h"

GraphDeleteCommand::GraphDeleteCommand()
    : Command("graphDelete", "this is the delete graph command", "Labore esse enim eu labore ea pariatur magna reprehenderit. Id ex est anim ad proident. Occaecat quis culpa dolor anim consequat cillum quis cillum est dolore ipsum. Ea est id voluptate fugiat non sunt anim aute ad eu et mollit irure nisi."){};


int GraphDeleteCommand::exec(utils::config config, const std::vector<std::string> &arguments){
    //@TODO
    std::cout << "Graph Deleted" << std::endl;
    return 0;
}