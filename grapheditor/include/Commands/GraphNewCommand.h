/**
 * @brief 
 * 
 * @file GraphNewCommand.h
 * @author (The Intern)
 * @date 2018-06-27
 */
#include "Command.h"

class GraphNewCommand : public Command {  
    private:
    

    public: 
    GraphNewCommand();
    int exec(utils::config config, std::vector<std::string> arguments);
};