/**
 * @brief 
 * 
 * @file GraphCloseCommand.h
 * @author (The Intern)
 * @date 2018-06-28
 */
#include "Command.h"
#include <iostream>


class GraphCloseCommand : public Command {
    private:

    public:
    GraphCloseCommand();
    int exec(utils::config config, std::vector<std::string> arguments);

};