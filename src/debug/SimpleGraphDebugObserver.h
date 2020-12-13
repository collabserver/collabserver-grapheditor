#pragma once

#include "debug/SimpleGraphDebugOpHandler.h"
#include "simplegraph/SimpleGraph.h"

/**
 * Observer for SimpleGraph operation and uses debug handler.
 */
class SimpleGraphDebugObserver : public collabserver::CollabDataOperationObserver {
   private:
    SimpleGraphDebugOpHandler _opHandler;

   public:
    SimpleGraphDebugObserver() = default;
    void onOperation(const collabserver::CollabDataOperation &op) override { op.accept(_opHandler); }
};
