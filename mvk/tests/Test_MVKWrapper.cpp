#include "MVKWrapper.h"


#define LOCALCONNECTIONADRESS "http://127.0.0.1:8001"


void MVKWrapper_tests() {
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

int main(int argc, char** argv) {
    MVKWrapper_tests();
    return 0;
}


