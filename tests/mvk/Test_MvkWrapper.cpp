#include "mvk/MvkWrapper.h"

#include <iostream>

#define _TEST_IP "localhost"
#define _TEST_PORT 8001
#define _USER_NAME "admin"
#define _USER_PSWD "admin"

#define _TEST_MODEL "models/TestSimpleGraph"
#define _TEST_MMODEL "formalisms/SimpleClassDiagrams"

#define _TYPE_CLASS "Class"
#define _TYPE_ASSOCIATION "Association"
#define _TYPE_NAME "name"


void MVKWrapper_tests() {
    MvkWrapper mvk(true);

    std::cout << "=== Begining of MVK Tests ===\n\n";

    std::cout << "====== Connection MVK test ======\n";
    mvk.connect(_TEST_IP, _TEST_PORT, _USER_NAME, _USER_PSWD);
    std::cout << "== End of connection test ==\n\n";

    std::cout << "======= Listing Models test =======\n";
    mvk.modelList("models");
    std::cout << "=== End of listing test ===\n\n";


    std::cout << "======= Adding Model test =======\n";
    mvk.modelAdd(_TEST_MODEL, _TEST_MMODEL, "");
    mvk.modelList("models");
    mvk.modelDelete(_TEST_MODEL);
    mvk.modelList("models");
    std::cout << "=== End of adding test ===\n\n";

    std::cout << "====== EnterModel test ======\n";
    mvk.modelAdd(_TEST_MODEL, _TEST_MMODEL, "");
    mvk.modelList("models");
    mvk.modelEnter(_TEST_MODEL, _TEST_MMODEL);
    mvk.modelExit();
    mvk.modelDelete(_TEST_MODEL);
    mvk.modelList("models");
    std::cout << "== End of modifying test ==\n\n";

    std::cout << "======== Element list test ========\n";
    mvk.modelAdd(_TEST_MODEL, _TEST_MMODEL, "");
    mvk.modelList("models");
    mvk.modelEnter(_TEST_MODEL, _TEST_MMODEL);
    mvk.elementList();
    mvk.elementListJSON();
    mvk.elementCreate(_TYPE_CLASS, "e1");
    mvk.elementList();
    mvk.elementListJSON();
    mvk.elementDelete("e1");
    mvk.elementList();
    mvk.elementListJSON();
    mvk.modelExit();
    mvk.modelDelete(_TEST_MODEL);
    mvk.modelList("models");
    std::cout << "==== End of node test ====\n\n";

    std::cout << "======== Edge test ========\n";
    mvk.modelAdd(_TEST_MODEL, _TEST_MMODEL, "");
    mvk.modelList("models");
    mvk.modelEnter(_TEST_MODEL, _TEST_MMODEL);
    mvk.elementCreate(_TYPE_CLASS, "e1");
    mvk.elementCreate(_TYPE_CLASS, "e2");
    mvk.edgeCreate(_TYPE_ASSOCIATION, "edge1", "e1", "e2");
    mvk.elementList();
    mvk.elementDelete("e1");
    mvk.elementDelete("e2");
    // edge automatically deleted
    mvk.elementList();
    mvk.modelExit();
    mvk.modelDelete(_TEST_MODEL);
    mvk.modelList("models");
    std::cout << "==== End of edge test ====\n\n";

    std::cout << "====== Attribute test ======\n";
    mvk.modelAdd(_TEST_MODEL, _TEST_MMODEL, "");
    mvk.modelList("models");
    mvk.modelEnter(_TEST_MODEL, _TEST_MMODEL);
    mvk.elementList();
    mvk.elementCreate(_TYPE_CLASS, "e1");
    mvk.attributeSet("e1", _TYPE_NAME, "AttrValue");
    mvk.elementList();
    mvk.elementListJSON();
    mvk.attributeSet("e1", _TYPE_NAME, "NewAttrValue");
    mvk.elementList();
    mvk.elementListJSON();
    mvk.attributeDelete("e1", _TYPE_NAME);
    mvk.elementList();
    mvk.elementListJSON();
    mvk.elementDelete("e1");
    mvk.elementList();
    mvk.modelExit();
    mvk.modelDelete(_TEST_MODEL);
    mvk.modelList("models");
    std::cout << "== End of attribute test ==\n\n";

    std::cout << "===== End of unit test =====\n";
}

int main(int argc, char** argv) {
    MVKWrapper_tests();
    return 0;
}


