#include "DatabaseObserver.h"

DatabaseObserver::DatabaseObserver(DatabaseOperationHandler* opHandler) {
    this->opHandler = opHandler;
}

DatabaseObserver::~DatabaseObserver(){
    if(opHandler!= nullptr) {
        delete opHandler;
        opHandler = nullptr;
    }
}

void DatabaseObserver::onOperation(const collab::Operation &op) {
    op.accept(*opHandler);
}