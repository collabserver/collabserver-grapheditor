#pragma once

#include <collabdata/custom/OperationObserver.h>
#include <collabdata/custom/Operation.h>

#include "DatabaseSimpleGraphOperationHandler.h"
#include "MVKSimpleGraphOperationHandler.h"
#include "DatabaseOperationHandler.h"


class DatabaseObserver : public collab::OperationObserver {
    protected:

        /**
         * Used to apply every operation send by the observable item.
         */
        DatabaseOperationHandler *opHandler;

        DatabaseObserver() = default;

    public:

        explicit DatabaseObserver(DatabaseOperationHandler *opHandler);

        ~DatabaseObserver() override;

        void onOperation(const collab::Operation &op) override;
};


