#pragma once

#include <collabdata/custom/SimpleGraph.h>

#include "SGraphMvkOpHandler.h"


class SGraphMvkObserver : public collab::OperationObserver {
    private:
        SGraphMvkOpHandler* _opHandler;
    public:
        SGraphMvkObserver(SGraphMvkOpHandler* handler) : _opHandler(handler) {}
        void onOperation(const collab::Operation &op) override {
            op.accept(*_opHandler);
        }
};
