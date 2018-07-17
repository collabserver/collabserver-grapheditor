#include "Commands/AttributeRemove.h"
#include "collabdata/custom/SimpleGraph.h"

AttributeRemove::AttributeRemove()
    : Command("attributeRemove", "Remove an attribute from a vertex", "Name :\n\tattributeRemove - Remove an attribute from a vertex.\nUsage :\n\tattributeRemove [vertex id] [attribute name]"){};

int AttributeRemove::exec(utils::config config, const std::vector<std::string> &arguments)
{
    if (arguments.size() != 2)
    {
        std::cout << "Error : missing or too many arguments" << std::endl;
        std::cout << "Usage : attributeRemove \"vertex\" \"name\"" << std::endl;
        return -1;
    }
    config.getDataStructure()->removeAttribute(arguments[0], arguments[1]);
    return 0;
}