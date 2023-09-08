
package cloudsim;
simple HostNode
{
    
    parameters:
        int messageSize = default(4);   //in MB default message(packets) size
        double messagesGenerateLowerBound = default(5.0e-3);  // 5ms lower bound random delay for generate message
        double messagesGenerateUpperBound = default(500.0e-3); // 500ms upper bound random delay for generate message
      	  
        @display("i=device/pc");

        gates:
        input in ;
        output out;
         
       
}
