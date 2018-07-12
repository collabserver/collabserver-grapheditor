#include "Commands/EdgeAddCommand.h"
#include "collabdata/custom/SimpleGraph.h"

EdgeAddCommand::EdgeAddCommand()
    : Command("edgeAdd", "this is the edge add command", "Est labore deserunt ea in quis est duis adipisicing sint aute aute commodo Lorem est. Consectetur anim esse ullamco velit magna veniam ad. Reprehenderit ad ullamco exercitation consequat sunt eu exercitation aliquip est enim."){};

int EdgeAddCommand::exec(utils::config config, std::vector<std::string> arguments)
{
    //@TODO
    if (arguments.size() != 2)
    {
        std::cout << "Error : missing or too many arguments" << std::endl;
        std::cout << "Usage : edgeAdd \"from\" \"to\"" << std::endl;
        return -1;
    }
    config.getDataStructure().addEdge(arguments[0], arguments[1]);
    //std::cout << "Edge Added" << std::endl;
    return 0;
}