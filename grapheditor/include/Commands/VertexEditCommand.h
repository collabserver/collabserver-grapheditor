/**
 * @brief 
 * 
 * @file VertexEditCommand.h
 * @author (The Intern)
 * @date 2018-06-27
 */
#include "Command.h"

class VertexEditCommand : public Command {  
    private:
    

    public: 
    VertexEditCommand();
    int exec(utils::config config, std::vector<std::string> arguments);
};