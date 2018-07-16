/**
 * @brief 
 * 
 * @file VertexRemoveCommand.h
 * @author (The Intern)
 * @date 2018-06-27
 */
#include "Command.h"

class VertexRemoveCommand : public Command {  
    private:
    

    public: 
    VertexRemoveCommand();
    int exec(utils::config config, const std::vector<std::string> &arguments);
};