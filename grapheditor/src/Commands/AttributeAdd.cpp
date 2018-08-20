#include "Commands/AttributeAdd.h"

#include "collabdata/custom/SimpleGraph.h"


AttributeAdd::AttributeAdd()
    : Command("attributeAdd",
              "Add an attribute and its value to a vertex",
              "Name :\n\tattributeAdd - Add an attribute and its value to a vertex.\nUsage :\n\tattributeAdd [vertex id] [attribute name] [attribute value]"){
};

int AttributeAdd::exec(utils::config config, const std::vector<std::string> &arguments) {
    if (arguments.size() != 3) {
        std::cout << "Error: invalid arguments" << std::endl;
        std::cout << "Usage: attributeAdd \"vertex\" \"name\" \"value\"" << std::endl;
        return -1;
    }
    config.getDataStructure()->addAttribute(arguments[0], arguments[1], arguments[2]);
    return 0;
}
