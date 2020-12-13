#pragma once

#include <string>

#include "mvk/MvkWrapper.h"
#include "simplegraph/SimpleGraph.h"

/**
 * \brief
 * SimpleGraph Mapper for MVK database.
 *
 * Gives set of operations to use SimpleGraph with a MVK database.
 * (CRUD Operations etc).
 */
class SimpleGraphMvkMapper {
    // -------------------------------------------------------------------------
    // Data
    // -------------------------------------------------------------------------
   private:
    MvkWrapper* _mvk = nullptr;

    // -------------------------------------------------------------------------
    // INIT
    // -------------------------------------------------------------------------

   public:
    SimpleGraphMvkMapper(MvkWrapper* mvk);

    // -------------------------------------------------------------------------
    // CRUD
    // -------------------------------------------------------------------------

   public:
    /**
     * Add new vertex to a SimpleGraph in MVK.
     *
     * \param model SimpleGraph path as registered in MVK.
     * \param metamodel SimpleGraph metamodel as registered in MVK.
     * \param name Vertex name to set (Its ID).
     * \return True if successfully applied, otherwise, return false.
     */
    bool vertexAdd(const std::string& model, const std::string& metamodel, const std::string& name) const;

    /**
     * Remove vertex from a SimpleGraph in MVK.
     *
     * \param model SimpleGraph path as registered in MVK.
     * \param metamodel SimpleGraph metamodel as registered in MVK.
     * \param name Vertex name (Its ID).
     * \return True if successfully applied, otherwise, return false.
     */
    bool vertexRemove(const std::string& model, const std::string& metamodel, const std::string& name) const;

    /**
     * Add edge to a SimpleGraph in MVK.
     *
     * \param model SimpleGraph path as registered in MVK.
     * \param metamodel SimpleGraph metamodel as registered in MVK.
     * \param from ID of the source vertex.
     * \param to ID of the destination vertex.
     * \return True if successfully applied, otherwise, return false.
     */
    bool edgeAdd(const std::string& model, const std::string& metamodel, const std::string& from,
                 const std::string& to) const;

    /**
     * Remove edge from a SimpleGraph in MVK.
     *
     * \param model SimpleGraph path as registered in MVK.
     * \param metamodel SimpleGraph metamodel as registered in MVK.
     * \param from ID of the source vertex.
     * \param to ID of the destination vertex.
     * \return True if successfully applied, otherwise, return false.
     */
    bool edgeRemove(const std::string& model, const std::string& metamodel, const std::string& from,
                    const std::string& to) const;

    /**
     * Add attribute to a SimpleGraph in MVK.
     *
     * \param model SimpleGraph path as registered in MVK.
     * \param metamodel SimpleGraph metamodel as registered in MVK.
     * \param vertexID Vertex where to add attribute.
     * \param attrName Attribute's unique name.
     * \param attrValue Attribute's value to set.
     * \return True if successfully applied, otherwise, return false.
     */
    bool attributeAdd(const std::string& model, const std::string& metamodel, const std::string& vertexID,
                      const std::string& attrName, const std::string& attrValue) const;

    /**
     * Remove attribute from a SimpleGraph in MVK.
     *
     * \param model SimpleGraph path as registered in MVK.
     * \param metamodel SimpleGraph metamodel as registered in MVK.
     * \param vertexID Vertex where to remove attribute.
     * \param attrName Name of the attribute to remove.
     * \return True if successfully applied, otherwise, return false.
     */
    bool attributeRemove(const std::string& model, const std::string& metamodel, const std::string& vertexID,
                         const std::string& attrName) const;

    /**
     * Set / modify value of an attribute from a SimpleGraph in MVK.
     *
     * \param model SimpleGraph path as registered in MVK.
     * \param metamodel SimpleGraph metamodel as registered in MVK.
     * \param vertexID Vertex where to set attribute.
     * \param attrName Name of the attribute to modify.
     * \param attrValue New value to set in this attribute.
     * \return True if successfully applied, otherwise, return false.
     */
    bool attributeSet(const std::string& model, const std::string& metamodel, const std::string& vertexID,
                      const std::string& attrName, const std::string& attrValue) const;

    /**
     * Load a graph with MVK content.
     *
     * Get MVK data, convert it into SimpleGraph operations and
     * apply this operation on the graph.
     * Most of the case, graph is empty and this is an 'init' method.
     *
     * \return True if successfully loaded, otherwise, return false.
     */
    bool loadGraph(const std::string& model, const std::string& metamodel, SimpleGraph& graph) const;
};
