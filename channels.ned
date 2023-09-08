package cloudsim;

channel hostsFogChannel extends ned.DatarateChannel {
    datarate = 1Gbps; // Example datarate, adjust accordingly
    delay = 10ms;     // default delay, you can change it in connections as needed
    
}
channel fogFogChannel extends ned.DatarateChannel {
    datarate = 1Gbps; // Example datarate, adjust accordingly
    delay = 8ms;     // default delay, you can change it in connections as needed
    
}
channel fogsServerChannel extends ned.DatarateChannel {
    datarate = 1Gbps; // Example datarate, adjust accordingly
    delay = 30ms;     // default delay, you can change it in connections as needed
    
}