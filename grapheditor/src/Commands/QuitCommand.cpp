#include "Commands/QuitCommand.h"
#include "utils.h"

QuitCommand::QuitCommand(Editor * editor)
    : Command("quit", "This is the quit command", "Qui quis velit velit cupidatat ipsum culpa. Veniam consequat deserunt nostrud qui est. Irure esse eu adipisicing duis amet incididunt. Laborum cupidatat do ex voluptate cupidatat anim irure sint Lorem.")
    {
        this->editor = editor;
    }

int QuitCommand::exec(utils::config config, std::vector<std::string> arguments)
{
    this->editor->stopRunning();    
    return 0;
}