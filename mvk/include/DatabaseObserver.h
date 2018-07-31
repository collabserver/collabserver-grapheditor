/**
 * @brief Observer for any Metamodel
 */

#ifndef MVK_DATABASEOBSERVER_H
#define MVK_DATABASEOBSERVER_H

#include <collabdata/custom/OperationObserver.h>
#include <collabdata/custom/Operation.h>
#include "DatabaseSimpleGraphOperationHandler.h"
#include "MVKSimpleGraphOperationHandler.h"
#include "DatabaseOperationHandler.h"

class DatabaseObserver : public collab::OperationObserver {
protected:
    /**
     * @brief Used to apply every operation send by the observable item
     */
    DatabaseOperationHandler *opHandler;

    DatabaseObserver() = default;

public:

    explicit DatabaseObserver(DatabaseOperationHandler *opHandler);

    ~DatabaseObserver() override;

    /**
     * @brief call the operation in parameter by the handler
     * @param op the operation send by the abservable item
     */
    void onOperation(const collab::Operation &op) override;
};


#endif //MVK_DATABASEOBSERVER_H
