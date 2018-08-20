#include "Commands/AttributeCommands.h"

#include "collabdata/custom/SimpleGraph.h"


int AttributeAdd::exec(utils::config config,
                       const std::vector<std::string> &arguments) {
    if (arguments.size() != 3) {
        std::cout << "Error: invalid arguments" << std::endl;
        //std::cout << getUsage() << "\n"; // TODO
        return -1;
    }

    config.getDataStructure()->addAttribute(arguments[0],
                                            arguments[1],
                                            arguments[2]);
    return 0;
}

int AttributeRemove::exec(utils::config config,
                          const std::vector<std::string> &arguments) {
    if (arguments.size() != 2) {
        std::cout << "Error : missing or too many arguments" << std::endl;
        std::cout << "Usage : attributeRemove \"vertex\" \"name\"" << std::endl;
        return -1;
    }

    config.getDataStructure()->removeAttribute(arguments[0], arguments[1]);
    return 0;
}

int AttributeSet::exec(utils::config config,
                       const std::vector<std::string> &arguments) {
    if (arguments.size() != 3) {
        std::cout << "Error : missing or too many arguments" << std::endl;
        std::cout << "Usage : attributeRemove \"vertex\" \"name\" \"value\"" << std::endl;
        return -1;
    }

    config.getDataStructure()->setAttribute(arguments[0],
                                            arguments[1],
                                            arguments[2]);
    return 0;
}
