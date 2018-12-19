//=============================================================================
// Simulate a Stack Overflow and show how to properly handle it via exceptions
//=============================================================================

#include "Stack2.hpp" // Stack implementation safely guarded against overflow
#include <iostream>
#include <cassert>
using std::cout;

int main() {

  // Guard stack push against overflow
  try {
    Stack<int> stack{4};
    cout << " Created stack of max size: " << stack.MaxSize() << '\n';

    // Keep pushing until the stack overflows...
    while (true) {
      cout << " Trying: stack.Push(64); ...";
      // correctly tested the POP function with the exception with the below commands
      // stack.Pop();
      // assert(stack.Size() == 0);
      stack.Push(64);
      cout << "OK.\n";
    }
  } catch (const StackOverflowException& e) {
    cout << "\n *** Stack Overflow detected ***\n\n";    
  }
}

