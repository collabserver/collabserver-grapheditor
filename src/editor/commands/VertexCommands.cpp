#include "editor/commands/VertexCommands.h"

#include <iostream>

#include "Global.h"

// -----------------------------------------------------------------------------
// VertexAdd
// -----------------------------------------------------------------------------

int VertexAddCommand::exec(const std::vector<std::string>& args) {
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
        std::cout << "ERROR: No data loaded yet\n";
        return -1;
    }

    Global::get().graphdata().addVertex(args[0]);
    return 0;
}

// -----------------------------------------------------------------------------
// VertexRemove
// -----------------------------------------------------------------------------

int VertexRemoveCommand::exec(const std::vector<std::string>& args) {
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
        std::cout << "ERROR: No data loaded yet\n";
        return -1;
    }

    Global::get().graphdata().removeVertex(args[0]);
    return 0;
}

// -----------------------------------------------------------------------------
// VertexInfo
// -----------------------------------------------------------------------------

int VertexInfoCommand::exec(const std::vector<std::string>& args) {
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
        std::cout << "ERROR: No data loaded yet\n";
        return -1;
    }

    try {
        const auto vertex = Global::get().graphdata().at(args[0]);

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
    } catch (const std::out_of_range& e) {
        std::cout << "ERROR: vertex '" << args[0] << "' not found\n";
        return -2;
    }

    return 0;
}

// -----------------------------------------------------------------------------
// VertexList
// -----------------------------------------------------------------------------

int VertexListCommand::exec(const std::vector<std::string>& args) {
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
        std::cout << "ERROR: No data loaded yet\n";
        return -1;
    }

    SimpleGraph::VertexIterator it = Global::get().graphdata().vertices();
    while (it.moveNext()) {
        SimpleGraph::VertexDescriptor vertex = it.current();
        std::cout << vertex.id() << " ";
    }
    std::cout << "\n";

    return 0;
}
