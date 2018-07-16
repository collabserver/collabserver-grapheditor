#include "SimpleGraphOperationObserver.h"
#include <iostream>

SimpleGraphOperationObserver::SimpleGraphOperationObserver(SimpleGraphOperationHandler opHandler)
{
    this->opHandler = opHandler;
}

void SimpleGraphOperationObserver::onOperation(const collab::Operation &op)
{
   op.accept(this->opHandler);
}