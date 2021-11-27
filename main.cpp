#include <iostream>
#include "profile.h"
#include "network.h"

int main() {

//Task A
    Profile p1("marco", "Marco");    
    std::cout << p1.getUsername() << std::endl; // marco
    std::cout << p1.getFullName() << std::endl; // Marco (@marco)

    p1.setDisplayName("Marco Rossi"); 
    std::cout << p1.getUsername() << std::endl; // marco
    std::cout << p1.getFullName() << std::endl; // Marco Rossi (@marco)
    
    Profile p2("tarma1", "Tarma Roving");    
    std::cout << p2.getUsername() << std::endl; // tarma1
    std::cout << p2.getFullName() << std::endl; // Tarma Roving (@tarma1)

//Task B
    Network nw;
    cout << nw.addUser("mario", "Mario") << endl;     // true (1)
    cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)

    cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
    cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
    cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)

    for(int i = 2; i < 20; i++)
        cout << i << nw.addUser("mario" + to_string(i), 
                    "Mario" + to_string(i)) << endl;   // true (1)

    cout << nw.addUser("yoshi", "Yoshi") << endl;      //false (0)

//Task C
    Network nw1;
    // add three users
    nw1.addUser("mario", "Mario");
    nw1.addUser("luigi", "Luigi");
    nw1.addUser("yoshi", "Yoshi");

    //make them follow each other
    nw1.follow("mario", "luigi");
    nw1.follow("mario", "yoshi");
    nw1.follow("luigi", "mario");
    nw1.follow("luigi", "yoshi");
    nw1.follow("yoshi", "mario");
    nw1.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw2.addUser("wario", "Wario");

    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw2.addUser(usrn, dspn);
        nw2.follow(usrn, "mario");
    }

    // additionally, make @mario2 follow @luigi
    nw2.follow("mario2", "luigi");

    nw1.printDot();
    
    return 0;
}