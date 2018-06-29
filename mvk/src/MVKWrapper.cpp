//
// Created by robin on 28/05/18.
//

#include "MVKWrapper.h"

MVKWrapper::MVKWrapper() {
    uuid = UuidGenerator::basicGenerator();
    connectionAdress = LOCALCONNECTIONADRESS;
    DebugMode = false;
    initCurl();
}

MVKWrapper::MVKWrapper(const char *connectionAdress) {
    uuid = UuidGenerator::basicGenerator();
    this->connectionAdress = connectionAdress;
    DebugMode = false;
    initCurl();
}

MVKWrapper::MVKWrapper(const char *connectionAdress,
                       const bool isDebugMode) {
    uuid = UuidGenerator::basicGenerator();
    this->connectionAdress = connectionAdress;
    this->DebugMode = isDebugMode;
    initCurl();
}

MVKWrapper::~MVKWrapper() {
    log->close();
    delete log;
    log = nullptr;
    curl_easy_cleanup(curl);
    curl_global_cleanup(); // Cleaning of curl
}

const std::string &MVKWrapper::getUuid() const {
    return uuid;
}

void MVKWrapper::setUuid(const std::string &uuid) {
    this->uuid = uuid;
}

const std::string &MVKWrapper::getConnectionAdress() const {
    return connectionAdress;
}

void MVKWrapper::setConnectionAdress(const std::string &connectionAdress) {
    this->connectionAdress = connectionAdress;
    curl_easy_setopt(curl, CURLOPT_URL, this->connectionAdress.c_str());
}

bool MVKWrapper::isDebugMode() const {
    return DebugMode;
}

void MVKWrapper::setDebugMode(bool isDebugMode) {
    this->DebugMode = isDebugMode;
}

const std::string &MVKWrapper::getDatabaseAnswer() const {
    return databaseAnswer;
}

void MVKWrapper::setDatabaseAnswer(const std::string &databaseAnswer) {
    MVKWrapper::databaseAnswer = databaseAnswer;
}

void MVKWrapper::send(const char *data) {
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, -1L);

    // TODO Juste mettre la data (sans le uid) dans les infos du log
    CURLcode curlAnswer = curl_easy_perform(curl);
    *log << "Sending : " << data << "\n   Answer : "
         << databaseAnswer << "\n";
    curlError(curlAnswer);
}

bool MVKWrapper::receive() {
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, receiveRequest.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, -1L);

    CURLcode curLAnswer = curl_easy_perform(curl);
    *log << "Sending : " << receiveRequest << "\n   Answer :"
         << databaseAnswer << "\n";
    if (isDebugMode()) { std::cout << databaseAnswer << "\n"; }
    curlError(curLAnswer);
    if (functionError()) {
        return false;
    }
    return true;

}

void MVKWrapper::curlError(CURLcode curlAnswer) {
    if (curlAnswer != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(curlAnswer));
    }
}

bool MVKWrapper::functionError() {
    // TODO Improve function success or fail

    std::regex unknownCommand("^\"[Uu]nknown command");
    std::regex success("^\"Success");
    if (std::regex_search(databaseAnswer, unknownCommand)) {
        return true;
    }
    /*if (!isDebugMode()) {
        if (std::regex_search(databaseAnswer, success) ||
            databaseAnswer == "Model loaded, ready for commands!") {
            return false;
        } else {
            return true;
        }
    }*/
    return false;
}

int MVKWrapper::voidSending() {
    std::string request =
            "value=\"\"" + baseSendRequest;
    send(request.c_str());
    receive();

    return 0;
}

int MVKWrapper::connect(const std::string username,
                        const std::string password) {
    std::string request =
            "op=set_input&value=\"" + uuid + "\"&taskname=task_manager";
    send(request.c_str());
    if (!receive()) { return -1; }

    request = "value=\"" + username + "\"" + baseSendRequest;
    send(request.c_str());
    if (!receive()) { return -1; }

    std::regex newUser("^[A-Za-z \"]+new user");
    if (std::regex_search(databaseAnswer, newUser)) {
        request = "value=\"" + password + "\"" + baseSendRequest;
        send(request.c_str());
        if (!receive()) { return -1; }
    }

    request = "value=\"" + password + "\"" + baseSendRequest;
    send(request.c_str());
    if (!receive()) { return -1; }
    if (!receive()) { return -1; }

    if (!isDebugMode()) {
        request = "value=\"quiet\"" + baseSendRequest;
        send(request.c_str());
    }

    return 0;
}

int MVKWrapper::modelList(const std::string path) {
    std::string request =
            "data=[\"model_list\",\"" + path + "\"]" + baseSendRequest;
    send(request.c_str());
    if (!receive()) { return -1; }
    if (isDebugMode()) {
        if (!receive()) { return -1; }
    }

    return 0;
}

int MVKWrapper::modelAdd(const std::string savePathName,
                         const std::string modelType,
                         const std::string textualRepresentation) {
    std::string request =
            "data=[\"model_add\",\"" + modelType + "\",\"" + savePathName +
            "\",\"" + textualRepresentation + "\"]" + baseSendRequest;
    send(request.c_str());
    if (!receive()) { return -1; }
    if (isDebugMode()) {
        if (!receive()) { return -1; }
        if (!receive()) { return -1; }
        if (!receive()) { return -1; }
    }

    return 0;
}

int MVKWrapper::modelDelete(const std::string savePathName) {
    std::string request =
            "data=[\"model_delete\",\"" + savePathName + "\"]" +
            baseSendRequest;
    send(request.c_str());
    if (!receive()) { return -1; }
    if (isDebugMode()) {
        if (!receive()) { return -1; }
    }

    return 0;
}

int MVKWrapper::modelModify(const std::string workingModel,
                            const std::string modelType) {
    std::string request =
            "data=[\"model_modify\",\"" + workingModel + "\",\"" + modelType +
            "\"]" + baseSendRequest;
    send(request.c_str());
    if (!receive()) { return -1; }
    if (isDebugMode()) {
        if (!receive()) { return -1; }
        if (!receive()) { return -1; }
    }

    return 0;
}

int MVKWrapper::modelExit() {
    std::string request =
            "value=\"exit\"" + baseSendRequest;
    send(request.c_str());
    if (!receive()) { return -1; }

    return 0;
}

int MVKWrapper::listFull() {
    std::string request =
            "value=\"list_full\"" + baseSendRequest;
    send(request.c_str());
    if (!receive()) { return -1; }

    return 0;
}

int MVKWrapper::JSON() {
    std::string request =
            "value=\"JSON\"" + baseSendRequest;
    send(request.c_str());
    if (!receive()) { return -1; }

    return 0;
}

int MVKWrapper::instantiateNode(const std::string elementType,
                                const std::string name) {
    std::string request =
            "data=[\"instantiate_node\",\"" + elementType + "\",\"" + name +
            "\"]" + baseSendRequest;
    send(request.c_str());
    if (!receive()) { return -1; }
    if (isDebugMode()) {
        if (!receive()) { return -1; }
        if (!receive()) { return -1; }
    }
    return 0;
}

int MVKWrapper::instantiateEdge(const std::string elementType,
                                const std::string name,
                                const std::string source,
                                const std::string target) {
    std::string request =
            "data=[\"instantiate_edge\",\"" + elementType + "\",\"" + name +
            "\",\"" + source + "\",\"" + target + "\"]" + baseSendRequest;
    send(request.c_str());
    if (!receive()) { return -1; }
    if (isDebugMode()) {
        if (!receive()) { return -1; }
        if (!receive()) { return -1; }
        if (!receive()) { return -1; }
        if (!receive()) { return -1; }
    }
    return 0;
}

int MVKWrapper::deleteElement(const std::string name) {
    std::string request =
            "data=[\"delete\",\"" + name + "\"]" + baseSendRequest;
    send(request.c_str());
    if (!receive()) { return -1; }
    if (isDebugMode()) {
        if (!receive()) { return -1; }
    }

    return 0;
}

void MVKWrapper::initCurl() {
    curl_global_init(CURL_GLOBAL_ALL); // Init of curl
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, this->connectionAdress.c_str());
    log = new std::ofstream("log.txt", std::ios::trunc);
    databaseAnswer = "";

    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &databaseAnswer);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    // This part usefull in case of we need a really big debug mode
    /* if (DebugMode) {
        MVKDebugData config;
        curl_easy_setopt(curl, CURLOPT_DEBUGFUNCTION, MVKDebugTrace);
        curl_easy_setopt(curl, CURLOPT_DEBUGDATA, &config);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
    }*/

    baseSendRequest = "&op=set_input&taskname=" + uuid;
    receiveRequest = "op=get_output&taskname=" + uuid;
}

size_t MVKWrapper::WriteCallback(void *contents, size_t size, size_t nmemb,
                                 void *userp) {
    ((std::string *) userp)->clear();
    ((std::string *) userp)->append((char *) contents, size * nmemb);
    return size * nmemb;
}

void MVKWrapper::MVKDebugDump(const char *text, FILE *stream,
                              unsigned char *ptr, size_t size, char nohex) {
    size_t i;
    size_t c;

    unsigned int width = 0x10;

    if (nohex)
        /* without the hex output, we can fit more on screen */
        width = 0x40;

    fprintf(stream, "%s, %10.10lu bytes (0x%8.8lx)\n",
            text, size, size);

    for (i = 0; i < size; i += width) {

        fprintf(stream, "%4.4lx: ", i);

        if (!nohex) {
            /* hex not disabled, show it */
            for (c = 0; c < width; c++)
                if (i + c < size)
                    fprintf(stream, "%02x ", ptr[i + c]);
                else
                    fputs("   ", stream);
        }

        for (c = 0; (c < width) && (i + c < size); c++) {
            /* check for 0D0A; if found, skip past and start a new line of output */
            if (nohex && (i + c + 1 < size) && ptr[i + c] == 0x0D &&
                ptr[i + c + 1] == 0x0A) {
                i += (c + 2 - width);
                break;
            }
            fprintf(stream, "%c",
                    (ptr[i + c] >= 0x20) && (ptr[i + c] < 0x80) ? ptr[i + c]
                                                                : '.');
            /* check again for 0D0A, to avoid an extra \n if it's at width */
            if (nohex && (i + c + 2 < size) && ptr[i + c + 1] == 0x0D &&
                ptr[i + c + 2] == 0x0A) {
                i += (c + 3 - width);
                break;
            }
        }
        fputc('\n', stream); /* newline */
    }
    fflush(stream);
}

int MVKWrapper::MVKDebugTrace(CURL *handle, curl_infotype type, char *data,
                              size_t size, void *userp) {
    struct MVKDebugData *config = (struct MVKDebugData *) userp;
    const char *text;
    (void) handle; /* prevent compiler warning */

    switch (type) {
        case CURLINFO_TEXT:
            fprintf(stderr, "== Info: %s", data);
            /* FALLTHROUGH */
        default: /* in case a new one is introduced to shock us */
            return 0;

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
    }

    MVKDebugDump(text, stderr, (unsigned char *) data, size,
                 config->trace_ascii);
    return 0;
}




