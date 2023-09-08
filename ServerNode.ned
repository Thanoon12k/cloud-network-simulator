

package cloudsim;
simple ServerNode
{
 parameters:
   
   double processingDelay = default(15.0e-3);     // 10 ms delay for process every message
   int queueSize = default(99);     //  queue size
   int wattsConsumePerSecond = default(450);     //  queue number of watts consumed in 1 second
      	
      	
        @display("i=device/server");
        
        gates:
        
        input in1 ;
     
//        output out1;
       
}

