/**
 * @brief 
 * 
 * @file GraphOpenCommand.h
 * @author (The Intern)
 * @date 2018-06-27
 */
#include "Command.h"

class GraphOpenCommand : public Command {  
    private:
    

    public: 
    GraphOpenCommand();
    int exec(utils::config config, std::vector<std::string> arguments);
};