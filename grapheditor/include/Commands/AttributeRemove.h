/**
 * @brief 
 * 
 * @file AttributeRemove.h
 * @author (The Intern)
 * @date 2018-07-03
 */
#include "Command.h"

class AttributeRemove : public Command
{
  private:
  public:
    AttributeRemove();
    int exec(utils::config config, std::vector<std::string> arguments);
};