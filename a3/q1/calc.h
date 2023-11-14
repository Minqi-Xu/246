#ifndef CALC_H
#define CALC_H
#include <iostream>

struct Calc {
  bool error = false; // whether or not the most recent operation produced an error
  int display = 0; // the current contents of the display
  char oper = 0; // the most recently pressed operator key (a character: +, -, *, or /)
  int result = 0; // the current computed result
  int memory = 0; // the contents of memory

  // Adds digit (which must be between 0 and 9, inclusive) to the end of the display value
  void digit(int digit);

  // Sets the oper field. If the oper field previously contained an operator, it combines display 
  // and result with that operator, and stores the result. If not, display is copied to result. 
  // In either case, display is cleared (reset to 0).
  void op(char oper);

  // Combines result and display using operator, and stores the result in result and display.
  // Clears the oper field.
  void equals();

  // Adds the displayed value to the contents of memory and stores the result in memory.
  void memPlus();

  // Clears the contents of the memory (sets it to 0).
  void memClear();

  // Copies the contents of memory to the display.
  void memRecall();

  // Returns true if the error flag is set (because of division by 0).
  bool isError() const;

  // Resets all memory to 0, clears the operator, and resets the error flag.
  void allClear();
};

// Prints the current state of the Calc object to out.
// Please refer to the assignment specification for the format.
std::ostream &operator<<(std::ostream &out, const Calc &c);

#endif
