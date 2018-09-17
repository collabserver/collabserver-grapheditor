#pragma once

#include "MVKWrapper.h"


class Prompt {
    private:
        MVKWrapper database;


    private:

        /** The connection part of Modelverse. */
        void connection();

        /** The megamodeling part of Modelverse. */
        void megaModelling();

        /** The modeling part of Modelverse. */
        void modelling();

        /**
         * Get what the user type and return it.
         *
         * \return The answer of the user
         */
        std::string getUserAnswer();

    public:
        /** Launch the prompt. */
        void runPrompt();
};


