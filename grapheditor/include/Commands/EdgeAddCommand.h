/**
 * @brief 
 * 
 * @file EdgeAddCommand.h
 * @author (The Intern)
 * @date 2018-06-29
 */

#include "Command.h"

class EdgeAddCommand : public Command
{
  private:
  public:
    EdgeAddCommand();
    int exec(utils::config config, const std::vector<std::string> &arguments);
};