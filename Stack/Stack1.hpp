#ifndef STACK_HPP_INCLUDED
#define STACK_HPP_INCLUDED

#include <ostream>
#include "Array.hpp"

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
    // Push element on top of the stack
    m_top++; //update top index
    m_array[m_top] = element;  
  }

  T Pop() {
    T topElement = m_array[m_top]; //copy element at the top position
    m_top--;
    return topElement;
  }

  const T& Top() const {
    return m_array[m_top];  //return element at the top position
  }

  int Size() const {
    return (m_top + 1); //return # currently stored in the stack
  }

  bool IsEmpty() const {
    return Size() == 0;
  }

  int MaxSize() const {
    return m_array.Size(); //Size of the internal Array
  }

  void Clear() {
    m_top = -1; //reset top Index to -1 (empty stack)
  }


  // Dump stack content to output stream
  friend std::ostream& operator<<(std::ostream& os, const Stack<T>& stack) {
    if (stack.IsEmpty()) {
      os << "  [*** Empty Stack ***]\n\n";
      return os;
    }
    //in case of no empty stack then do the following
    os << "  [Stack]\n";
    // Print stack content from top to bottom and decrease 
    for (int i = stack.m_top; i >= 0; i--) {
      os << "    " << stack.m_array[i] << '\n';
    }
    os << '\n';

    return os;
  }
};

#endif // STACK_HPP_INCLUDED

