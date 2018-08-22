#include <csignal>
#include <iostream>
#include <stdexcept>

#include "Editor.h"


static Editor editor = Editor();

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
