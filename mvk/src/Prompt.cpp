//
// Created by robin on 20/06/18.
//

#include "../include/Prompt.h"

void Prompt::runPrompt() {
    std::cout << "Welcome to local shell for Modelverse C++ !\n";
    connection();
    megaModelling();
}

void Prompt::connection() {
    using namespace std;

    string userAnswer;
    cout << "Please choose if you want to connect with a local modelverse "
            "or a remote one.\n";

    do {
        userAnswer = getUserAnswer();
        if ((userAnswer != "local" && userAnswer != "remote")) {
            cout << "Write 'local' if you want to connect to a local Modelverse"
                    "\nor 'remote' if you want to connect to a distant one.\n";
        }
    } while (userAnswer != "local" && userAnswer != "remote");
    if (userAnswer != "local") {
        string completeAdress;
        cout << "Connection adress :\n";
        userAnswer = getUserAnswer();
        completeAdress = userAnswer;
        cout << "Port :\n";
        userAnswer = getUserAnswer();
        completeAdress += ":" + userAnswer;
        database.setConnectionAdress(completeAdress);
    }
    //database.setDebugMode(true);

    cout << "Please write your username\n";
    string username = getUserAnswer();
    cout << "Please write your password\n";
    userAnswer = getUserAnswer();
    database.connect(username, userAnswer);
}


void Prompt::megaModelling() {
    using namespace std;
    cout << "You are now in the Mega Modelling of Modelverse.\n"
            "You can exit using the command 'exit'.\n";
    string userAnswer;

    do {
        userAnswer = getUserAnswer();
        if (userAnswer == "model_list") {
            cout << "Location ?\n";
            userAnswer = getUserAnswer();
            database.modelList(userAnswer);
            cout << database.getDatabaseAnswer() << "\n";
        } else if (userAnswer == "model_add") {
            cout << "Model type ?\n";
            string modelType = getUserAnswer();
            cout << "Name of the new model ?\n";
            userAnswer = getUserAnswer();
            database.modelAdd(userAnswer, modelType, "");
            cout << database.getDatabaseAnswer() << "\n";
        } else if (userAnswer == "model_delete") {
            cout << "Name of the model to delete ?\n";
            userAnswer = getUserAnswer();
            database.modelDelete(userAnswer);
            cout << database.getDatabaseAnswer() << "\n";
        } else if (userAnswer == "model_modify") {
            cout << "Model name you want to modify ?\n";
            string workingModel = getUserAnswer();
            cout << "Model Type ?\n";
            userAnswer = getUserAnswer();
            database.modelModify(workingModel, userAnswer);
            if (database.getDatabaseAnswer() ==
                "\"Model loaded, ready for commands!\"") {
                modelling();
            } else {
                cout << "Impossible to modify the model you want.\n";
            }
        } else {
            cout << "Unknown Command !\n";
        }
    } while (userAnswer != "exit");
    cout << "Exit of the shell succesfull\n";
}

void Prompt::modelling() {
    using namespace std;
    cout << "You're now in the modelling mode\n";

    string userAnswer;
    do {
        userAnswer = getUserAnswer();
        if (userAnswer == "list_full") {
            database.listFull();
            cout << database.getDatabaseAnswer() << "\n";
        } else if (userAnswer == "JSON") {
            database.JSON();
            cout << database.getDatabaseAnswer() << "\n";
        } else if (userAnswer == "instantiate_node") {
            cout << "Element Type ?\n";
            string elementType = getUserAnswer();
            cout << "Name of new Element ?\n";
            userAnswer = getUserAnswer();
            database.instantiateNode(elementType, userAnswer);
            cout << database.getDatabaseAnswer() << "\n";
        } else if (userAnswer == "instantiate_edge") {
            cout << "Element Type ?\n";
            string elementType = getUserAnswer();
            cout << "Name of new Element ?\n";
            string elementName = getUserAnswer();
            cout << "Source of the edge ?\n";
            string source = getUserAnswer();
            cout << "Target of the edge ?\n";
            userAnswer = getUserAnswer();
            database.instantiateEdge(elementType, elementName, source,
                                     userAnswer);
            cout << database.getDatabaseAnswer() << "\n";
        } else if (userAnswer == "delete_element") {
            cout << "Element to delete ?\n";
            userAnswer = getUserAnswer();
            database.deleteElement(userAnswer);
            cout << database.getDatabaseAnswer() << "\n";
        } else if (userAnswer == "attr_add") {
            cout << "Element to modify ?\n";
            string element = getUserAnswer();
            cout << "Type of the new attribute ?\n";
            string attributeType = getUserAnswer();
            cout << "Value of the attribute ?\n";
            userAnswer = getUserAnswer();
            database.attributeAddModify(element,attributeType, userAnswer);
        } else if (userAnswer == "attr_del") {
            cout<<"Element to modify ?\n";
            string element = getUserAnswer();
            cout<<"Attribute to delete ?\n";
            userAnswer = getUserAnswer();
            database.attributeDelete(element, userAnswer);
        } else {
            cout << "Unknown Command !\n";
        }
    } while (userAnswer != "exit");
    cout << "Exiting modelling prompt and going back to "
            "mega modelling shell!\n";
    database.modelExit();
}

std::string Prompt::getUserAnswer() {
    std::string userAnswer;
    std::cout << ">>";
    std::cin >> userAnswer;
    return userAnswer;
}