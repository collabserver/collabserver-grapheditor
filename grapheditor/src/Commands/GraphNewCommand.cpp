#include "Commands/GraphNewCommand.h"

GraphNewCommand::GraphNewCommand()
    : Command("graphNew", "this is the new graph command", "Laborum amet reprehenderit in aute minim ex dolor qui aute dolore non esse ad. Excepteur est fugiat laboris consequat. Non reprehenderit et cupidatat ut amet et sunt do sunt id dolor incididunt culpa. Lorem culpa sint irure ea tempor reprehenderit mollit dolore. Exercitation irure officia dolor exercitation Lorem."){};


int GraphNewCommand::exec(utils::config config, const std::vector<std::string> &arguments){
    std::string graphName;
    std::cout << "Graph name (must be unique) :";
    std::cin >> graphName;

    // create the graph
    std::cout << "Graph " << graphName << " created." << std::endl;

    //Open the graph

    return 0;
}