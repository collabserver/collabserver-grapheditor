#pragma once

#include <iostream>

#include <curl/curl.h>


/**
 * \brief C++ Wrapper for Modelverse Database.
 *
 * Wrapper C++ to communicate with a Modelverse Database.
 */
class MVKWrapper {
    // -------------------------------------------------------------------------
    // Attributes
    // -------------------------------------------------------------------------

    private:
        /** Curl object for communication */
        CURL* _curl = nullptr;

        /** Unique identifier for modelverse authentification */
        std::string _uuid;

        /** The adresse/port where request are sent */
        std::string _address;

        /** A general part of the sending request */
        std::string baseSendRequest;

        /** The receving request */
        std::string receiveRequest;

        /** Boolean to set the mvk verbose */
        bool _debugMode = false;

        /** The last answer of Modelverse */
        std::string databaseAnswer;


    // -------------------------------------------------------------------------
    // Init / Constructor
    // -------------------------------------------------------------------------

    private:

        /** Basic stuff for curl initialisation*/
        void initCurl();

    public:

        /**
         * Basic constructor for local Modelverse
         */
        MVKWrapper();

        MVKWrapper(const char* ip, const int port, bool debugMode = false);

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


    // -------------------------------------------------------------------------
    // Network
    // -------------------------------------------------------------------------

    public:

        /**
         * Send a connection request to Modelverse,
         * at the end you are in megamodeling mode.
         *
         * \post you are in megamodeling mode
         * \param username username for connection
         * \param password password for connection
         * \return -1 if there is a detected error
         */
        int connect(const std::string username, const std::string password);

        /**
         * Send the data parameter to Modelverse.
         * \param data what we send to Moderlverse without adding anything.
         */
        void send(const char *data);

        /**
         * Ask for the answer of Modelverse
         * \return false if there is a detected error with Modelverse
         */
        bool receive();


    // -------------------------------------------------------------------------
    // Models management
    // -------------------------------------------------------------------------

    public:

        /**
         * Show all models/files in path.
         *
         * \pre being in megamodeling mode.
         * \param path PWD to use.
         * \return 0 if success, otherwise, -1
         */
        int modelList(const std::string path);

        /**
         * Add a new model to Modelverse.
         *
         * \pre being in megamodeling mode.
         * \param savePathName the place and the name of the new model
         * \param modelType the metamodel of the new model
         * \param textualRepresentation the base model used to create you new model
         *      (send a void string for an empty model)
         * \return -1 if there is a detected error
         */
        int modelAdd(const std::string savePathName, const std::string modelType,
                     const std::string textualRepresentation);

        /**
         * Delete specific model.
         *
         * \pre being in megamodeling mode.
         * \param path Model you want to delete.
         * \return 0 if success, otherwise, return -1.
         */
        int modelDelete(const std::string path);

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
         * Start the modeling mode in the model in parameter.
         *
         * \pre being in megamodeling mode
         * \post you are in modeling mode
         * \param workingModel the model you want to modify
         * \param modelType the metamodel of the model
         * \return -1 if there is a detected error
         */
        int modelModify(const std::string workingModel, const std::string modelType);

        /**
         * Exit the modeling mode and return to the megamodelling mode
         * \pre being in modeling mode
         * \post you are in megamodeling mode
         * \return -1 if there is a detected error
         */
        int modelExit();

    // -------------------------------------------------------------------------
    // Model
    // -------------------------------------------------------------------------

    public:

        /**
         * Shows all the element of the model.
         * \pre being in modeling mode.
         *
         * \return 0 if success, otherwise, return -1.
         */
        int listFull();

        /**
         * Show all the elements of the model in a JSON
         * \pre beign in modeling mode
         *
         * \return -1 if there is a detected error
         */
        int JSON();

        /**
         * Create a new element in the model
         * \pre being in modeling mode
         *
         * \param elementType the type of the new element
         * \param name the name of the new element
         * \return -1 if there is a detected error
         */
        int instantiateNode(const std::string elementType, const std::string name);

        /**
         * Create a link between two elements in the model.
         *
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


    // -------------------------------------------------------------------------
    // Getters / Setters
    // -------------------------------------------------------------------------
    public:

        const std::string& getUuid() const { return _uuid; }

        void setUuid(const std::string& uuid) { _uuid = uuid; }

        const std::string& getConnectionAdress() const { return _address; }

        void setConnectionAdress(const std::string &connectionAdress);

        bool isDebugMode() const { return _debugMode; }

        const std::string& getDatabaseAnswer() const { return databaseAnswer; }

        /**
         * Return the last database answer without uselsess information.
         *
         * Response removes "\"Success :" at the begining and "\"" at the end,
         * or an empty string if the answer is to short.
         *
         * \warning
         * There is no verification in the content of databaseAnswer
         * so use with caution.
         *
         * \return The last database answer.
         */
        const std::string getCleanDatabaseAnswer() const;

        void setDatabaseAnswer(const std::string& databaseAnswer);
};


