#include <iostream>
#include <string>
using namespace std;

#include "drone.h"

int main() {
  Drone d;
  char c;
  int i;
  bool quit = false;
  while (!quit && cin >> c) {
    switch(c) {
      case 'f': // forward
	      cin >> i;
        d.forward(i);
        break;
      case 'b': // backward
	      cin >> i;
        d.backward(i);
        break;
      case 'l': // turn left
        d.left();
        break;
      case 'r':
        d.right();  // turn right
        break;
      case 'c': // print drone
        cout << d << endl;
        break;
      case 't': // print total distance
        cout << d.getTotalDistance() << endl;
        break;
      case 'm': // print Manhattan distance
        cout << d.getManhattanDistance() << endl;
	      break;
	    case 'q': // quit
        quit = true;
	      break;
    }
  }
}
