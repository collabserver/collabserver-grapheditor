#include "Commands/EdgeRemoveCommand.h"

EdgeRemoveCommand::EdgeRemoveCommand()
    : Command("edgeRemove", "this is the edge remove command", "Est labore deserunt ea in quis est duis adipisicing sint aute aute commodo Lorem est. Consectetur anim esse ullamco velit magna veniam ad. Reprehenderit ad ullamco exercitation consequat sunt eu exercitation aliquip est enim."){}; 


int EdgeRemoveCommand::exec(utils::config config, std::vector<std::string> arguments){
    //@TODO
    std::cout << "Edge removed" << std::endl;
    return 0;
}