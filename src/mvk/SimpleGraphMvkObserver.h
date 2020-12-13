#pragma once

#include "collabserver/datatypes/collabdata/CollabDataOperationObserver.h"
#include "mvk/SimpleGraphMvkOpHandler.h"
#include "simplegraph/SimpleGraph.h"

class SimpleGraphMvkObserver : public collabserver::CollabDataOperationObserver {
   private:
    SimpleGraphMvkOpHandler* _opHandler;

   public:
    SimpleGraphMvkObserver(SimpleGraphMvkOpHandler* handler) : _opHandler(handler) {}
    void onOperation(const collabserver::CollabDataOperation& op) override { op.accept(*_opHandler); }
};
