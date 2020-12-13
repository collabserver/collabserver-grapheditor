#pragma once

#include <collabserver/client/Client.h>

#include <cassert>
#include <string>

#include "debug/SimpleGraphDebugObserver.h"
#include "debug/SimpleGraphDebugOpHandler.h"
#include "editor/Editor.h"
#include "mvk/MvkWrapper.h"
#include "mvk/SimpleGraphMvkMapper.h"
#include "mvk/SimpleGraphMvkObserver.h"
#include "mvk/SimpleGraphMvkOpHandler.h"
#include "simplegraph/SimpleGraph.h"
#include "utils/utils.h"

class Global {
   private:
    Editor _editor;
    MvkWrapper _mvk;
    collabserver::Client _collabclient;
    SimpleGraph _graph = SimpleGraph::build(9999);
    // DevNote: _graph is initialized here, but id doesn't matter since
    // it will be actually reset when user enter a collab room.

   private:
    Global() = default;
    Global(const Global& other) = delete;
    Global& operator=(const Global& other) = delete;

   public:
    static Global& get() {
        static Global _instance;
        return _instance;
    }

    void resetGraphData() {
        _graph = SimpleGraph::build(_collabclient.getUserID());
        _graph.clearOperationObservers();
#ifndef _NDEBUG
        static SimpleGraphDebugObserver obsDebug;
        _graph.addOperationObserver(obsDebug);
#endif
    }

    bool resetGraphDataMvk(const std::string& model, const std::string& mmodel) {
        this->resetGraphData();
        static SimpleGraphMvkMapper mapper(&_mvk);
        static SimpleGraphMvkOpHandler handler(&mapper, &_graph, model, mmodel);
        static SimpleGraphMvkObserver observer(&handler);

        // At beginning, model MUST BE VALID (And exists in db)
        _mvk.modelVerify(model, mmodel);
        if (_mvk.isSuccess()) {
            _graph.addOperationObserver(observer);
            mapper.loadGraph(model, mmodel, _graph);
            return true;
        }
        return false;
    }

   public:
    Editor& editor() { return _editor; }
    MvkWrapper& mvk() { return _mvk; }
    collabserver::Client& collabclient() { return _collabclient; }
    SimpleGraph& graphdata() { return _graph; }
};
