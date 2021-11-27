#include "profile.h"
#include <iostream>

// Profile constructor for a user (initializing 

// private variables username=usrn, displayname=dspn)
Profile::Profile() {
  username = "";
  displayname = "";
}

// Default Profile constructor (username="", displayname="")
Profile::Profile(std::string usrn, std::string dspn) {
  username = usrn;
  displayname = dspn;
}

// Return username
std::string Profile::getUsername() {
  return username;
}

// Return name in the format: "displayname (@username)"
std::string Profile::getFullName() {
  return displayname + " (@" + username+")";
}

// Change display name
void Profile::setDisplayname(std::string dspn) {
  displayname = dspn;
}