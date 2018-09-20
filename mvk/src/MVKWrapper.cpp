#include "MVKWrapper.h"

#include <cassert>
#include <iostream>
#include <sstream>
#include <regex>

#include "UUIDGenerator.h"
#include "Messaging.h"


// -----------------------------------------------------------------------------
// Static util methods
// -----------------------------------------------------------------------------

struct MVKDebugData { char trace_ascii; /* 1 or 0 */ };

static void MVKDebugDump(const char *text, FILE *stream, unsigned char *ptr,
                         size_t size, char nohex);
static int MVKDebugTrace(CURL *handle, curl_infotype type, char *data,
                         size_t size, void *userp);

static void curlError(CURLcode code) {
    if(code != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(code));
    }
}

static size_t curlWriteCallback(void *contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*) userp)->clear();
    ((std::string*) userp)->append((char*) contents, size* nmemb);
    return size * nmemb;
}


// -----------------------------------------------------------------------------
// Init methods
// -----------------------------------------------------------------------------

MVKWrapper::MVKWrapper(bool debugMode) {
    _debugMode = debugMode;
    _uuid = generateNewUUID();

    // Init CURL
    curl_global_init(CURL_GLOBAL_ALL);
    _curl = curl_easy_init();
    assert(_curl != nullptr);

    curl_easy_setopt(_curl, CURLOPT_WRITEDATA, &_buffer);
    curl_easy_setopt(_curl, CURLOPT_WRITEFUNCTION, curlWriteCallback);

    // This part usefull in case of we need a really big debug mode
    /*
    if(_debugMode) {
        MVKDebugData config;
        curl_easy_setopt(_curl, CURLOPT_DEBUGFUNCTION, MVKDebugTrace);
        curl_easy_setopt(_curl, CURLOPT_DEBUGDATA, &config);
        curl_easy_setopt(_curl, CURLOPT_VERBOSE, 1L);
    }
    */
}

MVKWrapper::~MVKWrapper() {
    curl_easy_cleanup(_curl);
    curl_global_cleanup();
}


// -----------------------------------------------------------------------------
// Connection
// -----------------------------------------------------------------------------

int MVKWrapper::connect(const std::string& ip, const int port,
                        const std::string& username, const std::string& pswd) {
    this->connectMVK(ip, port);
    this->login(username, pswd);
    return 0;
}

int MVKWrapper::disconnect() {
    this->logout();
    this->disconnectMVK();
    return 0;
}

int MVKWrapper::connectMVK(const std::string& ip, const int port) {
    // Addr format: "http://127.0.0.1:8001"
    std::stringstream addr;
    addr << "http://" << ip << ":" << port;
    curl_easy_setopt(_curl, CURLOPT_URL, addr.str().c_str());
    _buffer = "";

    return 0;
}

int MVKWrapper::disconnectMVK() {
    curl_easy_setopt(_curl, CURLOPT_URL, "");
    _buffer = "";
    return 0;
}

int MVKWrapper::login(const std::string& username, const std::string& pswd) {
    // Connect MVK
    std::string msg = MSG_USER_CONNECT(_uuid);
    send(msg.c_str());
    if(sendInternal() == -1) { return -1; }

    msg = MSG_USER_LOGIN(username, _uuid);
    send(msg.c_str());
    if(sendInternal() == -1) { return -1; }

    std::regex newUser("^[A-Za-z \"]+new user");
    if(std::regex_search(_buffer, newUser)) {
        msg = MSG_USER_LOGIN(pswd, _uuid);
        send(msg.c_str());
        if(sendInternal() == -1) { return -1; }
    }

    msg = MSG_USER_LOGIN(pswd, _uuid);
    send(msg.c_str());
    if(sendInternal() == -1) { return -1; }
    if(sendInternal() == -1) { return -1; }

    if(!_debugMode) {
        msg = MSG_CONFIG_SET_QUIET(_uuid);
        send(msg.c_str());
    }
    return 0;
}

int MVKWrapper::logout() {
    // DevNote: Well. We actually don't know how to logout.
    // More MVK reading doc required.
    return 0;
}


// -----------------------------------------------------------------------------
// Network
// -----------------------------------------------------------------------------

void MVKWrapper::send(const char* data) {
    assert(_curl != nullptr);
    curl_easy_setopt(_curl, CURLOPT_POSTFIELDS, data);
    curl_easy_setopt(_curl, CURLOPT_POSTFIELDSIZE, -1L);

    CURLcode rabbit = curl_easy_perform(_curl);
    curlError(rabbit);
    if(_debugMode) {
        std::clog << "[REQUEST]: " << data << "\n";
        std::clog << "[RESPONSE]: " << _buffer << std::endl;
    }
}

int MVKWrapper::sendInternal() {
    // TODO I actually need to check the doc etc to understand:
    // Do we really need this dummy request?
    std::string msg = MSG_DUMMY(_uuid);
    this->send(msg.c_str());

    std::regex unknownCommand("^\"[Uu]nknown command");
    if (std::regex_search(_buffer, unknownCommand)) {
        return 0;
    }

    return -1;
}


// -----------------------------------------------------------------------------
// Models management
// -----------------------------------------------------------------------------

int MVKWrapper::modelList(const std::string& path) {
    std::string request = MSG_MODEL_LIST(path, _uuid);
    send(request.c_str());
    if(sendInternal() == -1) { return -1; }
    return 0;
}

int MVKWrapper::modelAdd(const std::string& name,
                         const std::string& mmodel,
                         const std::string& syntax) {
    std::string request = MSG_MODEL_ADD(name, mmodel, syntax, _uuid);
    send(request.c_str());
    if(sendInternal() == -1) { return -1; }
    if(_debugMode) {
        if(sendInternal() == -1) { return -1; }
        if(sendInternal() == -1) { return -1; }
        if(sendInternal() == -1) { return -1; }
    }

    return 0;
}

int MVKWrapper::modelDelete(const std::string& name) {
    std::string request = MSG_MODEL_DEL(name, _uuid);
    send(request.c_str());
    if(sendInternal() == -1) { return -1; }
    if(_debugMode) {
        if(sendInternal() == -1) { return -1; }
    }
    return 0;
}

int MVKWrapper::modelVerify(const std::string& model, const std::string& mmodel) {
    std::string request = MSG_MODEL_VERIFY(model, mmodel, _uuid);
    send(request.c_str());
    if(sendInternal() == -1) { return -1; }
    if(_debugMode) {
        if(sendInternal() == -1) { return -1; }
        if(sendInternal() == -1) { return -1; }
    }
    return 0;
}

int MVKWrapper::modelEnter(const std::string& model, const std::string& mmodel) {
    std::string request = MSG_MODEL_MODIFY(model, mmodel, _uuid);
    send(request.c_str());
    if(sendInternal() == -1) { return -1; }
    if(_debugMode) {
        if(sendInternal() == -1) { return -1; }
        if(sendInternal() == -1) { return -1; }
    }
    return 0;
}

int MVKWrapper::modelExit() {
    std::string request = MSG_MODEL_EXIT(_uuid);
    send(request.c_str());
    if(sendInternal() == -1) { return -1; }
    return 0;
}


// -----------------------------------------------------------------------------
// Model
// -----------------------------------------------------------------------------

int MVKWrapper::elementList() {
    std::string request = MSG_ELT_LIST(_uuid);
    send(request.c_str());
    if(sendInternal() == -1) { return -1; }
    return 0;
}

int MVKWrapper::elementListJSON() {
    std::string request = MSG_ELT_LIST_JSON(_uuid);
    send(request.c_str());
    if(sendInternal() == -1) { return -1; }
    return 0;
}

int MVKWrapper::elementCreate(const std::string& type, const std::string& name) {
    std::string request = MSG_ELT_CREA(type, name, _uuid);
    send(request.c_str());
    if(sendInternal() == -1) { return -1; }
    if(_debugMode) {
        if(sendInternal() == -1) { return -1; }
        if(sendInternal() == -1) { return -1; }
    }
    return 0;
}
int MVKWrapper::elementDelete(const std::string& name) {
    std::string request = MSG_ELT_DEL(name, _uuid);
    send(request.c_str());
    if(sendInternal() == -1) { return -1; }
    if(_debugMode) {
        if(sendInternal() == -1) { return -1; }
    }
    return 0;
}

int MVKWrapper::edgeCreate(const std::string& type, const std::string& name,
                           const std::string& from, const std::string& to) {
    std::string request = MSG_EDGE_CREA(type, name, from, type, _uuid);
    send(request.c_str());
    if(sendInternal() == -1) { return -1; }
    if(_debugMode) {
        if(sendInternal() == -1) { return -1; }
        if(sendInternal() == -1) { return -1; }
        if(sendInternal() == -1) { return -1; }
        if(sendInternal() == -1) { return -1; }
    }
    return 0;
}

int MVKWrapper::attributeSet(const std::string& elt,
                             const std::string& attrType,
                             const std::string& attrValue) {
    std::string request = MSG_ATTR_SET(elt, attrType, attrValue, _uuid);
    send(request.c_str());
    if(sendInternal() == -1) { return -1; }
    if(_debugMode) {
        if(sendInternal() == -1) { return -1; }
        if(sendInternal() == -1) { return -1; }
        if(sendInternal() == -1) { return -1; }
    }

    return 0;
}

int MVKWrapper::attributeDelete(const std::string& elt,
                                const std::string& attrType) {
    std::string request = MSG_ATTR_DEL(elt, attrType, _uuid);
    send(request.c_str());
    if(sendInternal() == -1) { return -1; }
    if(_debugMode) {
        if(sendInternal() == -1) { return -1; }
        if(sendInternal() == -1) { return -1; }
    }

    return 0;
}

int MVKWrapper::attributeDefine(const std::string& elt,
                                const std::string& attrType,
                                const std::string& attrName) {
    std::string request = MSG_ATTR_DEFINE(elt, attrType, attrName, _uuid);
    send(request.c_str());
    if(sendInternal() == -1) { return -1; }
    if(_debugMode) {
        if(sendInternal() == -1) { return -1; }
        if(sendInternal() == -1) { return -1; }
        if(sendInternal() == -1) { return -1; }
    }
    return 0;
}

int MVKWrapper::attributeSetCode(const std::string& elt,
                                 const std::string& attrType,
                                 const std::string& attrValue) {
    std::string request = MSG_ATTR_SET_CODE(elt, attrType, attrValue, _uuid);
    send(request.c_str());
    if(sendInternal() == -1) { return -1; }
    if(_debugMode) {
        if(sendInternal() == -1) { return -1; }
        if(sendInternal() == -1) { return -1; }
        if(sendInternal() == -1) { return -1; }
    }

    return 0;
}


// -----------------------------------------------------------------------------
// Static Debug
// -----------------------------------------------------------------------------

static void MVKDebugDump(const char *text, FILE *stream, unsigned char *ptr,
                         size_t size, char nohex) {
    size_t i;
    size_t c;

    unsigned int width = 0x10;

    if(nohex)
        /* without the hex output, we can fit more on screen */
        width = 0x40;

    fprintf(stream, "%s, %10.10lu bytes (0x%8.8lx)\n", text, size, size);

    for (i = 0; i < size; i += width) {
        fprintf(stream, "%4.4lx: ", i);

        if(!nohex) {
            /* hex not disabled, show it */
            for (c = 0; c < width; c++) {
                if(i + c < size)
                    fprintf(stream, "%02x ", ptr[i + c]);
                else
                    fputs("   ", stream);
            }
        }

        for (c = 0; (c < width) && (i + c < size); c++) {
            /* check for 0D0A; if found, skip past and start a new line of output */
            if(nohex && (i + c + 1 < size) && ptr[i + c] == 0x0D &&
                    ptr[i + c + 1] == 0x0A) {
                i += (c + 2 - width);
                break;
            }
            fprintf(stream, "%c",
                    (ptr[i + c] >= 0x20) && (ptr[i + c] < 0x80) ? ptr[i + c]
                                                                : '.');
            /* check again for 0D0A, to avoid an extra \n if it's at width */
            if(nohex && (i + c + 2 < size) && ptr[i + c + 1] == 0x0D &&
                ptr[i + c + 2] == 0x0A) {
                i += (c + 3 - width);
                break;
            }
        }
        fputc('\n', stream);
    }
    fflush(stream);
}

static int MVKDebugTrace(CURL *handle, curl_infotype type, char *data,
                              size_t size, void *userp) {
    struct MVKDebugData *config = (struct MVKDebugData *) userp;
    const char *text;
    (void) handle; /* prevent compiler warning */

    switch (type) {
        case CURLINFO_TEXT:
            fprintf(stderr, "== Info: %s", data);
        case CURLINFO_HEADER_OUT:
            text = "=> Send header";
            break;
        case CURLINFO_DATA_OUT:
            text = "=> Send data";
            break;
        case CURLINFO_SSL_DATA_OUT:
            text = "=> Send SSL data";
            break;
        case CURLINFO_HEADER_IN:
            text = "<= Recv header";
            break;
        case CURLINFO_DATA_IN:
            text = "<= Recv data";
            break;
        case CURLINFO_SSL_DATA_IN:
            text = "<= Recv SSL data";
            break;

        default: /* In case a new one is introduced to shock us */
            return 0;
    }

    MVKDebugDump(text, stderr, (unsigned char*) data, size, config->trace_ascii);
    return 0;
}
