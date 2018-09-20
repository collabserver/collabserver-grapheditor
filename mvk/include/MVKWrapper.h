#pragma once

#include <string>

#include <curl/curl.h>


/**
 * \brief
 * C++ Wrapper for Modelverse Database.
 *
 * Wrapper C++ to communicate with a Modelverse Database.
 *
 * \par Modeling / MegaModeling Modes
 * During MVK connection you may be in one of the two modes.
 * - Modeling: You are currently working on a specific model.
 * - MegaModeling: Generic operations such as list models, add/remove a model...
 * Each methods may have a prerequisite in order to be applied successfully.
 * (Ex: being in modeling mode).
 *
 * \see https://msdl.uantwerpen.be/git/yentl/modelverse
 */
class MVKWrapper {
    // -------------------------------------------------------------------------
    // Attributes
    // -------------------------------------------------------------------------

    private:
        bool            _debugMode = false;
        std::string     _uuid = "";

    private:
        CURL*           _curl = nullptr;
        std::string     _buffer = ""; // The last answer of Modelverse


    // -------------------------------------------------------------------------
    // Init / Constructor
    // -------------------------------------------------------------------------

    public:

        /**
         * Create a new MVKWrapper.
         * In debug mode (debugMode = true), we get more information
         * from the MVK about ongoing requests.
         *
         * \param debugMode Set the debug mode.
         */
        MVKWrapper(bool debugMode = false);

        ~MVKWrapper();


    // -------------------------------------------------------------------------
    // Connection
    // -------------------------------------------------------------------------

    public:

        /**
         * Connect to a remote MVK database and login given user.
         *
         * \post you are in megamodeling mode.
         * \param ip Server IP.
         * \param port Server port.
         * \param username Username as registered in MVK.
         * \param pswd Password as registered in MVK.
         * \return -1 if there is a detected error.
         */
        int connect(const std::string& ip, const int port,
                    const std::string& username, const std::string& pswd);

        /**
         * Disconnect from MVK. Do nothing if not connected yet.
         * Logout user and disconnect from server.
         *
         * \return -1 if there is a detected error.
         */
        int disconnect();

    private:

        /**
         * Connect to MVK (But doesn't log as a user).
         *
         * \param ip Server IP.
         * \param port Server port.
         * \return -1 if there is a detected error.
         */
        int connectMVK(const std::string& ip, const int port);

        /**
         * Disconnect from MVK server.
         * \return -1 if there is a detected error.
         */
        int disconnectMVK();

        /**
         * Log as user.
         * You must be connected to MVK server first.
         *
         * \param username Username as registered in MVK.
         * \param pswd Password as registered in MVK.
         * \return -1 if there is a detected error.
         */
        int login(const std::string& username, const std::string& pswd);

        /**
         * Logout current user.
         * You must be loged.
         * \return -1 if there is a detected error.
         */
        int logout();


    // -------------------------------------------------------------------------
    // Models management
    // -------------------------------------------------------------------------

    public:

        /**
         * Show all models/files in path.
         * \pre Being in megamodeling mode.
         *
         * \param path PWD to use.
         * \return -1 if there is a detected error.
         */
        int modelList(const std::string& path);

        /**
         * Add a new model to Modelverse.
         * \pre Being in megamodeling mode.
         *
         * \param name Model name (Its full path).
         * \param mmodel Metamodel of the new model.
         * \param syntax Base model to use (Or empty for empty model).
         * \return -1 if there is a detected error.
         */
        int modelAdd(const std::string& name, const std::string& mmodel,
                     const std::string& syntax);

        /**
         * Delete a model.
         * \pre Being in megamodeling mode.
         *
         * \param name Model to delete.
         * \return -1 if there is a detected error.
         */
        int modelDelete(const std::string& name);

        /**
         * Check if the model respect the metamodel.
         * Expect message "Success : OK" if respect metamodel.
         * \pre Being in megamodeling mode.
         *
         * \param model Model to validate.
         * \param mmodel Metamodel to use.
         * \return -1 if there is a detected error.
         */
        int modelVerify(const std::string& model, const std::string& mmodel);

        /**
         * Work on a specific model.
         * This start the MVK to be in modeling mode for the requested model.
         *
         * \pre Being in megamodeling mode.
         * \post You are in modeling mode.
         *
         * \param model Model to work on.
         * \param mmodel Model's metamodel.
         * \return -1 if there is a detected error.
         */
        int modelEnter(const std::string& model, const std::string& mmodel);

        /**
         * Exit the modeling mode and return to the megamodeling mode.
         *
         * \pre Being in modeling mode.
         * \post You are in megamodeling mode.
         *
         * \return -1 if there is a detected error.
         */
        int modelExit();


    // -------------------------------------------------------------------------
    // Model
    // -------------------------------------------------------------------------

    public:

        /**
         * Request to list all elements in current model.
         * \pre Being in modeling mode.
         *
         * \return -1 if there is a detected error.
         */
        int elementList();

        /**
         * Request list of all elements in current model (JSON format).
         * \pre Being in modeling mode.
         *
         * \return -1 if there is a detected error.
         */
        int elementListJSON();

        /**
         * Create a new element in current model.
         * \pre Being in modeling mode.
         *
         * \param type Type of the new element.
         * \param name Name of the new element.
         * \return -1 if there is a detected error.
         */
        int elementCreate(const std::string& type, const std::string& name);

        /**
         * Delete given element and all its edges.
         * \pre Being in modeling mode.
         *
         * \param name Path of the element to delete.
         * \return -1 if there is a detected error.
         */
        int elementDelete(const std::string& name);

        /**
         * Create a link between two elements in current model.
         * \pre Being in modeling mode.
         *
         * \param type Type of the new link.
         * \param name Name of the new link
         * \param from First element linked.
         * \param to Second element linked.
         * \return -1 if there is a detected error.
         */
        int edgeCreate(const std::string& type , const std::string& name,
                       const std::string& from, const std::string& to);

        /**
         * Set attribute value in element. Create attribute if doesn't exists.
         * Modify previous value if exists.
         * \pre Being in modeling mode
         *
         * \param element Element to modify.
         * \param attrType Type of attribute to add.
         * \param attrValue Value of the new attribute.
         * \return -1 if there is a detected error.
         */
        int attributeSet(const std::string& element,
                         const std::string& attrType,
                         const std::string& attrValue);

        /**
         * Delete attribute from element.
         * \pre Being in modeling mode
         *
         * \param elt Element where attribute is.
         * \param attr Attribute to delete
         * \return -1 if there is a detected error.
         */
        int attributeDelete(const std::string& elt, const std::string& attr);

        /**
         * Define another attribute in element.
         * \pre Being in modeling mode
         *
         * \warning
         * MetaModeling Function
         *
         * \param element Element to work on.
         * \param attrType Type of the new attribute.
         * \param attrName Name of the new attribute.
         * \return -1 if there is a detected error.
         */
        int attributeDefine(const std::string& element,
                            const std::string& attrType,
                            const std::string& attrName);

        /**
         * TODO: This methods is not validated yet, don't use it.
         * \pre Being in modeling mode
         */
        int attributeSetCode(const std::string& element,
                             const std::string& attrType,
                             const std::string& attrName);


    // -------------------------------------------------------------------------
    // Network
    // -------------------------------------------------------------------------

    private:

        /**
         * Send data to Modelverse and update buffer with its response.
         * Block until response.
         *
         * \param data Raw data to send to MVK. (MVK format).
         */
        void send(const char* data);

        /**
         * Internal send method.
         *
         * \return -1 if there is a detected error.
         */
        bool sendInternal();


    // -------------------------------------------------------------------------
    // Getters / Setters
    // -------------------------------------------------------------------------
    public:
        const std::string& getDatabaseAnswer() const { return _buffer; }

        /**
         * Return the last database answer with clean format.
         * Removes "\"Success :" at the beginning and "\"" at the end.
         * (Or empty string if the answer is to short).
         *
         * \return Last database answer with clean format.
         */
        const std::string getCleanDatabaseAnswer() const;
};


