#include <iostream>
#include "network.h"
#include "profile.h"

//a default constructor that creates an empty network
Network::Network() {
    numUsers = 0;

    for(int i = 0; i < numUsers; i++) {
        for(int j = 0; i < numUsers; j++) {
            following[i][j] = false;
        }
    }
}


//allows adding new users
bool Network::addUser(std::string usrn, std::string dspn) {
    int count = 0;

    for(int i = 0; i < numUsers; i++) {
        if(usrn == profiles[i].getUsername()) {
            std::cout.setf(std::ios::boolalpha);
            return false;
        }
    }

    for(int i = 0; i < usrn.size(); i++) {
        if (!((usrn[i]>='a'&&usrn[i]<='z') || (usrn[i]>='A'&&usrn[i]<='Z') || (usrn[i]>='0'&&usrn[i]<='9'))) {
            std::cout.setf(std::ios::boolalpha);
            return false;
        }
    }

    if(usrn.size() > 0 && numUsers < 20) {
        profiles[numUsers]=Profile(usrn, dspn);
        numUsers++; 
        std::cout.setf(std::ios::boolalpha);
        return true;
    }
    return false;
}

//return the ID of the user with that username
int Network::findID(std::string usrn) {
    int result = -1;
    
    for(int i = 0; i < numUsers; i++) {
        if(profiles[i].getUsername() == usrn) {
            result = i;
        }
    }
    return result;
}

//if user1 can follow users2, return true
bool Network::follow(std::string usrn1, std::string usrn2) {
    if(findID(usrn1) >= 0 && findID(usrn2) >= 0 && usrn1!=usrn2) {
        following[findID(usrn1)][findID(usrn2)] = true;
        return true;
    }
    return false;
}

// visualize the default network
void Network::printDot() {
    std::cout << "diagraph { \n";

    for(int i = 0; i < numUsers; i++) {
        std::cout << "\t\"@"+profiles[i].getUsername() + "\"\n";
    }  

    for(int i = 0; i < numUsers; i++) {
        for(int j = 0; j < numUsers; j++) {
            if(following[i][j] == true) {
                std::cout << "\t\"@"<<profiles[i].getUsername() << "\" -> ";
                std::cout << " \"@"<<profiles[j].getUsername() << "\"\n";
            }
        }
    }
    std::cout << "\n";
}
