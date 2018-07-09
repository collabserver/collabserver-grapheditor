/**
 * @brief 
 * 
 * @file AttributeSet.h
 * @author (The Intern)
 * @date 2018-07-03
 */
#include "Command.h"

class AttributeSet : public Command
{
  private:
  public:
    AttributeSet();
    int exec(utils::config config, std::vector<std::string> arguments);
};
