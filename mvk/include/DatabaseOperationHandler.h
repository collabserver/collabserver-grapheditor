#pragma once

#include <iostream>
#include <collabdata/custom/OperationHandler.h>
#include <collabdata/custom/Operation.h>


/**
 * \brief Basic Interface for any Database and any Metamodel.
 *
 * You must instantiate one OperationHandler per Model.
 */
class DatabaseOperationHandler : public collab::OperationHandler {
    protected:
        DatabaseOperationHandler() = default;
        DatabaseOperationHandler(const DatabaseOperationHandler& other) = default;
        DatabaseOperationHandler& operator=(const DatabaseOperationHandler& other) = default;
};


