#include "Commands/GraphCommands.h"

#include "Global.h"


// -----------------------------------------------------------------------------
// GraphShow
// -----------------------------------------------------------------------------

int GraphShowCommand::exec(const std::vector<std::string>& args) {
    if (args.size() != 0) {
        std::cout << "ERROR: invalid arguments\n";
        std::cout << "USAGE: " << getUsage() << "\n";
        return -1;
    }

    if(!Global::get().collabclient().isConnected()) {
        std::cout << "ERROR: You must be connected to a server first\n";
        std::cout << "HINT: See connect command\n";
        return -1;
    }

    if(!Global::get().collabclient().isDataLoaded()) {
        std::cout << "ERROR: No graph data loaded yet\n";
        return -1;
    }

    collab::SimpleGraph::VertexIterator it = Global::get().graphdata().vertices();
    while(it.moveNext()) {
        collab::SimpleGraph::VertexDescriptor vertex = it.current();
        std::cout << vertex.id() << "\n";

        // Show attributes
        collab::SimpleGraph::AttributeIterator attributes = vertex.attributes();
        while(attributes.moveNext()) {
            const auto attribute = attributes.current();
            std::cout << "  " << attribute.name() << " : " << attribute.value() << "\n";
        }

        std::cout << "  --- \n";

        // Show edges
        collab::SimpleGraph::EdgeIterator edges = vertex.edges();
        while(edges.moveNext()) {
            const collab::SimpleGraph::UUID &edge = edges.current();
            std::cout << "  (" << vertex.id() << " -> " << edge << ")\n";
        }
    }

    return 0;
}


// -----------------------------------------------------------------------------
// GraphInfo
// -----------------------------------------------------------------------------

int GraphInfoCommand::exec(const std::vector<std::string>& args) {
    if (args.size() != 0) {
        std::cout << "ERROR: invalid arguments\n";
        std::cout << "USAGE: " << getUsage() << "\n";
        return -1;
    }

    if(!Global::get().collabclient().isConnected()) {
        std::cout << "ERROR: You must be connected to a server first\n";
        std::cout << "HINT: See connect command\n";
        return -1;
    }

    if(!Global::get().collabclient().isDataLoaded()) {
        std::cout << "ERROR: No graph data loaded yet\n";
        return -1;
    }

    collab::SimpleGraph& graph = Global::get().graphdata();

    std::cout << "Nb vertices: " << graph.nbVertices() << "\n";
    std::cout << "Nb edges: " << graph.nbEdges() << "\n";

    return 0;
}
