#include "Prompt.h"

#include <iostream>


// Font: shadow
// See: http://www.patorjk.com/software/taag/#p=display&f=Shadow&t=MVK
#define WELCOME_MENU_TEXT \
"________________________________________________________________________________\n"\
"                                                                                \n"\
"        \\  | \\ \\     /  |  /       ___|   |   |  ____|  |      |             \n"\
"       |\\/ |  \\ \\   /   ' /      \\___ \\   |   |  __|    |      |           \n"\
"       |   |   \\ \\ /    . \\            |  ___ |  |      |      |             \n"\
"      _|  _|    \\_/    _|\\_\\     _____/  _|  _| _____| _____| _____|         \n"\
"                                                                                \n"\
"________________________________________________________________________________\n"


// -----------------------------------------------------------------------------
// Core prompt
// -----------------------------------------------------------------------------

void Prompt::runPrompt() {
    std::cout << WELCOME_MENU_TEXT << std::endl;
    //std::cout << "Modelverse C++ shell" << std::endl;
    menuConnect();
    menuMegaModelingMode();
}

void Prompt::menuConnect() {
    using namespace std; // Yes, I dare using the 'using namespace'! Crazy!

    string ip;
    string port;
    string username;
    string password;

    cout << "Connect to Modelverse (MVK) Database server.\n";
    cout << "IP address: "; cin >> ip;
    cout << "Port: ";       cin >> port;
    cout << "Username: ";   cin >> username;
    cout << "Password: ";   cin >> password;

    cout << "Connecting to Modelverse... " << endl;

    int success = _mvk.connect(ip, std::atoi(port.c_str()), username, password);
    if(success == 0) {
        cout << "Successfully connected\n";
    }
    else {
        cout << "Error. Unable to connect with MVK\n";
    }
}

static void showHelpMegaModeling() {
    using namespace std;
    cout << "MetaModeling commands: \n";
    cout << "    mlist (model_list)\n";
    cout << "    madd (model_add)\n";
    cout << "    mdel (model_delete)\n";
    cout << "    mmod (model_modify)\n";
}

void Prompt::menuMegaModelingMode() {
    using namespace std;
    cout << "Entering MegaModeling mode ('help' for help. 'exit' to leave)";
    cout << endl;

    string choice;
    while(true) {
        cout << ">> ";
        cin >> choice;

        if(choice == "exit" || choice == "quit") {
            break;
        }
        else if(choice == "help") {
            showHelpMegaModeling();
        }
        else if(choice == "mlist") {
            cout << "Location: ";
            cin >> choice;
            _mvk.modelList(choice);
            cout << _mvk.getDatabaseAnswer() << endl;
        }
        else if(choice == "madd") {
            cout << "Model type: ";
            string modelType;
            cin >> modelType;
            cout << "Model name: ";
            cin >> choice;
            _mvk.modelAdd(choice, modelType, "");
            cout << _mvk.getDatabaseAnswer() << endl;
        }
        else if(choice == "mdel") {
            cout << "Model name: ";
            cin >> choice;
            _mvk.modelDelete(choice);
            cout << _mvk.getDatabaseAnswer() << endl;
        }
        else if(choice == "mmod") {
            cout << "Model name: ";
            string workingModel;
            cin >> workingModel;
            cout << "Model Type: ";
            cin >> choice;
            _mvk.modelEnter(workingModel, choice);
            if(_mvk.getDatabaseAnswer() == "\"Model loaded, ready for commands!\"") {
                menuModelingMode();
            }
            else {
                cout << "Error: Unable to load this model" << endl;
            }
        }
        else {
            cout << "Unknown Command" << endl;
        }
    }
}

static void showHelpModeling() {
    using namespace std;
    cout << "Modeling commands: \n";
    cout << "    mlist (model_list)\n";
    cout << "    madd (model_add)\n";
    cout << "    mdel (model_delete)\n";
    cout << "    mmod (model_modify)\n";
}

void Prompt::menuModelingMode() {
    using namespace std;
    cout << "Entering Modeling mode ('help' for help. 'exit' to leave)";
    cout << endl;

    string choice;
    while(true) {
        cout << ">> ";
        cin >> choice;

        if(choice == "exit" || choice == "quit") {
            break;
        }
        else if(choice == "help") {
            showHelpModeling();
        }
        else if(choice == "eltlist") {
            _mvk.elementList();
            cout << _mvk.getDatabaseAnswer() << "\n";
        }
        else if(choice == "eltlistjson") {
            _mvk.elementListJSON();
            cout << _mvk.getDatabaseAnswer() << "\n";
        }
        else if(choice == "eltcrea") {
            cout << "Element Type: ";
            string elementType;
            cin >> elementType;
            cout << "Element name: ";
            cin >> choice;
            _mvk.elementCreate(elementType, choice);
            cout << _mvk.getDatabaseAnswer() << "\n";
        }
        else if(choice == "eltdel") {
            cout << "Element to delete: ";
            cin >> choice;
            _mvk.elementDelete(choice);
            cout << _mvk.getDatabaseAnswer() << "\n";
        }
        else if(choice == "edgecrea") {
            cout << "Element type: ";
            string elementType;
            cin >> elementType;
            cout << "Element name: ";
            string elementName;
            cin >> elementName;
            cout << "Edge source: ";
            string source;
            cin >> source;
            cout << "Edge dest: ";
            cin >> choice;
            _mvk.edgeCreate(elementType, elementName, source, choice);
            cout << _mvk.getDatabaseAnswer() << "\n";
        }
        else if(choice == "attradd") {
            cout << "Element: ";
            string element;
            cin >> element;
            cout << "Attribute name: ";
            string attributeType;
            cin >> attributeType;
            cout << "Attribute value: ";
            cin >> choice;

            _mvk.attributeSet(element, attributeType, choice);
        }
        else if(choice == "attrdel") {
            cout<<"Element: ";
            string element;
            cin >> element;
            cout<<"Attribute: ";
            cin >> choice;

            _mvk.attributeDelete(element, choice);
        }
        else {
            cout << "Unknown command";
        }
    }

    _mvk.modelExit();
}


