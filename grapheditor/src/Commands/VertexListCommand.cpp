#include "Commands/VertexListCommand.h"

VertexListCommand::VertexListCommand()
    : Command("vertexList",
              "Display a list of all the vertex in the graph.",
              "Name :\n\tvertexList - Display a list of all the vertex in the graph.\nUsage :\n\tvertexList [option: --details]") {
};

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

