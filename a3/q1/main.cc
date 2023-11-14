#include <iostream>
#include "calc.h"

using namespace std;

int main() {
  Calc calc;
  char ch;
  bool memOp = false;
  bool ac = false;
  while (cin >> ch) {
    switch(ch) {
      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
        // digit typed
        calc.digit(ch - '0');
        break;
      case 'M':
        // start of memory command
        memOp = true;
        break;
      case 'R':
        // memory recall command if follows an 'M'
        if (memOp) {
          calc.memRecall();
          memOp = false;
        }
        break;
      case 'C': 
        // memory clear command if follows a 'C'
        // all clear command if follows an 'A'
        if (memOp) {
          calc.memClear();
          memOp = false;
        }
        else if (ac) {
          calc.allClear();
          ac = false;
        }
        break;
      case '+':
        // memory add command if follows an 'M'
        // plus operator otherwise
        if (memOp) {
          calc.memPlus();
          memOp = false;
        } else {
          calc.op('+');
        }
        break;
      case '-': case '*': case '/':
        // minus, times, division operators
        calc.op(ch);
        break;
      case 'A':
        // start of all clear command
        ac = true; 
        break; 
      case '=':
        // equals operation
        calc.equals();
        cout << calc << endl;
        break;
		  case '.':
        // decimal point not accepted
        cerr << "Decimal numbers not accepted. Program terminated." << endl;
        return 1;
		  default:
        // any other character is invalid input
        cerr << ch << " is not a valid input. Program terminated." << endl;
        return 1;
	 }
  }  
}
