#include <iomanip>

#include "FogNode.h"
#include "functions.h"


Define_Module(FogNode);


void FogNode::initialize()
{

     processing_delay=par("processingDelay").doubleValue();
     queue_size=par("queueSize").intValue();



    scheduleEvent = new cMessage("scheduleEvent");


}

void FogNode::handleMessage(cMessage *msg)
{
    send(msg,"out3");
}
void FogNode::addToQueue(cMessage *msg)
{
    if (waitingMessagePool.size() < queue_size)
      {
        sum_utilize_time+=processing_delay;
          waitingMessagePool.push(msg);
      }
      else if (strcmp(msg->getArrivalGate()->getName(),"in3") == 3)
      {
          cMessage* lastMessage = waitingMessagePool.back();
          waitingMessagePool.pop();
          delete lastMessage;
          waitingMessagePool.push(msg);
      }
      else
      {
          forwardMessage(msg, true);
      }


}


void FogNode::forwardMessage(cMessage *msg, BOOLEAN queue_full){


    if (!queue_full)
    {
        std::string outputGateName = functions.getDestGate(std::string(this->getName()), std::string(msg->getArrivalGate()->getName()), msg);
        outputGateName="out3";
        send(msg, outputGateName.c_str());
        return;
    }

    std::string nextgate = getBestFogGate(msg);
    if (nextgate != "")
    {
        incrementHopCounter(msg);
        send(msg, nextgate.c_str());
    }
}






std::string FogNode::getBestFogGate(cMessage *msg) //Neighbor
 {

     int fog_node_number = std::stoi(std::string(msg->getArrivalModule()->getName()).substr(7));
     std:: string arrivall_gate=msg->getArrivalGate()->getName();
     bubble(("fog" + std::to_string(fog_node_number) + " queue full !!!   hops: " + std::to_string(getHopCounter(msg))).c_str());
     if (getHopCounter(msg) == 0 ){

         return "out4";          //send all full messages to right edge
     }


     switch(fog_node_number)
     {
         case 1:
             return "out4";
         case 5:
                 bubble("Deleting image queues full  !!!");
                    delete msg;
             break;
         default:
             return (arrivall_gate=="in5") ? "out4" : "out5";

     }

     return ""; // Return empty string for undefined behavior.
 }




void FogNode::incrementHopCounter(cMessage* msg) {
     hopCounter[msg]++;
 }
 int FogNode::getHopCounter(cMessage* msg) const {
     auto it = hopCounter.find(msg);
     if (it != hopCounter.end()) {
         return it->second;
     }
     return 0;  // Default hop count is 0 if not found
 }


 FogNode :: ~FogNode(){
     while(!waitingMessagePool.empty()) {
               cMessage* msg = waitingMessagePool.front();
               waitingMessagePool.pop();
               delete msg;
           }

           if (scheduleEvent) {
               cancelAndDelete(scheduleEvent);
               scheduleEvent = nullptr;
           }


 }
 void FogNode::finish() {
     double utlztime=measurments.getServerUtilizationPrecent(sum_utilize_time.dbl(),waitingMessagePool.size(),processing_delay);

     EV << "FogNode ulitization: " << std::fixed << std::setprecision(2) << utlztime << "%\n";
     }



