#pragma once

#include <regex>
#include <iostream>
#include <fstream>

#include <curl/curl.h>

#include "UuidGenerator.h"

#define LOCALCONNECTIONADRESS "http://127.0.0.1:8001"


/**
 * \brief Allows communication with Modelverse Database in C++
 *
 * This is a basic wrapper with small error detection.
 * The communication is done using HTTP Requests with the curl librairie.
 */
class MVKWrapper {

    private:
        /** Curl object for communication */
        CURL *curl;

        /** Unique identifier for modelverse authentification */
        std::string uuid;

        /** The adresse/port where request are sent */
        std::string connectionAdress;

        /** A general part of the sending request */
        std::string baseSendRequest;

        /** The receving request */
        std::string receiveRequest;

        /** Boolean to set the mvk verbose */
        bool DebugMode = false;

        /** Pointer where we store each request and answer */
        std::ofstream *log;

        /** The last answer of Modelverse */
        std::string databaseAnswer;

        /** Basic stuff for curl initialisation*/
        void initCurl();

        /** Struct for big debugging mode (not used)*/
        struct MVKDebugData {
            char trace_ascii; /* 1 or 0 */
        };

        /** Function for big debug mode (not used)*/
        static size_t
        WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);

        /** Function for big debug mode (not used)*/
        static int
        MVKDebugTrace(CURL *handle, curl_infotype type, char *data, size_t size,
                      void *userp);

        /** Function for big debug mode (not used)*/
        static void MVKDebugDump(const char *text, FILE *stream, unsigned char *ptr,
                                 size_t size, char nohex);

    public:

        /**
         * Basic constructor for local Modelverse
         */
        MVKWrapper();

        /**
         * Constructor for remote Modelverse
         * \param connectionAdress adress and port of the Modelverse database
         */
        explicit MVKWrapper(const char *connectionAdress);

        /**
         * Constructor for remote or local server with debug
         *      mode initialisation
         * \param connectionAdress adress and port of the Modelverse database
         * \param isDebugMode debug mode setting
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

        /**
         * Return the last database answer without uselsess information
         * \warning There is no verification in the content of databaseAnswer so
         *      use with caution
         * \return The last database answer (without "\"Success :" at the begining
         *      and "\"" at the end) or an empty string if the answer is to short
         */
        const std::string getCleanDatabaseAnswer() const;

        void setDatabaseAnswer(const std::string &databaseAnswer);

        /**
         * Send the data parameter to Modelverse
         * \param data what we send to Moderlverse without adding anything
         */
        void send(const char *data);

        /**
         * Ask for the answer of Modelverse
         * \return false if there is a detected error with Modelverse
         */
        bool receive();

        /**
         * Check if there is an error with curl and the request in general
         * \param curlAnswer the answer of curl after sending a request
         */
        void curlError(CURLcode curlAnswer);

        /**
         * A simple error detector for Modelverse
         * \return true if there is an error
         */
        bool functionError();

        /**
         * Send a void request
         * \return 0
         */
        int voidSending();

        /**
         * Send a connection request to Modelverse,
         *      at the end you are in megamodeling mode
         * \post you are in megamodeling mode
         * \param username username for connection
         * \param password password for connection
         * \return -1 if there is a detected error
         */
        int connect(const std::string username, const std::string password);

        /**
         * Show all models/files in path
         * \pre being in megamodeling mode
         * \param path the place we want to see
         * \return -1 if there is a detected error
         */
        int modelList(const std::string path);

        /**
         * Add a new model to Modelverse
         * \pre being in megamodeling mode
         * \param savePathName the place and the name of the new model
         * \param modelType the metamodel of the new model
         * \param textualRepresentation the base model used to create you new model
         *      (send a void string for an empty model)
         * \return -1 if there is a detected error
         */
        int modelAdd(const std::string savePathName, const std::string modelType,
                     const std::string textualRepresentation);

        /**
         * Delete the model in parameter
         * \pre being in megamodeling mode
         * \param savePathName the model you want to delete
         * \return -1 if there is a detected error
         */
        int modelDelete(const std::string savePathName);

        /**
         * Check if the model respect the metamodel
         *      if it's good databaseAnswer should be : "Success : OK"
         * \pre being in megamodeling mode
         * \param savePathName the model you want to verify
         * \param modelType the metamodel you want to use
         * \return -1 if there is a detected error
         */
        int modelVerify(const std::string savePathName, const std::string modelType);

        /**
         * Start the modeling mode in the model in parameter
         * \pre being in megamodeling mode
         * \post you are in modeling mode
         * \param workingModel the model you want to modify
         * \param modelType the metamodel of the model
         * \return -1 if there is a detected error
         */
        int
        modelModify(const std::string workingModel, const std::string modelType);

        /**
         * Exit the modeling mode and return to the megamodelling mode
         * \pre being in modeling mode
         * \post you are in megamodeling mode
         * \return -1 if there is a detected error
         */
        int modelExit();

        /**
         * Shows all the element of the model
         * \pre being in modeling mode
         * \return -1 if there is a detected error
         */
        int listFull();

        /**
         * Show all the elements of the model in a JSON
         * \pre beign in modeling mode
         * \return -1 if there is a detected error
         */
        int JSON();

        /**
         * Create a new element in the model
         * \pre being in modeling mode
         * \param elementType the type of the new element
         * \param name the name of the new element
         * \return -1 if there is a detected error
         */
        int instantiateNode(const std::string elementType, const std::string name);

        /**
         * Create a link between two elements in the model
         * \pre being in modeling mode
         * \param elementType the type of the new link
         * \param name the name of the new link
         * \param source the first element linked
         * \param target the second element linked
         * \return -1 if there is a detected error
         */
        int instantiateEdge(const std::string elementType, const std::string name,
                            const std::string source, const std::string target);

        /**
         * Delete the element in paramter (and the edge linked to him)
         * \pre being in modeling mode
         * \param name the path of the element to delete
         * \return -1 if there is a detected error
         */
        int deleteElement(const std::string name);

        /**
         * Add an attribute to the element in parameter or modify an already
         *      created element
         * \pre being in modeling mode
         * \param element the element in wich we want to add an element
         * \param attributeType the type of the element we add
         * \param attributeValue the value of the new attribute
         * \return
         */
        int attributeAddModify(const std::string element,
                               const std::string attributeType,
                               const std::string attributeValue);

        /**
         * Delete the attribute of the element in parameters
         * \pre being in modeling mode
         * \param element the element in which we want to delete
         * \param attributeType the attribute to delete
         * \return -1 if there is a detected error
         */
        int attributeDelete(const std::string element, const std::string attributeType);

        int attributeAddModifyCode(const std::string element,
                                   const std::string attributeType,
                                   const std::string attributeValue);

        /**
         * Define another attribute for the element in parameters
         * \warning Metamodeling Function
         * \param element the element in which we define the new attribute
         * \param attributeName the name of the new attribute
         * \param attributeType the type of the new attribute
         * \return
         */
        int defineAttribute(const std::string element,
                            const std::string attributeName,
                            const std::string attributeType);

        static void unitTest();
};


