/**
 * @brief 
 * 
 * @file main.cc
 * @author (The Intern)
 * @date 2018-06-26
 */

#include <cstdlib>
#include "Editor.h"
int main(int argc, char const *argv[])
{
    Editor editor = Editor();    
    return editor.startRunning();
}