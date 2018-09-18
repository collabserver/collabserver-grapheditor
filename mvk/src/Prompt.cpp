#include "Prompt.h"

#include <iostream>


// -----------------------------------------------------------------------------
// Core prompt
// -----------------------------------------------------------------------------

void Prompt::runPrompt() {
    std::cout << "Modelverse C++ shell" << std::endl;
    connection();
    //enterMegaModellingMode();
}

void Prompt::connection() {
    using namespace std;


    string ip;
    string port;
    string username;
    string password;

    cout << "Connect to Modelverse Database server.\n";
    cout << "IP address: "; cin >> ip;
    cout << "Port: ";       cin >> port;
    cout << "Username: ";   cin >> username;
    cout << "Password: ";   cin >> password;

    cout << "Connecting to Modelverse... " << endl;
    // TODO
    //_db.setConnectionAdress(completeAdress);
    //_db.connect(username, password);
}

void Prompt::enterMegaModellingMode() {
    using namespace std;
    cout << "Entering Mega Modelling mode ('exit' to leave)" << endl;

    string userAnswer;
    /*
     * TODO TMP COMMENTED
    do {
        cin >> userAnswer;
        if(userAnswer == "model_list") {
            cout << "Location ?\n";
            cin >> userAnswer;
            _db.modelList(userAnswer);
            cout << _db.getDatabaseAnswer() << "\n";
        }
        else if(userAnswer == "model_add") {
            cout << "Model type ?\n";
            string modelType;
            cin >> modelType;
            cout << "Name of the new model ?\n";
            cin >> userAnswer;
            _db.modelAdd(userAnswer, modelType, "");
            cout << _db.getDatabaseAnswer() << "\n";
        }
        else if(userAnswer == "model_delete") {
            cout << "Name of the model to delete ?\n";
            cin >> userAnswer;
            _db.modelDelete(userAnswer);
            cout << _db.getDatabaseAnswer() << "\n";
        }
        else if(userAnswer == "model_modify") {
            cout << "Model name you want to modify ?\n";
            string workingModel;
            cin >> workingModel;
            cout << "Model Type ?\n";
            cin >> userAnswer;
            _db.modelModify(workingModel, userAnswer);
            if(_db.getDatabaseAnswer() ==
                "\"Model loaded, ready for commands!\"") {
                enterModellingMode();
            }
            else {
                cout << "Impossible to modify the model you want.\n";
            }
        } else {
            cout << "Unknown Command !\n";
        }
    } while (userAnswer != "exit");
    */
    cout << "Exit of the shell succesfull\n";
}

void Prompt::enterModellingMode() {
    using namespace std;
    cout << "You're now in the modelling mode\n";

    string userAnswer;
    /*
     * TODO TMP COMMENTED
    do {
        cin >> userAnswer;
        if(userAnswer == "list_full") {
            _db.listFull();
            cout << _db.getDatabaseAnswer() << "\n";
        }
        else if(userAnswer == "JSON") {
            _db.listFullJSON();
            cout << _db.getDatabaseAnswer() << "\n";
        }
        else if(userAnswer == "instantiate_node") {
            cout << "Element Type ?\n";
            string elementType;
            cin >> elementType;
            cout << "Name of new Element ?\n";
            cin >> userAnswer;
            _db.instantiateNode(elementType, userAnswer);
            cout << _db.getDatabaseAnswer() << "\n";
        }
        else if(userAnswer == "instantiate_edge") {
            cout << "Element Type ?\n";
            string elementType;
            cin >> elementType;
            cout << "Name of new Element ?\n";
            string elementName;
            cin >> elementName;
            cout << "Source of the edge ?\n";
            string source;
            cin >> source;
            cout << "Target of the edge ?\n";
            cin >> userAnswer;
            _db.instantiateEdge(elementType, elementName, source,
                                     userAnswer);
            cout << _db.getDatabaseAnswer() << "\n";
        }
        else if(userAnswer == "delete_element") {
            cout << "Element to delete ?\n";
            cin >> userAnswer;
            _db.deleteElement(userAnswer);
            cout << _db.getDatabaseAnswer() << "\n";
        }
        else if(userAnswer == "attr_add") {
            cout << "Element to modify ?\n";
            string element;
            cin >> element;
            cout << "Type of the new attribute ?\n";
            string attributeType;
            cin >> attributeType;
            cout << "Value of the attribute ?\n";
            cin >> userAnswer;

            _db.attributeAddModify(element, attributeType, userAnswer);
        }
        else if(userAnswer == "attr_del") {
            cout<<"Element to modify ?\n";
            string element;
            cin >> element;
            cout<<"Attribute to delete ?\n";
            cin >> userAnswer;

            _db.attributeDelete(element, userAnswer);
        }
        else {
            cout << "Unknown Command !\n";
        }
    } while (userAnswer != "exit");
    */

    cout << "Exiting modelling prompt and going back to mega modelling shell!";
    cout << endl;

    _db.modelExit();
}


