/**
 * @brief The Editor class that manage le lifeCycle of the program
 * 
 * @file Editor.h
 * @author (The Intern)
 * @date 2018-07-05
 */
#ifndef EDITOR_H
#define EDITOR_H

#include <map>
#include <string>
#include "Commands/Command.h"


class Editor
{
  private:
    bool running;
    /**
     * @brief List of all the commands available in the editor
     * 
     */
    std::map<std::string, Command *> commands;

  public:
    Editor();
    int startRunning();
    int stopRunning();

    ~Editor();
};

#endif
