#pragma once

#include <collabdata/custom/SimpleGraph.h>

#include "SGraphDebugOpHandler.h"


/**
 * Observer for SimpleGraph operation and uses debug handler.
 */
class SGraphDebugObserver : public collab::OperationObserver {
    private:
        SGraphDebugOpHandler _opHandler;

    public:
        SGraphDebugObserver() = default;
        void onOperation(const collab::Operation &op) override {
            op.accept(_opHandler);
        }
};
