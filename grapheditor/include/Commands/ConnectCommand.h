/**
 * @brief 
 * 
 * @file ConnectCommand.h
 * @author (The Intern)
 * @date 2018-07-26
 */
#include "Command.h"
#include <iostream>
#include "Editor.h"


class ConnectCommand : public Command {
    private:
    Editor * editor;

    public:
    ConnectCommand();
    int exec(utils::config config, const std::vector<std::string> &arguments);

};