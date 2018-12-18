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
   //custom copy constructor
   IntArray(const IntArray& source) {
    //Allocate memory to store array element
    //copy element from source to a new "clone - indipendent" array   
    if (! source.IsEmpty()) {
      m_size = source.m_size;
      //new block of memory for array copy 
      m_ptr = new int[m_size]{};
      //copy from source the elements
      for (int i = 0; i < m_size; i++) {
        m_ptr[i] = source.m_ptr[i];
      }
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
  
    os << "[";
    for(int i=0; i < a.Size(); i++){
        os << a[i]<< ' ';
    }
    os << "]";
    return os;    
}

int main() {
  using std::cout;

  IntArray a{3};
  a[0]=10;
  a[1]=20;
  a[2]=30;

  IntArray b = a ; //copy initialization 
  //this cause a core dump 
  //if you change just and only one of your values 
  //inside of b Array

  cout << " a = " << a << '\n';
  cout << " b = " << b << '\n';

  b[1] = 100; // compiler of c++ causes a core dump here
  //a && b arrays are sharing the same pointer pointer which causes the Error
  cout << "\n b[1] = 100; \n\n";

  cout << " a = " << a << '\n';
  cout << " b = " << b << '\n';
}

