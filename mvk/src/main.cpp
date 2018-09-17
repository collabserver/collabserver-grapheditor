#include <cstdlib>
#include <iostream>

#include <collabdata/custom/SimpleGraph.h>

#include "MVKGlobal.h"


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


void usage() {
    std::cout << "USAGE: mvk_poc IP_SERVER PORT_SERVER IP_MVK PORT_MVK MODEL\n";
}

int main(int argc, char** argv) {
    if(argc != 6) {
        usage();
        return EXIT_FAILURE;
    }

    const char* collab_ip = argv[1];
    const int collab_port = atoi(argv[2]);
    const char* mvk_ip = argv[3];
    const int mvk_port = atoi(argv[4]);
    const char* modelName = argv[5];


    // CollabServer
    std::cout << "Connecting to CollabServer ("
              << collab_ip << ":" << collab_port << ")... "
              << std::endl;
    bool success = MVKGlobal::get().collabclient().connect(collab_ip, collab_port);
    if(!success) {
        std::cout << "FAILED\n";
        std::cout << "Unable to establish connection with CollabServer\n";
        return -1;
    }
    std::cout << "SUCCESS\n";
    std::cout << "Successfully connected to CollabServer\n";


    // Mvk
    std::cout << "Connecting to Mvk Database ("
              << mvk_ip << ":" << mvk_port << ")... "
              << std::endl;
    // TODO
    //success = MVKGlobal::get().mvkWrapper().connect();
    success = false; //TODO TMP
    if(!success) {
        std::cout << "FAILED\n";
        std::cout << "Unable to establish connection with Mvk database\n";
        return -1;
    }
    std::cout << "SUCCESS\n";
    std::cout << "Successfully connected to Mvk Database\n";

    return EXIT_SUCCESS;
}

