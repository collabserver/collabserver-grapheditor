#include "Commands/VertexCommands.h"

#include "collabdata/custom/SimpleGraph.h"


int VertexAddCommand::exec(utils::config config, const std::vector<std::string> &arguments) {
    if (arguments.size() != 1) {
        std::cout << "Error : missing or too many arguments" << std::endl;
        std::cout << "Usage : vertexAdd \"vertex\"" << std::endl;
        return -1;
    }
    config.getDataStructure()->addVertex(arguments[0]);
    return 0;
}

int VertexEditCommand::exec(utils::config config, const std::vector<std::string> &arguments){
    std::cout << "Vertex Edited" << std::endl;
    return 0;
}

int VertexInfoCommand::exec(utils::config config, const std::vector<std::string> &arguments) {
    if (arguments.size() != 1) {
        std::cout << "Error : missing or too many arguments" << std::endl;
        return -1;
    }

    try {
        collab::SimpleGraph::VertexDescriptor vertex = config.getDataStructure()->at(arguments[0]);
        std::cout << "- " << vertex.id() << std::endl;

        // Show attributes
        collab::SimpleGraph::AttributeIterator attributes = vertex.attributes();
        std::cout << "Attribute :" << std::endl;
        while (attributes.moveNext()) {
            const collab::SimpleGraph::AttributeDescriptor attribute = attributes.current();
            std::cout << "\t" << attribute.name() << " : " << attribute.value() << std::endl;
        }
        std::cout << std::endl;

        // Show edges
        collab::SimpleGraph::EdgeIterator edges = vertex.edges();
        std::cout << "Edge :" << std::endl;
        while (edges.moveNext()) {
            const collab::SimpleGraph::UUID &edge = edges.current();
            std::cout << "\t" << vertex.id() << " -> " << edge << std::endl;
        }
    }
    catch (const std::out_of_range &e) {
        std::cout << "Error : vertex " << arguments[0] << " not found in this graph" << std::endl;
        return -2;
    }
    return 0;
}

int VertexListCommand::exec(utils::config config, const std::vector<std::string> &arguments) {
    bool detail = false;
    if (arguments.size() == 1) {
        if (arguments[0] == "--details") {
            detail = true;
        }
        else {
            std::cout << "error : unknown argument" << std::endl;
            return -2;
        }
    }
    else if (arguments.size() > 1) {
        std::cout << "error : too many arguments" << std::endl;
        return -1;
    }
    std::cout << std::endl;

    std::cout << "Vertex List :" << std::endl;

    collab::SimpleGraph::VertexIterator it = config.getDataStructure()->vertices();
    while (it.moveNext()) {
        collab::SimpleGraph::VertexDescriptor vertex = it.current();
        std::cout << "- " << vertex.id() << std::endl;

        if (detail) {
            // Show attributes
            collab::SimpleGraph::AttributeIterator attributes = vertex.attributes();
            std::cout << "\tAttribute :"<< std::endl;
            while (attributes.moveNext()) {
                const collab::SimpleGraph::AttributeDescriptor attribute = attributes.current();
                std::cout << "\t\t" << attribute.name() << " : " << attribute.value() << std::endl;
            }
            std::cout << std::endl;
            // Show edges
            collab::SimpleGraph::EdgeIterator edges = vertex.edges();
            std::cout << "\tEdge :"<< std::endl;
            while (edges.moveNext()) {
                const collab::SimpleGraph::UUID &edge = edges.current();
                std::cout <<"\t\t" << vertex.id() << " -> " << edge << std::endl;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}

int VertexRemoveCommand::exec(utils::config config, const std::vector<std::string> &arguments) {
    if (arguments.size() != 1) {
        std::cout << "Error : missing or too many arguments" << std::endl;
        std::cout << "Usage : vertexRemove \"vertex\"" << std::endl;
        return -1;
    }
    config.getDataStructure()->removeVertex(arguments[0]);
    return 0;
}
