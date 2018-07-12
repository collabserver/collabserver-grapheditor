#include "Commands/AttributeRemove.h"
#include "collabdata/custom/SimpleGraph.h"

AttributeRemove::AttributeRemove()
    : Command("attributeRemove", "this is the remove attribute command", "Est labore deserunt ea in quis est duis adipisicing sint aute aute commodo Lorem est. Consectetur anim esse ullamco velit magna veniam ad. Reprehenderit ad ullamco exercitation consequat sunt eu exercitation aliquip est enim."){};

int AttributeRemove::exec(utils::config config, std::vector<std::string> arguments)
{
    //@TODO
    if (arguments.size() != 2)
    {
        std::cout << "Error : missing or too many arguments" << std::endl;
        std::cout << "Usage : attributeRemove \"vertex\" \"name\"" << std::endl;
        return -1;
    }
    config.getDataStructure().removeAttribute(arguments[0], arguments[1]);
    //std::cout << "Attribute removed" << std::endl;
    return 0;
}