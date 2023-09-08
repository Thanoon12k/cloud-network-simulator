// GlobalID.h
#ifndef GLOBALID_H_
#define GLOBALID_H_

namespace GlobalID {
    int getNextID();  // Declaration
}

#endif

#include <omnetpp.h>

namespace GlobalID {
    static int counter = 0;  // This will be shared across all nodes

    int getNextID() {
        return counter++;  // Return current ID, then increment
    }
}
