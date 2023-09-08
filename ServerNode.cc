#include "ServerNode.h"
#include <cmath>
#include <iomanip>


Define_Module(ServerNode);

void ServerNode::initialize()
{
    processing_delay=par("processingDelay").doubleValue();
    queue_size=par("queueSize").intValue();
    watts_per_second=par("wattsConsumePerSecond").intValue();



    scheduleEvent = new cMessage("scheduleEvent");
}

void ServerNode::handleMessage(cMessage *msg)
{


    if (! msg->isSelfMessage() ){
        addToQueue(msg);

        if (!scheduleEvent->isScheduled())
                    scheduleAt(simTime()+processing_delay, scheduleEvent); //wait until get last message in queue

    }
    else if (msg == scheduleEvent && !waitingMessagePool.empty()){


            msg = waitingMessagePool.front();
            waitingMessagePool.pop(); //take the message
            forwardMessage(msg);
            scheduleAt(simTime()+processing_delay, scheduleEvent);
    }
        else{


        }


}

void ServerNode::addToQueue(cMessage *msg){
    if (waitingMessagePool.size() < queue_size)
    {
        sum_utilize_time+=processing_delay;
        EV<<"sum processing time: "+sum_utilize_time.str()<<endl;
        waitingMessagePool.push(msg);
    }
    else
    {
        bubble(("Queue full, deleted image -" + functions.getMessageID(msg)).c_str());
        delete msg;
    }
}

void ServerNode::forwardMessage(cMessage *msg)
{
    EV << "msg sent at " << getName() << " - " << (simTime().dbl() )  << endl;

    std::string outputGateName = functions.getDestGate(std::string(this->getName()), std::string(msg->getArrivalGate()->getName()), msg);
    msg->setName(("image-" + functions.getMessageID(msg) + " processed " + functions.getPcName(msg)).c_str());
    bubble(("Image served with id: " + functions.getMessageID(msg)).c_str());
    send(msg, outputGateName.c_str());
}

ServerNode::~ServerNode()
{
    while (!waitingMessagePool.empty()) {
        cMessage* msg = waitingMessagePool.front();
        waitingMessagePool.pop();
        delete msg;
    }

    if (scheduleEvent) {
        cancelAndDelete(scheduleEvent);
        scheduleEvent = nullptr;
    }
}


void ServerNode::finish() {

     double utlztime=measurments.getServerUtilizationPrecent(sum_utilize_time.dbl(),waitingMessagePool.size(),processing_delay);
     double powr_cunsume=measurments.getPowerConsume(sum_utilize_time, watts_per_second);

     EV << "server power consume: " << std::fixed << std::setprecision(1) << powr_cunsume << " Joule" << endl;
     EV << "server ulitization: " << std::fixed << std::setprecision(2) << utlztime << "%\n";
          }


