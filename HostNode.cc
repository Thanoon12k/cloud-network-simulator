#include "HostNode.h"

#include "CustomPackets_m.h"
#include "messages_globalid.h"
#include <iomanip>


Define_Module(HostNode);

void HostNode::initialize()
{   username="";
   
    lowerBound=par("messagesGenerateLowerBound").doubleValue();
    upperBound=par("messagesGenerateUpperBound").doubleValue();
    message_size=par("messageSize").intValue();

   configName = cSimulation::getActiveEnvir()->getConfigEx()->getActiveConfigName();
      messagesdelayVector.setName("Messages Delay");
    msgevent = new cMessage("timer event");
    firstmessage_time=nextRandomDelay();

    if (strcmp(configName, "one-user") == 0) {
         username=  functions.findLastModifiedNpzFile("C:/Users/mohsal/Desktop/app/metalux/fog/python/files");

        if (strcmp(getName(), "pc1")==0)  scheduleAt(simTime()+ firstmessage_time, (msgevent));

    }else
    {
       scheduleAt(simTime()+firstmessage_time, (msgevent));

    }

}

void HostNode::handleMessage(cMessage *msg)
{
    events++;

    if  (strcmp(configName, "one-request") == 0 && events==2)
       endSimulation();

    if(msg->isSelfMessage()){
            GenerateNewMesssage();
            scheduleAt(simTime()+nextRandomDelay(), msgevent);

    }
    else{
        sum_recieved_packets++;
        double  msgdly=measurments.getResponseTime(msg)*1000;//in ms
        messagesdelayVector.recordWithTimestamp(simTime(), msgdly);
        totalMBytesRecived+=message_size;
        EV<<"message ms recorded delay: "+std::to_string(msgdly);

        bubble(("response arrive image id: " + functions.getMessageID(msg) ).c_str());
        delete msg;
    }


    }




void HostNode::GenerateNewMesssage()
{
    int uniqueID = GlobalID::getNextID();
    std::string msgcontent = username+" encrypted image-" + std::to_string(uniqueID) + " from " + std::string(this->getName());
    Image *packet1 = new Image(msgcontent.c_str());
    packet1->setUniqueID(uniqueID);
    packet1->setContent((msgcontent).c_str());
    packet1->setByteLength(4);  // Example packet size 1Byte
    bubble((username+" image id: " + std::to_string(uniqueID)).c_str());

    if (gate("out")->getTransmissionChannel()->isBusy()) {
        delete packet1;
    }
    else{
            send(packet1, "out");
            sum_sent_packets++;
    }
}


double HostNode::nextRandomDelay() {
    double dly=uniform(lowerBound,upperBound);

    return dly;
}

HostNode::~HostNode()
{
    cancelAndDelete(msgevent);
}
void HostNode::finish() {
    double avrg_respnse_time = measurments.getAverageResponseTime();
    double thrput = measurments.getThrouPut_bps(totalMBytesRecived *message_size, firstmessage_time);
    double pkt_lost_prcent = measurments.getPacketsLostsPrecent(sum_sent_packets, sum_recieved_packets);
    double message_rate=measurments.getMessagesRate(sum_sent_packets);
    if (strcmp(getName(), "pc1") == 0 && strcmp(configName, "one-request") != 0) {

        EV << "Average System Response: " << std::fixed << std::setprecision(2) << avrg_respnse_time << " ms\n";
        EV << "SystemThroughput: " << std::fixed << std::setprecision(2) << thrput << " Mbps\n";
        EV << "packet Lost Precentage: " << std::fixed << std::setprecision(2) << pkt_lost_prcent << "%\n";
        EV << "Messages Rate Per second: " << std::fixed << std::setprecision(2) << message_rate << " message per second \n";
                 }
}

