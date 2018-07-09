#include "Commands/AttributeRemove.h"

AttributeRemove::AttributeRemove()
    : Command("attributeRemove", "this is the remove attribute command", "Est labore deserunt ea in quis est duis adipisicing sint aute aute commodo Lorem est. Consectetur anim esse ullamco velit magna veniam ad. Reprehenderit ad ullamco exercitation consequat sunt eu exercitation aliquip est enim."){}; 


int AttributeRemove::exec(utils::config config, std::vector<std::string> arguments){
    //@TODO
    std::cout << "Attribute removed" << std::endl;
    return 0;
}