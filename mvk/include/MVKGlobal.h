#pragma once

#include <collabclient/Client.h>
#include <collabdata/custom/SimpleGraph.h>

#include "MVKWrapper.h"


class MVKGlobal {
    private:
        collab::Client          _collabclient;
        collab::SimpleGraph     _graph = collab::SimpleGraph::build(9999);
        MVKWrapper              _mvkWrapper;
        // DevNote: _graph is initialized here, but id doesn't matter since
        // it will be actually reset when user enter a collab room.

    private:
        MVKGlobal() = default;
        MVKGlobal(const MVKGlobal& other) = delete;
        MVKGlobal& operator=(const MVKGlobal& other) = delete;

    public:
        static MVKGlobal& get() {
            static MVKGlobal _instance;
            return _instance;
        }

        void resetGraphData() {
            _graph = collab::SimpleGraph::build(_collabclient.getUserID());
        }

    public:
        collab::Client& collabclient() { return _collabclient; }
        collab::SimpleGraph& graphdata() { return _graph; }
        MVKWrapper& mvkWrapper() { return _mvkWrapper; }
};
