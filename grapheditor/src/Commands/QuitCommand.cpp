#include "Commands/QuitCommand.h"

#include "utils.h"


QuitCommand::QuitCommand(const CommandInfo& info, Editor* editor)
  : Command(info) {
        this->editor = editor;
    }

int QuitCommand::exec(utils::config config, const std::vector<std::string> &arguments) {
    this->editor->stop();
    return 0;
}
