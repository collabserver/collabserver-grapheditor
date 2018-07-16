/**
 * @brief 
 * 
 * @file EdgeRemoveCommand.h
 * @author (The Intern)
 * @date 2018-06-29
 */

#include "Command.h"

class EdgeRemoveCommand : public Command
{
  private:
  public:
    EdgeRemoveCommand();
    int exec(utils::config config, const std::vector<std::string> &arguments);
};