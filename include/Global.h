#pragma once

#include <cassert>
#include <string>

#include <collabdata/custom/SimpleGraph.h>
#include <collabclient/Client.h>

#include "editor/Editor.h"
#include "mvk/MvkWrapper.h"
#include "sgraph/SGraphDebugObserver.h"
#include "sgraph/SGraphDebugOpHandler.h"
#include "sgraph/SGraphMvkOpHandler.h"
#include "sgraph/SGraphMvkMapper.h"
#include "utils/utils.h"


class Global {
    private:
        Editor                  _editor;
        MvkWrapper              _mvk;
        collab::Client          _collabclient;
        collab::SimpleGraph     _graph = collab::SimpleGraph::build(9999);
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
            _graph = collab::SimpleGraph::build(_collabclient.getUserID());
            _graph.clearOperationObservers();
#           ifndef _NDEBUG
            static SGraphDebugObserver obsDebug;
            _graph.addOperationObserver(obsDebug);
#           endif
        }

        void linkGraphMVK(const std::string& model, const std::string& mmodel) {
            // DevNote: call this after resetGraphData
            // Probably undefined behavior if called 2 times without a reset
            static SGraphMvkMapper mapper(&_mvk);
            static SGraphMvkOpHandler handler(&mapper, &_graph, model, mmodel);
            // TODO

            //_graph.addOperationObserver(
        }

    public:
        Editor& editor() { return _editor; }
        MvkWrapper& mvk() { return _mvk; }
        collab::Client& collabclient() { return _collabclient; }
        collab::SimpleGraph& graphdata() { return _graph; }
};


