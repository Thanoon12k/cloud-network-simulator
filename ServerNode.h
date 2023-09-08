

#ifndef __cloudsim_SERVERNODE_H_
#define __cloudsim_SERVERNODE_H_

#include <omnetpp.h>
#include <queue>
#include "functions.h"
#include  "Measurments.h"
using namespace omnetpp;


class ServerNode : public cSimpleModule
{
    private:
    Functions functions;
    Measurments measurments;

       cMessage *scheduleEvent ;
       std::string status="idle"; ///ether idle or now_processing
       double processing_delay;
       int watts_per_second;;    ///server consume 400j  those equal 400watt per one running second
       int queue_size;
       simtime_t sum_utilize_time=0.0;
       simtime_t start_utlize_time=0.0;
       std::queue<cMessage *> waitingMessagePool;


  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    void addToQueue(cMessage *message);
    void forwardMessage(cMessage *msg);
    virtual void finish() override;


        virtual ~ServerNode();
};



#endif
