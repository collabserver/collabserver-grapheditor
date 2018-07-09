/**
 * @brief 
 * 
 * @file AttributeAdd.h
 * @author (The Intern)
 * @date 2018-07-03
 */
#include "Command.h"

class AttributeAdd : public Command
{
  private:
  public:
    AttributeAdd();
    int exec(utils::config config, std::vector<std::string> arguments);
};