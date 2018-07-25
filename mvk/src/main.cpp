#include <iostream>
#include <collabdata/custom/SimpleGraph.h>

#include "../include/MVKWrapper.h"
#include "../include/Prompt.h"
#include "../include/MVKSimpleGraphOperationHandler.h"
#include "../include/DatabaseSimpleGraphOperationHandler.h"
#include "../include/DatabaseObserver.h"

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
    connector.attributeDelete(elementName, attributeType);
    connector.listFull();
    connector.JSON();
    connector.deleteElement(elementName);
    connector.listFull();
    connector.modelExit();
    connector.modelDelete(workingModel);
    connector.modelList("models");
}

void testConstraint() {

    const std::string workingModel = "formalisms/SimpleGraph";
    const std::string metamodel = "formalisms/SimpleClassDiagrams";
    const std::string vertex = "Vertex";
    const std::string edge = "Edge";
    const std::string attribute = "Attribute";
    const std::string string = "String";

    /*
    const std::string constraint = "$ String function constraint(model : Element, name : String):"
            "   if (string_gte(read_attribute(model, name, 'source'), read_attribute(model, name, 'target'))):"
            "       return 'Auto Edge'!"
            "   else:"
            "       return 'Yeah Baby'! $";
    std::cout << constraint << "\n";
     */

    MVKWrapper mvkConnector(LOCALCONNECTIONADRESS, true);
    mvkConnector.connect("admin", "admin");
    mvkConnector.modelAdd(workingModel, metamodel, "");
    if (mvkConnector.getDatabaseAnswer() ==
        "\"Model exists: formalisms/SimpleGraph\"") {
        mvkConnector.modelDelete(workingModel);
        mvkConnector.modelAdd(workingModel, metamodel, "");
    }
    mvkConnector.modelAdd("test", workingModel, "");
    if (mvkConnector.getDatabaseAnswer() ==
        "\"Model exists: test\"") {
        mvkConnector.modelDelete("test");
        mvkConnector.modelAdd("test", workingModel, "");
    }

    mvkConnector.modelModify(workingModel, metamodel);
    // Création des 3 Element du metamodel
    mvkConnector.instantiateNode("String", vertex);
    mvkConnector.instantiateEdge("Association", edge, vertex, vertex);
    mvkConnector.instantiateNode("String", attribute);
    // Création des attributs
    mvkConnector.instantiateNode(string, string);
    mvkConnector.defineAttribute(attribute, vertex, string);
    mvkConnector.defineAttribute(attribute, "Name", string);
    mvkConnector.defineAttribute(attribute, "Value", string);

    /*
    std::cout<<"\nSTRESSS !!!\n";
    mvkConnector.attributeAddModifyCode(edge, "constraint", constraint);
    std::cout << "\nFUCK YEAH !\n\n";
     */

    mvkConnector.modelExit();

    mvkConnector.modelModify("test", workingModel);
    mvkConnector.instantiateNode(vertex, "v1");
    mvkConnector.instantiateNode(vertex, "v2");
    mvkConnector.instantiateEdge(edge, "e1", "v1", "v1");
    mvkConnector.modelExit();
    mvkConnector.modelVerify("test", workingModel);
};

void testSimpleGraphOperation() {
    MVKSimpleGraphOperationHandler opHandler;
    DatabaseObserver *observer = new DatabaseObserver(&opHandler);
    collab::SimpleGraph graph;
    graph.addOperationObserver(*observer);

    graph.addVertex("v1");
    graph.addVertex("v2");
    graph.addEdge("v1", "v2");
    graph.addAttribute("v1", "Ville", "Lyon");
    graph.addAttribute("v1", "Quartier1", "Monplaisir");
    graph.addAttribute("v1", "Quartier2", "GrangeBlanche");
    graph.addAttribute("v2", "Ville", "Paris");
    graph.removeAttribute("v1", "Quartier2");
    graph.setAttribute("v2", "Ville", "Marseille");

    std::cout<<"\nLet's Load !!\n";
    opHandler.loadModel();
};

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
    std::cout << "\n";
}

void launchPrompt() {
    Prompt prompt;
    prompt.runPrompt();
}

int main() {
    std::cout << "Début du Programme !" << std::endl;
    //MVKWrapper connector(LOCALCONNECTIONADRESS,true);

    testSimpleGraphOperation();

    /*MVKSimpleGraphOperationHandler opHandler;
    opHandler.loadModel();*/

    //allTest();
    //launchPrompt();

    std::cout << "Fin du Programme !\n";
    return 0;
}
