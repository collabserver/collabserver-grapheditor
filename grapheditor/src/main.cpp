#include <csignal>
#include <iostream>
#include <stdexcept>

#include "Global.h"


static Editor& editor = Global::get().editor(); // Just an alias kind of

static void handleInterrupt(int i) {
    std::cerr << "SIGINT received. Closing program...\n";
    editor.stop();
    throw;
}

int main(int argc, char **argv) {
    //signal(SIGINT, &handleInterrupt); // TODO Fix core dump issue

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
