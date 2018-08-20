#include "Commands/ConnectCommand.h"
#include <regex>
#include "utils.h"

ConnectCommand::ConnectCommand()
    : Command("connect",
              "Connect the client to the specified server.",
              "Name :\n\tconnect - Connect the client to the specified server\nUsage :\n\tconnect [ip] [port]") {
    this->editor = editor;
}

int ConnectCommand::exec(utils::config config, const std::vector<std::string> &arguments) {
    if (arguments.size() != 2) {
        std::cout << "Error : missing or too many arguments" << std::endl;
        std::cout << "Usage : connect \"ip\" \"port\"" << std::endl;
        return -1;
    }
    std::regex reg("^([01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])\\.([01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])\\.([01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])\\.([01]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])$");

    if (!std::regex_match(arguments[0], reg)) {
        std::cout << "Error : invalid IP address" << std::endl;
        return -4;
    }

    int port = atoi(arguments[1].c_str());
    if (port == 0) {
        std::cout << "Error : invalid port number" << std::endl;
        return -5;
    }

    //TODO use the simplegraph connect
    std::cout << "Connecting to " << arguments[0] /*Adresse IP*/<< ":" << port << " ..." << std::endl;
    return 0;
}
