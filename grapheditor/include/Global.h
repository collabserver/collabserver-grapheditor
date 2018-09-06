#pragma once

#include <cassert>

#include "Editor.h"
#include "collabclient/Client.h"
#include "collabdata/custom/SimpleGraph.h"
#include "utils.h"


class Global {
    private:
        Editor                  _editor;
        collab::Client          _collabclient;
        collab::SimpleGraph     _graph = collab::SimpleGraph(0);
        SGraphOpObserverDebug   _obs;

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
            // TODO Not sure this actually works. To check
            _graph = collab::SimpleGraph(42); // TODO WARNING: TMP ID
#           ifndef _NDEBUG
            _graph.addOperationObserver(_obs);
#           endif
        }

    public:
        Editor& editor() { return _editor; }
        collab::Client& collabclient() { return _collabclient; }
        collab::SimpleGraph& graphdata() { return _graph; }
};
