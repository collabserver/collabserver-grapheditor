#include <csignal>
#include <iostream>
#include <string>
#include <stdexcept>

#include "Global.h"


static Editor& editor = Global::get().editor(); // Just an alias kind of

static void handleInterrupt(int sig) {
    std::cout << "SIGINT received\n";
    std::cout << "Are you sure you want to leave? [quit/no]:\n";
}

int main(int argc, char **argv) {
    signal(SIGINT, &handleInterrupt);

    try {
        editor.start();
    }
    catch(const std::exception& e) {
        editor.stop();
        std::cerr << "Crashed with exception: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    catch(...) {
        editor.stop();
        std::cerr << "Crashed with unknown exception: " << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
