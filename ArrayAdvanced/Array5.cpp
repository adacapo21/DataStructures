// //Array 5 - Enable nice idiomatic array printing with operator

#include <cassert>
#include <iostream>
#include <ostream>

 //represent the exception thrown 
class IndexOutOfBoundsException{};

class IntArray {
 private:
  int* m_ptr{nullptr};
  int  m_size{0};

  // Helper Method of the array class - Safe array element axxess
  // checks the boundaries of an Array from 0 to N-1
  bool IsValidIndex(int index) const {
    return (index >= 0) && (index < m_size);
  }

 public:
  IntArray() = default;

  explicit IntArray(int size) {
    if (size != 0) {
      m_ptr = new int[size]{};
      m_size = size;
    }
  }
  //Destructor to avoid coredump
  ~IntArray() {
    delete[] m_ptr;
  }

  int Size() const {
    return m_size;
  }

  bool IsEmpty() const {
    return (m_size == 0);
  }

  int& operator[](int index) {
    if (!IsValidIndex(index)) {
      //Index Out of Range
      //Do Something to prevent buffer overflow
      throw IndexOutOfBoundsException{};
    }
    return m_ptr[index];
  }

  int operator[](int index)  const{
    if (!IsValidIndex(index)) {
      throw IndexOutOfBoundsException{};
    }

    return m_ptr[index];
  }
};

std::ostream& operator<<(std::ostream& os , const IntArray& a){
    //Print array elements without using cout
    //like this [10 20 30]
 
    os << "[";
    for(int i=0; i < a.Size(); i++){
        os << a[i]<< ' ';
    }
    os << "]";
    return os;    
}

int main() {
  using std::cout;

  IntArray a{15};
  for (int i = 0; i < a.Size(); i++) {
    a[i] = (i+1)*10;
  }
    
  cout << " Array elements : " << a << '\n';
}
