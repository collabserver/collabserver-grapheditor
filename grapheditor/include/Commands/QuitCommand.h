/**
 * @brief 
 * 
 * @file QuitCommand.h
 * @author (The Intern)
 * @date 2018-06-28
 */
#include "Command.h"
#include <iostream>
#include "Editor.h"


class QuitCommand : public Command {
    private:
    Editor * editor;

    public:
    QuitCommand(Editor * editor);
    int exec(utils::config config, const std::vector<std::string> &arguments);

};