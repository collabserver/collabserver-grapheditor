#include <iostream>
#include <collabdata/custom/SimpleGraph.h>

#include "../include/MVKWrapper.h"
#include "../include/Prompt.h"
#include "../include/MVKSimpleGraphOperationHandler.h"
#include "../include/DatabaseSimpleGraphOperationHandler.h"
#include "../include/DatabaseObserver.h"

void testSimpleGraphOperation() {
    MVKSimpleGraphOperationHandler opHandler;
    DatabaseObserver *observer = new DatabaseObserver(&opHandler);
    collab::SimpleGraph graph = collab::SimpleGraph::build(42); // Dummy ID
    graph.addOperationObserver(*observer);

    graph.addVertex("v1");
    graph.addVertex("v2");
    graph.addEdge("v1", "v2");
    graph.addAttribute("v1", "Ville", "Lyon");
    graph.addAttribute("v1", "Quartier1", "Monplaisir");
    graph.addAttribute("v1", "Quartier2", "GrangeBlanche");
    graph.addAttribute("v2", "Ville", "Paris");
    graph.removeAttribute("v1", "Quartier2");
    graph.setAttribute("v2", "Ville", "Marseille");

};

int main() {
    std::cout << "Début du Programme !" << std::endl;
    //MVKWrapper::unitTest();

    testSimpleGraphOperation();

    std::cout << "Fin du Programme !\n";
    return 0;
}
