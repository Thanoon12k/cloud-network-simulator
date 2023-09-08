
package cloudsim;



network net1
{
    @display("bgb=866,571;bgl=2");



    submodules:
         Server: ServerNode {
            @display("p=414,33");
           

}
       
        pc1: HostNode {
            @display("p=33,406");
        }
        pc2: HostNode {
            
            @display("p=111,406");
        }

        pc3: HostNode {
            @display("p=194,406");
        }
        pc4: HostNode {
            @display("p=278,406");
        }
        pc5: HostNode {
            @display("p=357,406");
        }
        pc6: HostNode {
            @display("p=442,406");
        }
        pc7: HostNode {
            @display("p=543,406");
        }
        pc8: HostNode {
            @display("p=642,406");
        }
        pc9: HostNode {
            @display("p=730,406");
        }
        pc10: HostNode {
            @display("p=807,406");
        }
        fogNode1: FogNode {
            @display("p=81,288");
        }
        fogNode2: FogNode {
            @display("p=233,288");
        }
        fogNode3: FogNode {
            @display("p=414,288");
        }
        fogNode4: FogNode {
            @display("p=594,288");
        }
        fogNode5: FogNode {
            @display("p=778,288");
        }
       
    connections:
        fogNode1.in1 <-- hostsFogChannel <-- pc1.out;
        fogNode1.out1 --> hostsFogChannel --> pc1.in;
        fogNode1.in2 <-- hostsFogChannel <-- pc2.out;
        fogNode1.out2 --> hostsFogChannel --> pc2.in;
        fogNode1.in3 <-- fogsServerChannel <-- Server.out1;
        fogNode1.out3 --> fogsServerChannel --> Server.in1;
        fogNode1.in4 <-- fogFogChannel <-- fogNode2.out4;
        fogNode1.out4 --> fogFogChannel --> fogNode2.in4;
        fogNode1.in5 <-- fogFogChannel <-- fogNode1.out5;


        fogNode2.in1 <-- hostsFogChannel <-- pc3.out;
        fogNode2.out1 --> hostsFogChannel --> pc3.in;
        fogNode2.in2 <-- hostsFogChannel <-- pc4.out;
        fogNode2.out2 --> hostsFogChannel --> pc4.in;
        fogNode2.in3 <-- fogsServerChannel <-- Server.out2;
        fogNode2.out3 --> fogsServerChannel --> Server.in2;
        fogNode2.in5 <-- fogFogChannel <-- fogNode3.out4;
        fogNode2.out5 --> fogFogChannel --> fogNode3.in4;

        fogNode3.in1 <-- hostsFogChannel <-- pc5.out;
        fogNode3.out1 --> hostsFogChannel --> pc5.in;
        fogNode3.in2 <-- hostsFogChannel <-- pc6.out;
        fogNode3.out2 --> hostsFogChannel --> pc6.in;
        fogNode3.in3 <-- fogsServerChannel <-- Server.out3;
        fogNode3.out3 --> fogsServerChannel --> Server.in3;
        fogNode3.in5 <-- fogFogChannel <-- fogNode4.out4;
        fogNode3.out5 --> fogFogChannel --> fogNode4.in4;

        fogNode4.in1 <-- hostsFogChannel <-- pc7.out;
        fogNode4.out1 --> hostsFogChannel --> pc7.in;
        fogNode4.in2 <-- hostsFogChannel <-- pc8.out;
        fogNode4.out2 --> hostsFogChannel --> pc8.in;
        fogNode4.in3 <-- fogsServerChannel <-- Server.out4;
        fogNode4.out3 --> fogsServerChannel --> Server.in4;
        fogNode4.in5 <-- fogFogChannel <-- fogNode5.out4;
        fogNode4.out5 --> fogFogChannel --> fogNode5.in4;

        fogNode5.in1 <-- hostsFogChannel <-- pc9.out;
        fogNode5.out1 --> hostsFogChannel --> pc9.in;
        fogNode5.in2 <-- hostsFogChannel <-- pc10.out;
        fogNode5.out2 --> hostsFogChannel --> pc10.in;
        fogNode5.in3 <-- fogsServerChannel <-- Server.out5;
        fogNode5.out3 --> fogsServerChannel --> Server.in5;
        fogNode5.in5 <-- fogFogChannel <-- fogNode5.out5;


}
