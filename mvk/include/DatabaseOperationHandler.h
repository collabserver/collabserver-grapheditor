/**
 * @brief Basic Interface for any Database and any Metamodel
 *
 * You must instantiate one OperationHandler per Model
 */

#ifndef MVK_DATABASEOPERATIONHANDLER_H
#define MVK_DATABASEOPERATIONHANDLER_H

#include <iostream>
#include <collabdata/custom/OperationHandler.h>
#include <collabdata/custom/Operation.h>

class DatabaseOperationHandler : public collab::OperationHandler {
protected:
    DatabaseOperationHandler() = default;
    DatabaseOperationHandler(const DatabaseOperationHandler& other) = default;
    DatabaseOperationHandler& operator=(const DatabaseOperationHandler& other) = default;
};


#endif //MVK_DATABASEOPERATIONHANDLER_H
