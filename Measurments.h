

#ifndef SCR_MEASURMENTS_H_
#define SCR_MEASURMENTS_H_


#include "CustomPackets_m.h"
#include <omnetpp.h>
using namespace omnetpp;

class Measurments {
private:
  std::vector<double> responses_time_vector;

public:
    Measurments();
    virtual ~Measurments();
    double getResponseTime(cMessage *msg);
    double getAverageResponseTime();
    double getServerUtilizationPrecent(double run_time,int poolSize,double process_delay);
    double getThrouPut_bps(int total_bytes,double frist_msg_time);
    double getPowerConsume(simtime_t runtime,int wps);
    double getPacketsLostsPrecent(double sent_pkts,double recieve_pkts);
    double getMessagesRate(double sent_pkts);


};

#endif /* SCR_MEASURMENTS_H_ */
