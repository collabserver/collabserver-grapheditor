#include <iostream>

#include <collabdata/custom/SimpleGraph.h>

#include "Global.h"
#include "MVKWrapper.h"
#include "Prompt.h"
#include "MVKSimpleGraphOperationHandler.h"
#include "DatabaseSimpleGraphOperationHandler.h"
#include "DatabaseObserver.h"


/*
 * TODO TMP to cleanup
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
*/

int main() {
    std::cout << "Début du Programme !" << std::endl;
    //testSimpleGraphOperation();

    std::cout << "Fin du Programme !\n";
    return 0;
}
