/**
 * @brief 
 * 
 * @file VertexInfoCommand.h
 * @author (The Intern)
 * @date 2018-06-27
 */
#include "Command.h"

class VertexInfoCommand : public Command {  
    private:
    

    public: 
    VertexInfoCommand();
    int exec(utils::config config, const std::vector<std::string> &arguments);
};