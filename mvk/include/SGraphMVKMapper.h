#pragma once

#include <string>

#include "MVKWrapper.h"


/**
 * \brief
 * SimpleGraph Mapper for MVK database.
 *
 * Gives set of operation to use SimpleGraph with MVK database.
 * (CRUD Operations etc).
 */
class SGraphMVKMapper {
    // -------------------------------------------------------------------------
    // Data
    // -------------------------------------------------------------------------
    private:

        MVKWrapper* _mvk                = nullptr;
        const std::string _model        = "models/BaseSimpleGraph";
        const std::string _metamodel    = "formalisms/SimpleGraph";


    // -------------------------------------------------------------------------
    // INIT
    // -------------------------------------------------------------------------

    public:

        SGraphMVKMapper(MVKWrapper* mvk);


    // -------------------------------------------------------------------------
    // CRUD
    // -------------------------------------------------------------------------

    public:

        bool vertexAdd(const std::string& name);

        bool vertexRemove(const std::string& name);

        bool edgeAdd(const std::string& from, const std::string& to);

        bool edgeRemove(const std::string& from, const std::string& to);

        bool attributeAdd(const std::string& elt,
                          const std::string& attrName,
                          const std::string& attrValue);

        bool attributeRemove(const std::string& elt, const std::string& attrName);

        bool attributeSet(const std::string& elt,
                          const std::string& attrName,
                          const std::string& attrValue);


    // -------------------------------------------------------------------------
    // Internal
    // -------------------------------------------------------------------------

    private:

        bool isModelValid();
};


