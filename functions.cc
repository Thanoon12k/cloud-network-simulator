
#include "functions.h"
#include <omnetpp.h>
#include "dirent.h"
#include "sys/stat.h"
#include <string>



Functions::Functions() {
    ServerioDic = { {"in1", "out1"}, {"in2", "out2"}, {"in3", "out3"}, {"in4", "out4"}, {"in5", "out5"} };
    FogioDic = { {"in1", "out3"}, {"in2", "out3"} };
    HostioDic = { {"in", "out"} };
}

Functions::~Functions() {
    // Cleanup if necessary
}



void Functions::Display(cMessage *msg)
{
         EV  << " Message: " << msg->getName()
           << " Sender: " << msg->getSenderModule()->getFullName()
           << " Receiver: " << msg->getArrivalModule()->getFullName()
           << " Arrival Gate: " << msg->getArrivalGate()->getName() << "\n";
}

void Functions::Display( std::string displayedText)
{
        EV << displayedText << "\n";

}

std::string Functions::getDestinationHostGateByMessage(cMessage *msg)
{
    std::string desgate="out1";
    std::string messagename = msg->getName();
    char lastChar = messagename.back();
        if (lastChar == '2' || lastChar == '4' || lastChar == '6' || lastChar == '8' || lastChar == '0') {
               desgate="out2";
          }
   return desgate ;
}


 std::string Functions::getFogOut(std::string inputgate,cMessage *msg)
{

    if (FogioDic.count(inputgate)) {

              return FogioDic[inputgate];
          } else {

            return  getDestinationHostGateByMessage(msg);
          }

}

 std::string Functions::getHostOut(std::string inputgate,cMessage *msg)
{
    return HostioDic[inputgate];
}
 std::string Functions::getServerOut(std::string inputgate,cMessage *msg)
{          return ServerioDic[inputgate];

}

 std::string Functions::getDestGate(std::string nodeName,std::string inputgate, cMessage *msg)
{

    if (nodeName.find("fog") != std::string::npos) {


        return getFogOut(inputgate, msg);
    }
    else if (nodeName.find("host") != std::string::npos) {
        return getHostOut(inputgate, msg);
    }
    else if (nodeName.find("Server") != std::string::npos) {
        return getServerOut(inputgate, msg);
    }
    else {
        return "out3";
    }

}
 std::string Functions::getMessageID(cMessage* msg) {
    const char* message = msg->getName();
    int id = -1;
    const char* patternStart = strstr(message, "image-");

    if (patternStart) { // If found, attempt to extract the number immediately after it

        sscanf(patternStart, "image-%d", &id);

        return std::to_string(id);;
    }
    return "??";
 }

 std::string Functions::getPcName(cMessage* msg){
     const char* message = msg->getName();
      int pcNumber = -1; // Initialize to an invalid number
      const char* patternStart = strstr(message, "pc");

      if (patternStart) {
          sscanf(patternStart, "pc%d", &pcNumber);
              return "pc" + std::to_string(pcNumber);
      }
      return "??";



 }
 std::string Functions::findLastModifiedNpzFile(const std::string& directoryPath) {
     DIR* dir = opendir(directoryPath.c_str());
     if (dir == nullptr) {
         return "";
     }

     struct dirent* entry;
     time_t latestTime = 0;  // Start with the oldest possible timestamp
     std::string latestFile = "";

     while ((entry = readdir(dir)) != nullptr) {
         std::string filename = entry->d_name;

         // Check if the filename has the ".npz" extension
         if (filename.length() >= 4 && filename.substr(filename.length() - 4) == ".npz") {
             struct stat fileStat;
             std::string fullPath = directoryPath + "/" + filename;

             // Use stat to get file attributes
             if (stat(fullPath.c_str(), &fileStat) != -1) {
                 if (fileStat.st_mtime > latestTime) {  // Compare modification times
                     latestTime = fileStat.st_mtime;
                     latestFile = filename.substr(0, filename.length() - 4);  // Store only the filename without the ".npz" extension
                 }
             } else {
                 // You can handle the error from stat here, if necessary
             }
         }
     }
     closedir(dir);

     return "( "+latestFile +" )";  // Return the latest modified file or empty string if not found
 }

