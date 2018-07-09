/**
 * @brief 
 * 
 * @file GraphListCommand.h
 * @author (The Intern)
 * @date 2018-06-27
 */
#include "Command.h"

class GraphListCommand : public Command {  
    private:
    

    public: 
    GraphListCommand();
    int exec(utils::config config, std::vector<std::string> arguments);
};