// Array.hpp: A basic Array<T> class template implementation

#ifndef ARRAY_HPP_INCLUDED
#define ARRAY_HPP_INCLUDED

template <typename T>
class Array {
 private:
  T*  m_ptr = nullptr;
  int m_size = 0;

 public:
  Array() = default;

  explicit Array(int size) {
    if (size != 0) {
      m_ptr = new T[size]{};
      m_size = size;
    }
  }

  // Ban copy
  Array(const Array&) = delete;
  Array& operator=(const Array&) = delete;

  ~Array() {
    delete[] m_ptr;
  }

  int Size() const {
    return m_size;
  }

  bool IsEmpty() const {
    return (m_size == 0);
  }

  T& operator[](int index) {
    return m_ptr[index];
  }
  
  const T& operator[](int index) const {
    return m_ptr[index];
  }
};

#endif // ARRAY_HPP_INCLUDED

