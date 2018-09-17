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
    if (isDebugMode()) {
        log->close();
        delete log;
        log = nullptr;
    }
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

const std::string MVKWrapper::getCleanDatabaseAnswer() const {
    std::string res = "";
    if (databaseAnswer.length() > 11) {
        res = databaseAnswer.substr(10, databaseAnswer.length() - 11);
    }
    return res;
}

void MVKWrapper::setDatabaseAnswer(const std::string &databaseAnswer) {
    MVKWrapper::databaseAnswer = databaseAnswer;
}

void MVKWrapper::send(const char *data) {
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, -1L);

    CURLcode curlAnswer = curl_easy_perform(curl);
    if (isDebugMode()) {
        *log << "Sending : " << data << "\n   Answer : "
             << databaseAnswer << "\n";
    }
    curlError(curlAnswer);
}

bool MVKWrapper::receive() {
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, receiveRequest.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, -1L);

    CURLcode curLAnswer = curl_easy_perform(curl);
    if (isDebugMode()) {
        *log << "Sending : " << receiveRequest << "\n   Answer :"
             << databaseAnswer << "\n";
        std::cout << databaseAnswer << "\n";
    }
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

int MVKWrapper::modelVerify(const std::string savePathName,
                            const std::string modelType) {
    std::string request =
            "data=[\"verify\",\"" + savePathName + "\",\"" + modelType +
            "\"]" + baseSendRequest;
    send(request.c_str());
    if (!receive()) { return -1; }
    if (isDebugMode()) {
        if (!receive()) { return -1; }
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

int MVKWrapper::attributeAddModify(const std::string element,
                                   const std::string attributeType,
                                   const std::string attributeValue) {
    std::string request =
            "data=[\"attr_add\",\"" + element + "\",\"" + attributeType +
            "\",\"" + attributeValue + "\"]" + baseSendRequest;
    send(request.c_str());
    if (!receive()) { return -1; }
    if (isDebugMode()) {
        if (!receive()) { return -1; }
        if (!receive()) { return -1; }
        if (!receive()) { return -1; }
    }

    return 0;
}

int MVKWrapper::attributeAddModifyCode(const std::string element,
                                       const std::string attributeType,
                                       const std::string attributeValue) {
    std::string request =
            "data=[\"attr_add_code\",\"" + element + "\",\"" + attributeType +
            "\",\"" + attributeValue + "\"]" + baseSendRequest;
    send(request.c_str());
    if (!receive()) { return -1; }
    if (isDebugMode()) {
        if (!receive()) { return -1; }
        if (!receive()) { return -1; }
        if (!receive()) { return -1; }
    }

    return 0;
}

int MVKWrapper::attributeDelete(const std::string element,
                                const std::string attributeType) {
    std::string request =
            "data=[\"attr_delete\",\"" + element + "\",\"" + attributeType +
            "\"]" + baseSendRequest;
    send(request.c_str());
    if (!receive()) { return -1; }
    if (isDebugMode()) {
        if (!receive()) { return -1; }
        if (!receive()) { return -1; }
    }

    return 0;
}

int MVKWrapper::defineAttribute(const std::string element,
                                const std::string attributeName,
                                const std::string attributeType) {
    std::string request = "data=[\"define_attribute\",\"" + element + "\",\"" +
                          attributeName + "\",\"" + attributeType + "\"]" +
                          baseSendRequest;
    send(request.c_str());
    if (!receive()) { return -1; }
    if (isDebugMode()) {
        if (!receive()) { return -1; }
        if (!receive()) { return -1; }
        if (!receive()) { return -1; }
    }

    return 0;
}

void MVKWrapper::unitTest() {
    std::cout << "=== Begining of unit test ===\n\n";

    std::cout << "====== Connection test ======\n";
    MVKWrapper connector1(LOCALCONNECTIONADRESS, true);
    connector1.connect("admin", "admin");
    std::cout << "== End of connection test ==\n\n";

    std::cout << "======= Listing test =======\n";
    MVKWrapper connector2(LOCALCONNECTIONADRESS, true);
    connector2.connect("admin", "admin");
    connector2.modelList("models");
    std::cout << "=== End of listing test ===\n\n";


    std::cout << "======= Adding test =======\n";
    std::string workingModel3 = "models/cppTestModel";
    std::string modelType3 = "formalisms/SimpleClassDiagrams";
    MVKWrapper connector3(LOCALCONNECTIONADRESS, true);
    connector3.connect("admin", "admin");
    connector3.modelAdd(workingModel3, modelType3, "");
    connector3.modelList("models");
    connector3.modelDelete(workingModel3);
    connector3.modelList("models");
    std::cout << "=== End of adding test ===\n\n";

    std::cout << "====== Modifying test ======\n";
    std::string workingModel4 = "models/cppTestModel";
    std::string modelType4 = "formalisms/SimpleClassDiagrams";
    MVKWrapper connector4(LOCALCONNECTIONADRESS, true);
    connector4.connect("admin", "admin");
    connector4.modelAdd(workingModel4, modelType4, "");
    connector4.modelList("models");
    connector4.modelModify(workingModel4, modelType4);
    connector4.modelExit();
    connector4.modelDelete(workingModel4);
    connector4.modelList("models");
    std::cout << "== End of modifying test ==\n\n";

    std::cout << "======== Node test ========\n";
    std::string workingModel5 = "models/cppTestModel";
    std::string modelType5 = "formalisms/SimpleClassDiagrams";
    std::string elementType5 = "Class";
    std::string name5 = "cppTestClassNode";
    MVKWrapper connector5(LOCALCONNECTIONADRESS, true);
    connector5.connect("admin", "admin");
    connector5.modelAdd(workingModel5, modelType5, "");
    connector5.modelList("models");
    connector5.modelModify(workingModel5, modelType5);
    connector5.listFull();
    connector5.JSON();
    connector5.instantiateNode(elementType5, name5);
    connector5.listFull();
    connector5.JSON();
    connector5.deleteElement(name5);
    connector5.listFull();
    connector5.JSON();
    connector5.modelExit();
    connector5.modelDelete(workingModel5);
    connector5.modelList("models");
    std::cout << "==== End of node test ====\n\n";

    std::cout << "======== Edge test ========\n";
    std::string workingModel6 = "models/cppTestModel";
    std::string modelType6 = "formalisms/SimpleClassDiagrams";
    std::string elementType16 = "Class";
    std::string elementType26 = "Association";
    std::string nameA6 = "cppTestClassNode1";
    std::string nameB6 = "cppTestClassNode2";
    std::string nameC6 = "cppTestClassEdge";
    MVKWrapper connector6(LOCALCONNECTIONADRESS, true);
    connector6.connect("admin", "admin");
    connector6.modelAdd(workingModel6, modelType6, "");
    connector6.modelList("models");
    connector6.modelModify(workingModel6, modelType6);
    connector6.instantiateNode(elementType16, nameA6);
    connector6.instantiateNode(elementType16, nameB6);
    connector6.instantiateEdge(elementType26, nameC6, nameA6, nameB6);
    connector6.listFull();
    connector6.deleteElement(nameA6);
    connector6.deleteElement(nameB6);
    // connector6.deleteElement(name3); // Not necessary because it's automatic
    connector6.listFull();
    connector6.modelExit();
    connector6.modelDelete(workingModel6);
    connector6.modelList("models");
    std::cout << "==== End of edge test ====\n\n";

    std::cout << "====== Attribute test ======\n";
    std::string workingModel7 = "models/cppTestModel";
    std::string modelType7 = "formalisms/SimpleClassDiagrams";
    std::string elementType7 = "Class";
    std::string attributeType7 = "name";
    std::string elementName7 = "cppTestClassNode";
    MVKWrapper connector7(LOCALCONNECTIONADRESS, true);
    connector7.connect("admin", "admin");
    connector7.modelAdd(workingModel7, modelType7, "");
    connector7.modelList("models");
    connector7.modelModify(workingModel7, modelType7);
    connector7.listFull();
    connector7.instantiateNode(elementType7, elementName7);
    connector7.attributeAddModify(elementName7, attributeType7,
                                 "Valeur Atribut");
    connector7.listFull();
    connector7.JSON();
    connector7.attributeAddModify(elementName7, attributeType7,
                                 "Nouvelle Valeur");
    connector7.listFull();
    connector7.JSON();
    connector7.attributeDelete(elementName7, attributeType7);
    connector7.listFull();
    connector7.JSON();
    connector7.deleteElement(elementName7);
    connector7.listFull();
    connector7.modelExit();
    connector7.modelDelete(workingModel7);
    connector7.modelList("models");
    std::cout << "== End of attribute test ==\n\n";

    std::cout << "===== End of unit test =====\n";
}

void MVKWrapper::initCurl() {
    curl_global_init(CURL_GLOBAL_ALL); // Init of curl
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, this->connectionAdress.c_str());
    if (isDebugMode()) {
        log = new std::ofstream("log.txt", std::ios::trunc);
    }
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




