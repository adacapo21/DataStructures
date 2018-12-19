// Stack2.hpp -- Stack class template refined with overflow protection
//
// Variations from Stack1.hpp:
// - Added the StackOverflowException class
// - Added code in Stack::Push() checking stack overflow conditions
//

#ifndef STACK_HPP_INCLUDED
#define STACK_HPP_INCLUDED

#include <ostream>
#include "Array.hpp"

// This represents a stack overflow error.
// In production code exception classes can be derived from std::runtime_error
class StackOverflowException {};

template <typename T>
class Stack {

 private:
  Array<T> m_array; // Stack elements are stored in this array
  int      m_top;   // Index of the top element (-1 for empty stack)


 public:

  explicit Stack(int maxStackSize)
    : m_array{maxStackSize}
    , m_top{-1}             // Empty stack
  {}

  void Push(const T& element) {
    // Before pushing on top of the stack, check that there's enough room
    if (Size() >= MaxSize()) {
      // There's not enough room in this stack for pushing a new element
      throw StackOverflowException{};
    }

    // Push element on top of the stack
    m_top++;
    m_array[m_top] = element;
  }

  T Pop() {
    // NOTE: We should add a similar check preventing underflow,
    // i.e. popping from an empty stack...

    T topElement = m_array[m_top];
    m_top--;
    return topElement;
  }

  const T& Top() const {
    return m_array[m_top];  
  }

  int Size() const {
    return (m_top + 1);
  }

  bool IsEmpty() const {
    return Size() == 0;
  }

  int MaxSize() const {
    return m_array.Size();
  }

  void Clear() {
    m_top = -1;
  }


  // Dump stack content to output stream
  friend std::ostream& operator<<(std::ostream& os, const Stack<T>& stack) {
    if (stack.IsEmpty()) {
      os << "  [*** Empty Stack ***]\n\n";
      return os;
    }

    os << "  [Stack]\n";
    // Print stack content from top to bottom
    for (int i = stack.m_top; i >= 0; i--) {
      os << "    " << stack.m_array[i] << '\n';
    }
    os << '\n';

    return os;
  }
};

#endif // STACK_HPP_INCLUDED

