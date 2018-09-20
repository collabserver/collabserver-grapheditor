#pragma once

#include <cassert>

#include <collabdata/custom/SimpleGraph.h>
#include <collabclient/Client.h>

#include "editor/Editor.h"
#include "mvk/MVKWrapper.h"
#include "utils/utils.h"


class Global {
    private:
        Editor                  _editor;
        MVKWrapper              _mvk;
        collab::Client          _collabclient;
        collab::SimpleGraph     _graph = collab::SimpleGraph::build(9999);
        SGraphOpObserverDebug   _obs;
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
#           ifndef _NDEBUG
            _graph.addOperationObserver(_obs);
#           endif
        }

    public:
        Editor& editor() { return _editor; }
        MVKWrapper& mvk() { return _mvk; }
        collab::Client& collabclient() { return _collabclient; }
        collab::SimpleGraph& graphdata() { return _graph; }
};
