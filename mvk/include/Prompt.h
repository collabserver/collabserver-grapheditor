/**
 * @brief Class test for MVK Wrapper with user interaction
 */

#ifndef MVK_PROMPT_H
#define MVK_PROMPT_H


#include "../include/MVKWrapper.h"


class Prompt {

private:
    /** @brief the wrapper for the communication with Modelverse*/
    MVKWrapper database;

    /** @brief the connection part of Modelverse */
    void connection();

    /** @brief the megamodeling part of Modelverse */
    void megaModelling();

    /** @brief the modeling part of Modelverse */
    void modelling();

    /**
     * @brief get what the user type and return it
     * @return the answer of the user
     */
    std::string getUserAnswer();

public:
    /** @brief launch the prompt*/
    void runPrompt();

};


#endif //MVK_PROMPT_H
