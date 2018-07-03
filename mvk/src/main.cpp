#include <iostream>
#include "../include/MVKWrapper.h"
#include "../include/Prompt.h"


void mvkConnect() {
    MVKWrapper connector(LOCALCONNECTIONADRESS, true);
    connector.connect("admin", "admin");
}

void mvkModelList() {
    MVKWrapper connector(LOCALCONNECTIONADRESS, true);
    connector.connect("admin", "admin");
    connector.modelList("models");
}

void mvkModelAddDelete() {
    std::string workingModel = "models/cppTestModel";
    std::string modelType = "formalisms/SimpleClassDiagrams";

    MVKWrapper connector(LOCALCONNECTIONADRESS, true);
    connector.connect("admin", "admin");
    connector.modelAdd(workingModel, modelType, "");
    connector.modelList("models");
    connector.modelDelete(workingModel);
    connector.modelList("models");
}

void mvkModelModify() {
    std::string workingModel = "models/cppTestModel";
    std::string modelType = "formalisms/SimpleClassDiagrams";

    MVKWrapper connector(LOCALCONNECTIONADRESS, true);
    connector.connect("admin", "admin");
    connector.modelAdd(workingModel, modelType, "");
    connector.modelList("models");
    connector.modelModify(workingModel, modelType);
    connector.modelExit();
    connector.modelDelete(workingModel);
    connector.modelList("models");
}

void mvkInstantiateNode() {
    std::string workingModel = "models/cppTestModel";
    std::string modelType = "formalisms/SimpleClassDiagrams";
    std::string elementType = "Class";
    std::string name = "cppTestClassNode";

    MVKWrapper connector(LOCALCONNECTIONADRESS, true);
    connector.connect("admin", "admin");
    connector.modelAdd(workingModel, modelType, "");
    connector.modelList("models");
    connector.modelModify(workingModel, modelType);
    connector.listFull();
    connector.JSON();
    connector.instantiateNode(elementType, name);
    connector.listFull();
    connector.JSON();
    connector.deleteElement(name);
    connector.listFull();
    connector.JSON();
    connector.modelExit();
    connector.modelDelete(workingModel);
    connector.modelList("models");
}

void mvkInstantiateEdge() {
    std::string workingModel = "models/cppTestModel";
    std::string modelType = "formalisms/SimpleClassDiagrams";
    std::string elementType1 = "Class";
    std::string elementType2 = "Association";
    std::string name1 = "cppTestClassNode1";
    std::string name2 = "cppTestClassNode2";
    std::string name3 = "cppTestClassEdge";

    MVKWrapper connector(LOCALCONNECTIONADRESS, true);
    connector.connect("admin", "admin");
    connector.modelAdd(workingModel, modelType, "");
    connector.modelList("models");
    connector.modelModify(workingModel, modelType);
    connector.instantiateNode(elementType1, name1);
    connector.instantiateNode(elementType1, name2);
    connector.instantiateEdge(elementType2, name3, name1, name2);
    connector.listFull();
    connector.deleteElement(name1);
    connector.deleteElement(name2);
    // connector.deleteElement(name3); // non necessaire car automatique
    connector.listFull();
    connector.modelExit();
    connector.modelDelete(workingModel);
    connector.modelList("models");
}

void mvkAttributeAdd() {
    std::string workingModel = "models/cppTestModel";
    std::string modelType = "formalisms/SimpleClassDiagrams";
    std::string elementType = "Class";
    std::string attributeType = "name";
    std::string elementName = "cppTestClassNode";

    MVKWrapper connector(LOCALCONNECTIONADRESS, true);
    connector.connect("admin", "admin");
    connector.modelAdd(workingModel, modelType, "");
    connector.modelList("models");
    connector.modelModify(workingModel, modelType);
    connector.listFull();
    connector.instantiateNode(elementType, elementName);
    connector.attributeAddModify(elementName, attributeType, "Valeur Atribut");
    connector.listFull();
    connector.JSON();
    connector.attributeAddModify(elementName, attributeType, "Nouvelle Valeur");
    connector.listFull();
    connector.JSON();
    connector.attributeDelete(elementName,attributeType);
    connector.listFull();
    connector.JSON();
    connector.deleteElement(elementName);
    connector.listFull();
    connector.modelExit();
    connector.modelDelete(workingModel);
    connector.modelList("models");
}

void allTest() {
    mvkConnect();
    std::cout << "\n";
    mvkModelList();
    std::cout << "\n";
    mvkModelAddDelete();
    std::cout << "\n";
    mvkModelModify();
    std::cout << "\n";
    mvkInstantiateNode();
    std::cout << "\n";
    mvkInstantiateEdge();
    std::cout << "\n";
    mvkAttributeAdd();
    std::cout<<"\n";
}

void launchPrompt() {
    Prompt prompt;
    prompt.runPrompt();
}

int main() {
    std::cout << "Début du Programme !" << std::endl;
    //MVKWrapper connector(LOCALCONNECTIONADRESS,true);

    allTest();
    //launchPrompt();

    std::cout << "Fin du Programme !" << std::endl;
    return 0;
}
