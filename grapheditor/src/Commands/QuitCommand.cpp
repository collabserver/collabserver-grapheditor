#include "Commands/QuitCommand.h"
#include "utils.h"

QuitCommand::QuitCommand(Editor * editor)
    : Command("quit", "Quit the editor", "Name :\n\tquit - Quit the editor.\nUsage :\n\tquit")
    {
        this->editor = editor;
    }

int QuitCommand::exec(utils::config config, const std::vector<std::string> &arguments)
{
    this->editor->stopRunning();    
    return 0;
}