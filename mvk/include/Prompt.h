#pragma once

#include "MVKWrapper.h"


/**
 * A simple command line prompt to manage MVK database.
 */
class Prompt {
    private:
        MVKWrapper _mvk = MVKWrapper(true); // Debug mode

    public:

        /**
         * Start and run this prompt.
         */
        void runPrompt();

    private:

        /**
         * Show connection / login menu.
         */
        void menuConnect();

        /**
         * Show megamodeling menu mode.
         * (Working on the MVK database globally).
         */
        void menuMegaModelingMode();

        /**
         * Show modeling menu mode.
         * (Working on a specific model in MVK).
         */
        void menuModelingMode();
};


