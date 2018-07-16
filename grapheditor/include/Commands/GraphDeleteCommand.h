/**
 * @brief 
 * 
 * @file GraphDeleteCommand.h
 * @author (The Intern)
 * @date 2018-06-27
 */
#include "Command.h"

class GraphDeleteCommand : public Command {  
    private:
    

    public: 
    GraphDeleteCommand();
    int exec(utils::config config, const std::vector<std::string> &arguments);
};