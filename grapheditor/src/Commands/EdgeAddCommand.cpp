#include "Commands/EdgeAddCommand.h"

EdgeAddCommand::EdgeAddCommand()
    : Command("edgeAdd", "this is the edge add command", "Est labore deserunt ea in quis est duis adipisicing sint aute aute commodo Lorem est. Consectetur anim esse ullamco velit magna veniam ad. Reprehenderit ad ullamco exercitation consequat sunt eu exercitation aliquip est enim."){}; 


int EdgeAddCommand::exec(utils::config config, std::vector<std::string> arguments){
    //@TODO
    std::cout << "Edge Added" << std::endl;
    return 0;
}