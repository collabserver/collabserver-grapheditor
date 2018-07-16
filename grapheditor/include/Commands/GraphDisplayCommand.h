/**
 * @brief 
 * 
 * @file GraphDisplayCommand.h
 * @author (The Intern)
 * @date 2018-07-09
 */
#include "Command.h"

class GraphDisplayCommand : public Command {  
    private:
    

    public: 
    GraphDisplayCommand();
    int exec(utils::config config, const std::vector<std::string> &arguments);
};