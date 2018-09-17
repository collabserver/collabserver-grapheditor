#pragma once

#include <cassert>

#include "collabclient/Client.h"
#include "collabdata/custom/SimpleGraph.h"


class Global {
    private:
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
        }

    public:
        collab::Client& collabclient() { return _collabclient; }
        collab::SimpleGraph& graphdata() { return _graph; }
};
