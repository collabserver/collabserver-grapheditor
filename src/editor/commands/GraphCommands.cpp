#include "editor/commands/GraphCommands.h"

#include <fstream>
#include <iostream>

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

    if (!Global::get().collabclient().isConnected()) {
        std::cout << "ERROR: You must be connected to a server first\n";
        std::cout << "HINT: See connect command\n";
        return -1;
    }

    if (!Global::get().collabclient().isDataLoaded()) {
        std::cout << "ERROR: No graph data loaded yet\n";
        return -1;
    }

    SimpleGraph::VertexIterator it = Global::get().graphdata().vertices();
    while (it.moveNext()) {
        SimpleGraph::VertexDescriptor vertex = it.current();
        std::cout << vertex.id() << "\n";

        // Show attributes
        SimpleGraph::AttributeIterator attributes = vertex.attributes();
        while (attributes.moveNext()) {
            const auto attribute = attributes.current();
            std::cout << "  " << attribute.name() << " : " << attribute.value() << "\n";
        }

        std::cout << "  --- \n";

        // Show edges
        SimpleGraph::EdgeIterator edges = vertex.edges();
        while (edges.moveNext()) {
            const SimpleGraph::UUID& edge = edges.current();
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

    if (!Global::get().collabclient().isConnected()) {
        std::cout << "ERROR: You must be connected to a server first\n";
        std::cout << "HINT: See connect command\n";
        return -1;
    }

    if (!Global::get().collabclient().isDataLoaded()) {
        std::cout << "ERROR: No graph data loaded yet\n";
        return -1;
    }

    SimpleGraph& graph = Global::get().graphdata();

    std::cout << "Nb vertices: " << graph.nbVertices() << "\n";
    std::cout << "Nb edges: " << graph.nbEdges() << "\n";

    return 0;
}

// -----------------------------------------------------------------------------
// GraphDump
// -----------------------------------------------------------------------------

int GraphDumpCommand::exec(const std::vector<std::string>& args) {
    if (args.size() != 1) {
        std::cout << "ERROR: invalid arguments\n";
        std::cout << "USAGE: " << getUsage() << "\n";
        return -1;
    }

    if (!Global::get().collabclient().isConnected()) {
        std::cout << "ERROR: You must be connected to a server first\n";
        std::cout << "HINT: See connect command\n";
        return -1;
    }

    if (!Global::get().collabclient().isDataLoaded()) {
        std::cout << "ERROR: No graph data loaded yet\n";
        return -1;
    }

    std::ofstream output(args[0]);

    if (!output.is_open()) {
        std::cout << "ERROR: Unable to open " << args[0] << "\n";
        return -1;
    }

    output << "digraph {"
           << "\n";

    SimpleGraph::VertexIterator it = Global::get().graphdata().vertices();
    while (it.moveNext()) {
        SimpleGraph::VertexDescriptor vertex = it.current();
        output << "  " << vertex.id();

        // Show attributes
        output << " [";
        SimpleGraph::AttributeIterator attributes = vertex.attributes();
        while (attributes.moveNext()) {
            const auto attribute = attributes.current();
            output << " " << attribute.name() << "=\"" << attribute.value() << "\"";
        }
        output << "]";

        output << "\n";

        // Show edges
        SimpleGraph::EdgeIterator edges = vertex.edges();
        while (edges.moveNext()) {
            const SimpleGraph::UUID& edge = edges.current();
            output << "  " << vertex.id() << " -> " << edge << "\n";
        }
    }

    output << "}"
           << "\n";

    output.close();

    return 0;
}
