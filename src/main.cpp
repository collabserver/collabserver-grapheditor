#include <csignal>
#include <iostream>
#include <stdexcept>
#include <string>

#include "Global.h"

static void handleInterrupt(int sig) {
    std::cout << "SIGINT received\n";
    std::cout << "Are you sure you want to leave? [quit/no]: ";
}

int main(int argc, char** argv) {
    signal(SIGINT, &handleInterrupt);

    try {
        Global::get().editor().start();
    } catch (const std::exception& e) {
        Global::get().editor().stop();
        std::cerr << "Crashed with exception: " << e.what() << std::endl;
        return EXIT_FAILURE;
    } catch (...) {
        Global::get().editor().stop();
        std::cerr << "Crashed with unknown exception: " << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
