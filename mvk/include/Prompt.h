//
// Created by robin on 20/06/18.
//

#ifndef FIRSTWRAPPER_PROMPT_H
#define FIRSTWRAPPER_PROMPT_H

#include <cstring>
#include <MVKWrapper.h>


class Prompt {

private:
    MVKWrapper database;

    void connection();

    void megaModelling();

    void modelling();

    std::string getUserAnswer();

public:
    void runPrompt();

};


#endif //FIRSTWRAPPER_PROMPT_H
