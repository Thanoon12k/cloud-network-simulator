

#include "Broker.h"

Define_Module(Broker);

void Broker::initialize()
{
    // TODO - Generated method body
}

#include <string>

void Broker::handleMessage(cMessage *msg)
{
    // Generate a random number between 1 and 10
    int gateNum = intuniform(6, 10);
 std::string gateName = "out" + std::to_string(gateNum);
  send(msg, gateName.c_str());
}
