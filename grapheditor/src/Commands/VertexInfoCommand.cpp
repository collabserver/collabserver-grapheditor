#include "Commands/VertexInfoCommand.h"

VertexInfoCommand::VertexInfoCommand()
    : Command("vertexInfo",
              "Display information about a specified vertex",
              "Name :\n\tvertexInfo - Display the information about the specified vertex.\nUsage :\n\tvertexInfo [vertex id]"){
};

int VertexInfoCommand::exec(utils::config config, const std::vector<std::string> &arguments) {
    //TODO
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
        while (attributes.moveNext())
        {
            const collab::SimpleGraph::AttributeDescriptor attribute = attributes.current();
            std::cout << "\t" << attribute.name() << " : " << attribute.value() << std::endl;
        }
        std::cout << std::endl;
        // Show edges
        collab::SimpleGraph::EdgeIterator edges = vertex.edges();
        std::cout << "Edge :" << std::endl;
        while (edges.moveNext())
        {
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
