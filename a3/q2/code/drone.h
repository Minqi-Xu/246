#ifndef __DRONE_H__
#define __DRONE_H__
#include <iostream>
#include "position.h"

class Drone {
  Position cur; // current position
  int dir;  // 0 = N, 1 = E, 2 = S, 3 = W
  int numSteps; // total number of steps walked by the drone
 public:
  // Initializes a drone in the position (0,0)
  Drone();
  // Destructor
  ~Drone();
  
  // Moves the drone forward by the number of steps in the current direction
  // steps must be a positive number
  void forward(int steps = 1);

  // Moves the drone backward by the number of steps in the current direction
  // steps must be a positive number
  void backward(int steps = 1);

  // Turns the drone 90 degrees left
  void left();

  // Turns the drone 90 degrees right
  void right();

  // Returns the current position  
  Position getPosition() const;
  
  // Returns the current direction
  int getDirection() const;
  
  // Returns the total number of steps walked by the drone
  int getTotalDistance() const;
  
  // Returns the Manhattan distance of the current position to the origin
  int getManhattanDistance() const;
};

// Prints the current status of the drone to out in the format:
// Current position: (ew,ns), Facing <direction>
// where <direction> is North, East, South, or West
std::ostream &operator<<(std::ostream &out, const Drone &drone);

#endif
