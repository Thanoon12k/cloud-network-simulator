
package cloudsim;



network net1
{
    @display("bgb=964.85004,780.85004;bgl=2");



    submodules:
        TaskBroker: Broker {
            @display("p=419.75,250.70001");


        }

        User1: HostNode {
            @display("p=37.95,715.30005");
        }
        User2: HostNode {

            @display("p=116.15,715.30005");
        }

        User3: HostNode {
            @display("p=198.95001,715.30005");
        }
        User4: HostNode {
            @display("p=281.75,715.30005");
        }
        User5: HostNode {
            @display("p=362.25,715.30005");
        }
        User6: HostNode {
            @display("p=447.35,715.30005");
        }
        User7: HostNode {
            @display("p=548.55,715.30005");
        }
        User8: HostNode {
            @display("p=647.45,715.30005");
        }
        User9: HostNode {
            @display("p=734.85004,715.30005");
        }
        User10: HostNode {
            @display("p=811.9,715.30005");
        }
        Router1: FogNode {
            @display("p=86.25,598");
        }
        Router2: FogNode {
            @display("p=238.05,598");
        }
        Router3: FogNode {
            @display("p=419.75,598");
        }
        Router4: FogNode {
            @display("p=599.15,598");
        }
        Router5: FogNode {
            @display("p=783.15,598");
        }

        DataCenter1: ServerNode {
            @display("p=85.100006,71.3");


        }

        DataCenter2: ServerNode {
            @display("p=242.65001,71.3");


        }

        DataCenter3: ServerNode {
            @display("p=418.6,71.3");


        }

        DataCenter4: ServerNode {
            @display("p=583.05005,71.3");


        }

        DataCenter5: ServerNode {
            @display("p=787.75,71.3");


        }

    connections:
        Router1.in1 <-- hostsFogChannel <-- User1.out;
        Router1.out1 --> hostsFogChannel --> User1.in;
        Router1.in2 <-- hostsFogChannel <-- User2.out;
        Router1.out2 --> hostsFogChannel --> User2.in;
        Router1.in3 <-- fogsServerChannel <-- TaskBroker.out1;
        Router1.out3 --> fogsServerChannel --> TaskBroker.in1;
        Router2.in1 <-- hostsFogChannel <-- User3.out;
        Router2.out1 --> hostsFogChannel --> User3.in;
        Router2.in2 <-- hostsFogChannel <-- User4.out;
        Router2.out2 --> hostsFogChannel --> User4.in;
        Router2.in3 <-- fogsServerChannel <-- TaskBroker.out2;
        Router2.out3 --> fogsServerChannel --> TaskBroker.in2;
        Router3.in1 <-- hostsFogChannel <-- User5.out;
        Router3.out1 --> hostsFogChannel --> User5.in;
        Router3.in2 <-- hostsFogChannel <-- User6.out;
        Router3.out2 --> hostsFogChannel --> User6.in;
        Router3.in3 <-- fogsServerChannel <-- TaskBroker.out3;
        Router3.out3 --> fogsServerChannel --> TaskBroker.in3;
        Router4.in1 <-- hostsFogChannel <-- User7.out;
        Router4.out1 --> hostsFogChannel --> User7.in;
        Router4.in2 <-- hostsFogChannel <-- User8.out;
        Router4.out2 --> hostsFogChannel --> User8.in;
        Router4.in3 <-- fogsServerChannel <-- TaskBroker.out4;
        Router4.out3 --> fogsServerChannel --> TaskBroker.in4;
        Router5.in1 <-- hostsFogChannel <-- User9.out;
        Router5.out1 --> hostsFogChannel --> User9.in;
        Router5.in2 <-- hostsFogChannel <-- User10.out;
        Router5.out2 --> hostsFogChannel --> User10.in;
        Router5.in3 <-- fogsServerChannel <-- TaskBroker.out5;
        Router5.out3 --> fogsServerChannel --> TaskBroker.in5;
        TaskBroker.out6 --> fogsServerChannel --> DataCenter1.in1;
        TaskBroker.out7 --> fogsServerChannel --> DataCenter2.in1;
        TaskBroker.out8 --> fogsServerChannel --> DataCenter3.in1;
        TaskBroker.out9 --> fogsServerChannel --> DataCenter4.in1;
        TaskBroker.out10 --> fogsServerChannel --> DataCenter5.in1;



}
