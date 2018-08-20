#include "Commands/AttributeAdd.h"

#include "collabdata/custom/SimpleGraph.h"


int AttributeAdd::exec(utils::config config, const std::vector<std::string> &arguments) {
    if (arguments.size() != 3) {
        std::cout << "Error: invalid arguments" << std::endl;
        //std::cout << getUsage() << "\n";
        return -1;
    }
    config.getDataStructure()->addAttribute(arguments[0], arguments[1], arguments[2]);
    return 0;
}
