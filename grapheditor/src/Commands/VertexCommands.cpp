#include "Commands/VertexCommands.h"

#include "collabdata/custom/SimpleGraph.h"


// -----------------------------------------------------------------------------
// VertexAdd
// -----------------------------------------------------------------------------

int VertexAddCommand::exec(utils::config config,
                           const std::vector<std::string> &args) {
    if(args.size() != 1) {
        std::cout << "ERROR: invalid arguments\n";
        std::cout << "USAGE: " << getUsage() << "\n";
        return -1;
    }

    config.getDataStructure()->addVertex(args[0]);
    return 0;
}


// -----------------------------------------------------------------------------
// VertexEdit
// -----------------------------------------------------------------------------

int VertexEditCommand::exec(utils::config config,
                            const std::vector<std::string> &args) {
    // TODO
    std::cout << "Vertex Edited (Not implemented yet)\n";
    return 0;
}


// -----------------------------------------------------------------------------
// VertexInfo
// -----------------------------------------------------------------------------

int VertexInfoCommand::exec(utils::config config,
                            const std::vector<std::string> &args) {
    if (args.size() != 1) {
        std::cout << "ERROR: invalid arguments\n";
        std::cout << "USAGE: " << getUsage() << "\n";
        return -1;
    }

    try {
        collab::SimpleGraph::VertexDescriptor vertex = config.getDataStructure()->at(args[0]);
        std::cout << "- " << vertex.id() << "\n";

        // Show attributes
        collab::SimpleGraph::AttributeIterator attributes = vertex.attributes();
        std::cout << "Attribute:\n";
        while (attributes.moveNext()) {
            const collab::SimpleGraph::AttributeDescriptor attribute = attributes.current();
            std::cout << "\t" << attribute.name() << " : " << attribute.value() << "\n";
        }
        std::cout << "\n";

        // Show edges
        collab::SimpleGraph::EdgeIterator edges = vertex.edges();
        std::cout << "Edge:\n";
        while (edges.moveNext()) {
            const collab::SimpleGraph::UUID &edge = edges.current();
            std::cout << "\t" << vertex.id() << " -> " << edge << "\n";
        }
    }
    catch (const std::out_of_range &e) {
        std::cout << "ERROR: vertex " << args[0] << " not found in this graph\n";
        return -2;
    }
    return 0;
}


// -----------------------------------------------------------------------------
// VertexList
// -----------------------------------------------------------------------------

int VertexListCommand::exec(utils::config config, const std::vector<std::string> &args) {
    bool detail = false;
    if(args.size() == 1) {
        if (args[0] == "--details") {
            detail = true;
        }
        else {
            std::cout << "ERROR: invalid arguments\n";
            std::cout << "USAGE: " << getUsage() << "\n";
            return -2;
        }
    }
    else if (args.size() > 1) {
        std::cout << "ERROR: invalid arguments\n";
        std::cout << "USAGE: " << getUsage() << "\n";
        return -1;
    }

    std::cout << "\nVertex List:\n";

    collab::SimpleGraph::VertexIterator it = config.getDataStructure()->vertices();
    while (it.moveNext()) {
        collab::SimpleGraph::VertexDescriptor vertex = it.current();
        std::cout << "- " << vertex.id() << "\n";

        if(detail) {
            // Show attributes
            collab::SimpleGraph::AttributeIterator attributes = vertex.attributes();
            std::cout << "\tAttribute:\n";
            while (attributes.moveNext()) {
                const collab::SimpleGraph::AttributeDescriptor attribute = attributes.current();
                std::cout << "\t\t" << attribute.name() << " : " << attribute.value() << "\n";
            }
            std::cout << "\n";
            // Show edges
            collab::SimpleGraph::EdgeIterator edges = vertex.edges();
            std::cout << "\tEdge:\n";
            while (edges.moveNext()) {
                const collab::SimpleGraph::UUID &edge = edges.current();
                std::cout <<"\t\t" << vertex.id() << " -> " << edge << "\n";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}


// -----------------------------------------------------------------------------
// VertexRemove
// -----------------------------------------------------------------------------

int VertexRemoveCommand::exec(utils::config config, const std::vector<std::string> &args) {
    if (args.size() != 1) {
        std::cout << "ERROR: invalid arguments\n";
        std::cout << "USAGE: " << getUsage() << "\n";
        return -1;
    }

    config.getDataStructure()->removeVertex(args[0]);
    return 0;
}
