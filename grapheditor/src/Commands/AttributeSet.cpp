#include "Commands/AttributeSet.h"

#include "collabdata/custom/SimpleGraph.h"


int AttributeSet::exec(utils::config config, const std::vector<std::string> &arguments) {
    if (arguments.size() != 3) {
        std::cout << "Error : missing or too many arguments" << std::endl;
        std::cout << "Usage : attributeRemove \"vertex\" \"name\" \"value\"" << std::endl;
        return -1;
    }
    config.getDataStructure()->setAttribute(arguments[0], arguments[1], arguments[2]);
    return 0;
}
