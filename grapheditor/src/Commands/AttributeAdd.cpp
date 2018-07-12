#include "Commands/AttributeAdd.h"
#include "collabdata/custom/SimpleGraph.h"

AttributeAdd::AttributeAdd()
    : Command("attributeAdd", "this is the add attribute command", "Est labore deserunt ea in quis est duis adipisicing sint aute aute commodo Lorem est. Consectetur anim esse ullamco velit magna veniam ad. Reprehenderit ad ullamco exercitation consequat sunt eu exercitation aliquip est enim."){};

int AttributeAdd::exec(utils::config config, std::vector<std::string> arguments)
{
    //@TODO
    if (arguments.size() != 3)
    {
        std::cout << "Error : missing or too many arguments" << std::endl;
        std::cout << "Usage : attributeAdd \"vertex\" \"name\" \"value\"" << std::endl;
        return -1;
    }
    config.getDataStructure().addAttribute(arguments[0], arguments[1], arguments[2]);
    //std::cout << "Attribute Added" << std::endl;
    return 0;
}