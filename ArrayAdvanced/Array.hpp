// Array.hpp -- A generic array class template
//
//              Implements several features from copy constructor,
//              to copy-and-swap idiom, move constructor,
//              printing via overloaded operator<<, etc.
//

#ifndef ARRAY_HPP_INCLUDED
#define ARRAY_HPP_INCLUDED

#include <cassert>    // For assert
#include <ostream>    // For std::ostream
#include <utility>    // For std::swap


class IndexOutOfBoundsException{};

//-----------------------------------------------------------------------------
// A generic array of T
//-----------------------------------------------------------------------------
template <typename T>
class Array {

  //
  // Implementation Details
  //
 private:
  T*  m_ptr{nullptr};
  int m_size{0};

  bool IsValidIndex(int index) const {
    return (index >= 0) && (index < m_size);
  }
  //
  // Public Interface
  //
 public:

  // Default constructor
  Array() = default;

  // Constructor to create an array with the given size (element count)
  explicit Array(int size) {
    assert(size >= 0);
    if (size != 0) {
      m_ptr = new T[size]{};
      m_size = size;
    }
  }

  // Copy constructor
  Array(const Array& source) {
    if (! source.IsEmpty()) {
      m_size = source.m_size;

      m_ptr = new T[m_size]{};
    
      for (int i = 0; i < m_size; i++) {
        m_ptr[i] = source.m_ptr[i];
      }
    }
  }

  // Move constructor
  Array(Array&& source)
    // "Steal" the data from source 
    : m_ptr {source.m_ptr}
    , m_size{source.m_size} {
    
    // Reset source in a safe state
    source.m_ptr  = nullptr;
    source.m_size = 0;
  }

  // Destructor
  ~Array() {
    delete[] m_ptr;
  }

  // Assignment operator (via copy-and-swap idiom)
  Array& operator=(Array source) {
    swap(*this, source);
    return *this;
  }

  // Swap two array objects (member-wise swap)
  friend void swap(Array& a, Array& b) noexcept {
    using std::swap;
    // we are using friend class here,
    // because we want to access to the private elements of the Array
    // Member-wise swap
    swap(a.m_ptr,  b.m_ptr);
    swap(a.m_size, b.m_size);
  }

  int Size() const {
    return m_size;
  }

  bool IsEmpty() const {
    return (m_size == 0);
  }

  // Safe element access with bounds checking
  T& operator[](int index) {
    if (!IsValidIndex(index)) {
      throw IndexOutOfBoundsException{};
    }

    return m_ptr[index];
  }

  // Safe read-only element access with bounds checking
  T operator[](int index) const {
    if (!IsValidIndex(index)) {
      throw IndexOutOfBoundsException{};
    }

    return m_ptr[index];
  }
};

// Enable idiomatic stream insertion for Array objects
// (e.g. cout << ... << myArray << ...)
template <typename T>
inline std::ostream& operator<<(std::ostream& os, const Array<T>& a) {
  os << "[ ";
  for (int i = 0; i < a.Size(); i++) {
    os << a[i] << ' ';
  }
  os << ']';

  return os;
}

#endif // ARRAY_HPP_INCLUDED


