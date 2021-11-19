//private variables 
/*
an array of registered user profiles,
an integer numUsers, which stores the number of registered users.
the size of the profiles array is defined as MAX_USERS=20, we cannot sign up more than this number of users.
*/

//public interface 
/*
a default constructor that creates an empty network. For now, setting numUsers = 0 is enough.
addUser(usrn, dspn) is the central function for the class. It allows adding new users. This function receives the username and display name of a new user, the new user can be signed up only if the following conditions are met:
the new username usrn must be a non-empty alphanumeric string,
there is no other users in the network with the same username,
the array profiles is not full.
If the above conditions are met, the new user should be added to the array profiles and the function should return true, otherwise don’t add the user and return false, thus indicating that the operation failed.
*/

class Network {
private:
  static const int MAX_USERS = 20; // max number of user profiles
  int numUsers;                    // number of registered users
  Profile profiles[MAX_USERS];     // user profiles array:
                                   // mapping integer ID -> Profile

  // Returns user ID (index in the 'profiles' array) by their username
  // (or -1 if username is not found)
  int findID (string usrn);
public:
  // Constructor, makes an empty network (numUsers = 0)
  Network();
  // Attempts to sign up a new user with specified username and displayname
  // return true if the operation was successful, otherwise return false
  bool addUser(string usrn, string dspn);
};

//************//

int main() {
  Network nw;
  cout << nw.addUser("mario", "Mario") << endl;     // true (1)
  cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)

  cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
  cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
  cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)

  for(int i = 2; i < 20; i++)
      cout << nw.addUser("mario" + to_string(i), 
                 "Mario" + to_string(i)) << endl;   // true (1)

  cout << nw.addUser("yoshi", "Yoshi") << endl;     // false (0)
}