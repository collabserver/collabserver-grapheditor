/**
 * @brief 
 * 
 * @file SimpleGraphOperationObserver.h
 * @author (The Intern)
 * @date 2018-07-10
 */

#ifndef SIMPLEGRAPHOPERATIONOBSERVER_H
#define SIMPLEGRAPHOPERATIONOBSERVER_H

#include "collabdata/custom/SimpleGraph.h"
#include "SimpleGraphOperationHandler.h"

class SimpleGraphOperationObserver : public collab::OperationObserver
{
  private:
    SimpleGraphOperationHandler opHandler;
  public:
    SimpleGraphOperationObserver(SimpleGraphOperationHandler opHandler);
    void onOperation(const collab::Operation &op) override;
};

#endif