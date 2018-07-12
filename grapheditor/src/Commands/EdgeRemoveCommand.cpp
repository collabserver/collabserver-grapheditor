#include "Commands/EdgeRemoveCommand.h"
#include "collabdata/custom/SimpleGraph.h"

EdgeRemoveCommand::EdgeRemoveCommand()
    : Command("edgeRemove", "this is the edge remove command", "Est labore deserunt ea in quis est duis adipisicing sint aute aute commodo Lorem est. Consectetur anim esse ullamco velit magna veniam ad. Reprehenderit ad ullamco exercitation consequat sunt eu exercitation aliquip est enim."){}; 


int EdgeRemoveCommand::exec(utils::config config, std::vector<std::string> arguments){
    
    if(arguments.size()!=2){
        std::cout << "Error : missing or too many arguments" << std::endl;
        std::cout << "Usage : edgeRemove \"from\" \"to\"" << std::endl;
        return -1;
    }
    config.getDataStructure().removeEdge(arguments[0], arguments[1]);
    //std::cout << "Edge removed" << std::endl;
    return 0;
}