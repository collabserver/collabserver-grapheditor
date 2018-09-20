#include <cstring>
#include <cstdlib>
#include <iostream>

#include "MVKGlobal.h"


static void usage() {
    std::cout << "USAGE: mvk_poc IP_SERVER PORT_SERVER IP_MVK PORT_MVK MODEL\n";
    std::cout << "       mvk_poc MODEL (Use default ip/port values)";
    std::cout << std::endl;
}

static bool connectCollabServer(const char* ip, const int port) {
    std::cout << "Connecting to CollabServer (" << ip << ":" << port << ")... ";
    bool success = MVKGlobal::get().collabclient().connect(ip, port);
    if(!success) {
        std::cout << "FAILED\n";
        std::cout << "Unable to establish connection with CollabServer";
        std::cout << std::endl;
        return false;
    }
    std::cout << "SUCCESS\n";
    std::cout << "Successfully connected to CollabServer";
    std::cout << std::endl;
    return true;
}

static bool connectMVK(const char* ip, const int port) {
    std::cout << "Connecting to Mvk Database (" << ip << ":" << port << ")... ";

    int error = MVKGlobal::get().mvkWrapper().connect(ip, port, "admin", "admin");
    if(error != 0) {
        std::cout << "FAILED\n";
        std::cout << "Unable to establish connection with Mvk database";
        std::cout << std::endl;
        return false;
    }
    std::cout << "SUCCESS\n";
    std::cout << "Successfully connected to Mvk Database";
    std::cout << std::endl;
    return true;

}

int main(int argc, char** argv) {
    // Default values
    const char* collab_ip   = "localhost";
    int collab_port         = 4242;
    const char* mvk_ip      = "localhost";
    int mvk_port            = 8001;
    const char* modelName   = "default";

    if(argc == 2) {
        modelName = argv[2];
    }
    else if(argc == 6) {
        collab_ip       = argv[1];
        collab_port     = atoi(argv[2]);
        mvk_ip          = argv[3];
        mvk_port        = atoi(argv[4]);
        modelName       = argv[5];
    }
    else {
        usage();
        return EXIT_FAILURE;
    }

    connectCollabServer(collab_ip, collab_port);
    connectMVK(mvk_ip, mvk_port);

    return EXIT_SUCCESS;
}

