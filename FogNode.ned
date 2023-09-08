
package cloudsim;


simple FogNode
{
    parameters:
        
        double processingDelay = default(15.0e-3);     // 15 ms delay for process every message
      	int queueSize = default(2);     //  queue size 
      	  
      
    
        @display("i=device/accesspoint");
    gates:
        input in1;
        input in2;
        input in3;
      
        output out1;
        output out2;
        output out3;
       

}