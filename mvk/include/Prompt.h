#pragma once

#include "MVKWrapper.h"


class Prompt {
    private:
        MVKWrapper _mvk = MVKWrapper(true); // Debug mode

    public:
        /** Launch the prompt. */
        void runPrompt();

    private:
        /** The connection part of Modelverse. */
        void menuConnect();

        /** The megamodeling part of Modelverse. */
        void enterMegaModellingMode();

        /** The modeling part of Modelverse. */
        void enterModellingMode();
};


