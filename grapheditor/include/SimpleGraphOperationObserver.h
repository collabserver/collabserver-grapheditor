#pragma once

#include "collabdata/custom/SimpleGraph.h"
#include "SimpleGraphOperationHandler.h"


class SimpleGraphOperationObserver : public collab::OperationObserver {
    private:
        SimpleGraphOperationHandler opHandler;
    public:
        SimpleGraphOperationObserver(SimpleGraphOperationHandler opHandler);
        void onOperation(const collab::Operation &op) override;
};


