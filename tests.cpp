#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define CHECK DOCTEST_CHECK
#include "doctest.h"
#include "profile.h"
#include "network.h"
using namespace std;

TEST_CASE("Taks A") {
    Profile p1("marco", "Marco");
    CHECK(p1.getUsername() == "marco");
    CHECK(p1.getFullName() == "Marco (@marco)");

    p1.setDisplayName("Marco Rossi");
    CHECK(p1.getUsername() == "marco");
    CHECK(p1.getFullName() == "Marco Rossi (@marco)");

    Profile p2("tarma1", "Tarma Roving"); 
    CHECK(p2.getUsername() == "tarma1");
    CHECK(p2.getFullName() == "Tarma Roving (@tarma1)");
}

TEST_CASE("Task B") {
    Network nw;

    CHECK(nw.addUser("mario", "Mario") == true);
    CHECK(nw.addUser("luigi", "Luigi") == true);
    CHECK(nw.addUser("mario", "Mario2") == false);
    CHECK(nw.addUser("mario 2", "Mario2") == false);
    CHECK(nw.addUser("mario-2", "Mario2") == false);

    for(int i = 2; i < 20; i++) {
        CHECK(nw.addUser("mario" + to_string(i), "Mario" + to_string(i)) == true);
    }

    CHECK(nw.addUser("yoshi", "Yoshi") == false);
}

TEST_CASE("Task C") {
    Network nw1 = Network();

    nw1.addUser("mario", "Mario");
    nw1.addUser("luigi", "Luigi");
    nw1.addUser("yoshi", "Yoshi");
    nw1.addUser("wario", "Wario");

    CHECK(nw1.follow("mario", "luigi") == true);
    CHECK(nw1.follow("mario", "wario") == true);
    CHECK(nw1.follow("mario", "mario") == false);
}