/**
 * @file Prompt.h
 * @author Robin Donnay
 * @date 20/06/18
 * @brief Class test for MVK Wrapper with user interaction
 */

#ifndef FIRSTWRAPPER_PROMPT_H
#define FIRSTWRAPPER_PROMPT_H


#include <MVKWrapper.h>


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


#endif //FIRSTWRAPPER_PROMPT_H
