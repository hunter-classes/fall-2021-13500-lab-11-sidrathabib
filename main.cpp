#include <iostream>
#include "particle.h"

int main() {
  // Create a particle object using the constructor
  Particle particle1 (11.0, 12.0,  0.5, -0.4); 
  // Create another particle object, but this time
  // using the default constructor
  Particle particle2; 
  particle1.move(10.0);
  std::cout << particle1.getX() << endl; 
  std::cout << particle1.getY() << endl; 

  std::cout << particle1.x << endl;       // Compile-time ERROR, 
                                     // cannot access
                                     // private variable
  particle1.x += particle1.vx * 5.0; // same ERROR
}