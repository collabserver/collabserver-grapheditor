/**
 * @file MVKConnector.h
 * @author Robin Donnay
 * @date 28/05/18
 * @brief Class allowing communication with Modelverse Database in C++
 *
 * This is a basic wrapper with small error detection.
 * The communication is done using HTTP Requests with the curl librairie.
 * Boost librairie is also use to generate unique identifier.
 */

#ifndef MVKWRAPPER_H
#define MVKWRAPPER_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <regex>
#include <random>
#include <climits>
#include <curl/curl.h>
#include <boost/uuid/uuid.hpp> // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp> // streaming operators (cout) etc.
#include <boost/lexical_cast.hpp> // easy cast for boost datatype


// TODO Best Error Checking/Action
// TODO Fonction qui envois des écoute tant qu'il n'a pas finis de parler
// TODO Fonction qui affiche l'aide (juste au cas où)

class MVKWrapper {

#define LOCALCONNECTIONADRESS "http://127.0.0.1:8001"

private:
    /** @brief curl object for communication */
    CURL *curl;
    /** @brief unique identifier for modelverse authentification */
    std::string uuid;
    /** @brief the adresse/port where request are sent */
    std::string connectionAdress;
    /** @bief a general part of the sending request */
    std::string baseSendRequest;
    /** @brief the receving request */
    std::string receiveRequest;
    /** @brief boolean to set the mvk verbose */
    bool DebugMode = false;
    /** @brief pointer where we store each request and answer */
    std::ofstream *log;
    /** @brief the last answer of Modelverse */
    std::string databaseAnswer;

    /** @brief basic stuff for curl initialisation*/
    void initCurl();

    /** @brief struct for big debugging mode (not used)*/
    struct MVKDebugData {
        char trace_ascii; /* 1 or 0 */
    };

    /** @brief function for big debug mode (not used)*/
    static size_t
    WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);

    /** @brief function for big debug mode (not used)*/
    static int
    MVKDebugTrace(CURL *handle, curl_infotype type, char *data, size_t size,
                  void *userp);

    /** @brief function for big debug mode (not used)*/
    static void MVKDebugDump(const char *text, FILE *stream, unsigned char *ptr,
                             size_t size, char nohex);

public:

    /**
     * @fn MVKConnector();
     * @brief basic constructor for local Modelverse
     */
    MVKWrapper();

    /**
     * @brief constructor for remote Modelverse
     * @param connectionAdress adress and port of the Modelverse database
     */
    explicit MVKWrapper(const char *connectionAdress);

    /**
     * @brief constructor for remote or local server with debug
     *      mode initialisation
     * @param connectionAdress adress and port of the Modelverse database
     * @param isDebugMode debug mode setting
     */
    explicit MVKWrapper(const char *connectionAdress, const bool isDebugMode);

    ~MVKWrapper();

    const std::string &getUuid() const;

    void setUuid(const std::string &uuid);

    const std::string &getConnectionAdress() const;

    void setConnectionAdress(const std::string &connectionAdress);

    bool isDebugMode() const;

    void setDebugMode(bool isDebugMode);

    const std::string &getDatabaseAnswer() const;

    void setDatabaseAnswer(const std::string &databaseAnswer);

    /**
     * @brief send the data parameter to Modelverse
     * @param data what we send to Moderlverse without adding anything
     */
    void send(const char *data);

    /**
     * @brief ask for the answer of Modelverse
     * @return false if there is a detected error with Modelverse
     */
    bool receive();

    /**
     * @brief check if there is an error with curl and the request in general
     * @param curlAnswer the answer of curl after sending a request
     */
    void curlError(CURLcode curlAnswer);

    /**
     * @brief a simple error detector for Modelverse
     * @return true if there is an error
     */
    bool functionError();

    /**
     * @brief send a void request
     * @return 0
     */
    int voidSending();

    /**
     * @brief send a connection request to Modelverse
     * @param username username for connection
     * @param password password for connection
     * @return -1 if there is a detected error
     */
    int connect(const std::string username, const std::string password);

    /**
     * @brief 
     * @param path
     * @return
     */
    int modelList(const std::string path);

    int modelAdd(const std::string savePathName, const std::string modelType,
                 const std::string textualRepresentation);

    int modelDelete(const std::string savePathName);

    int
    modelModify(const std::string workingModel, const std::string modelType);

    int modelExit();

    int listFull();

    int JSON();

    int instantiateNode(const std::string elementType, const std::string name);

    int instantiateEdge(const std::string elementType, const std::string name,
                        const std::string source, const std::string target);

    int deleteElement(const std::string name);

    static std::string uuidGenerator();
};


#endif //MVKWRAPPER_H
