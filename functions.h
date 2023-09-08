#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <omnetpp.h>
#include <map>
#include <string>

using namespace omnetpp;
class Functions {


public:
        Functions();
        ~Functions();
    void Display(cMessage *msg);
    void Display(std::string displayedText);
    std::map<std::string, std::string> ServerioDic;
    std::map<std::string, std::string> FogioDic;
    std::map<std::string, std::string> HostioDic;
    std::string getDestinationHostGateByMessage(cMessage *msg);

    std::string getFogOut(std::string inputgate, cMessage *msg = nullptr);
    std::string getHostOut(std::string inputgate, cMessage *msg = nullptr);
    std::string getServerOut(std::string inputgate, cMessage *msg = nullptr);
    std::string getDestGate(std::string nodeName, std::string inputgate, cMessage *msg);
    std::string getMessageID(cMessage* msg);
    std::string getPcName(cMessage* msg);
    std::string findLastModifiedNpzFile(const std::string& directoryPath);





};




#endif





