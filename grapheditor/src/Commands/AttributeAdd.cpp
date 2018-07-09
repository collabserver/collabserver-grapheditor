#include "Commands/AttributeAdd.h"

AttributeAdd::AttributeAdd()
    : Command("attributeAdd", "this is the add attribute command", "Est labore deserunt ea in quis est duis adipisicing sint aute aute commodo Lorem est. Consectetur anim esse ullamco velit magna veniam ad. Reprehenderit ad ullamco exercitation consequat sunt eu exercitation aliquip est enim."){}; 


int AttributeAdd::exec(utils::config config, std::vector<std::string> arguments){
    //@TODO
    std::cout << "Attribute Added" << std::endl;
    return 0;
}