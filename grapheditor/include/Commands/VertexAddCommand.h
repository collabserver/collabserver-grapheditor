/**
 * @brief 
 * 
 * @file VertexAddCommand.h
 * @author (The Intern)
 * @date 2018-06-27
 */
#include "Command.h"

class VertexAddCommand : public Command {  
    private:
    

    public: 
    VertexAddCommand();
    int exec(utils::config config, const std::vector<std::string> &arguments);
};