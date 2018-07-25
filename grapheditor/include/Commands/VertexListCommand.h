/**
 * @brief 
 * 
 * @file VertexListCommand.h
 * @author (The Intern)
 * @date 2018-06-27
 */
#include "Command.h"

class VertexListCommand : public Command {  
    private:
    

    public: 
    VertexListCommand();
    int exec(utils::config config, const std::vector<std::string> &arguments);
};