
#ifndef __cloudsim_HOSTNODE_H_
#define __cloudsim_HOSTNODE_H_

#include <omnetpp.h>
#include "functions.h"
#include "Measurments.h"

class HostNode : public cSimpleModule
{
  private:
    Functions functions;
    Measurments measurments;
    cOutVector messagesdelayVector;
    cMessage *msgevent;
    int totalMBytesRecived=0;
    double firstmessage_time=0;
    int sum_recieved_packets=0;
    int sum_sent_packets=0;
    int message_size;
    int events=0;
    const char *configName;
    double lowerBound;
    double upperBound;
    std::string username;



  public:
    virtual ~HostNode();

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    void GenerateNewMesssage();
    double nextRandomDelay();
    virtual void finish() override;


};


#endif
