#include "Commands/GraphDisplayCommand.h"

GraphDisplayCommand::GraphDisplayCommand()
    : Command("graphDisplay", "this is the display graph command", "Labore esse enim eu labore ea pariatur magna reprehenderit. Id ex est anim ad proident. Occaecat quis culpa dolor anim consequat cillum quis cillum est dolore ipsum. Ea est id voluptate fugiat non sunt anim aute ad eu et mollit irure nisi."){};


int GraphDisplayCommand::exec(utils::config config, std::vector<std::string> arguments){
    //@TODO
    std::cout << "Graph : " << std::endl << std::endl;
    return 0;
}