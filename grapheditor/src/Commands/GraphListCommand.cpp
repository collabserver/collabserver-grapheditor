#include "Commands/GraphListCommand.h"

GraphListCommand::GraphListCommand()
    : Command("graphList", "this is the list graph command", "Est labore deserunt ea in quis est duis adipisicing sint aute aute commodo Lorem est. Consectetur anim esse ullamco velit magna veniam ad. Reprehenderit ad ullamco exercitation consequat sunt eu exercitation aliquip est enim."){};


int GraphListCommand::exec(utils::config config, std::vector<std::string> arguments){
    //@TODO
    std::cout << "GraphList :" << std::endl;
    return 0;
}