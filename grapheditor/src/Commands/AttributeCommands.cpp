#include "Commands/AttributeCommands.h"

#include "collabdata/custom/SimpleGraph.h"


int AttributeAdd::exec(utils::config config,
                       const std::vector<std::string> &args) {
    if (args.size() != 3) {
        std::cout << "ERROR: invalid arguments\n";
        std::cout << "USAGE: " << getUsage() << "\n";
        return -1;
    }

    config.getDataStructure()->addAttribute(args[0], args[1], args[2]);
    return 0;
}

int AttributeRemove::exec(utils::config config,
                          const std::vector<std::string> &args) {
    if (args.size() != 2) {
        std::cout << "ERROR: invalid arguments\n";
        std::cout << "USAGE: " << getUsage() << "\n";
        return -1;
    }

    config.getDataStructure()->removeAttribute(args[0], args[1]);
    return 0;
}

int AttributeSet::exec(utils::config config,
                       const std::vector<std::string> &args) {
    if (args.size() != 3) {
        std::cout << "ERROR: invalid arguments\n";
        std::cout << "USAGE: " << getUsage() << "\n";
        return -1;
    }

    config.getDataStructure()->setAttribute(args[0], args[1], args[2]);
    return 0;
}
