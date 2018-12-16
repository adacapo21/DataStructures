// //Array 4 - array implementation with bounds checking

#include <cassert>
#include <iostream>

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

int main() {
  using std::cout;
  using std::cin;

  try {
    IntArray a{10};
    for (int i = 0; i < a.Size(); i++) {
      a[i] = (i+1)*10;
    }
    
    cout << " Array elements: ";
    for (int i = 0; i < a.Size(); i++) {
      cout << a[i] << ' ';
    }
    cout << '\n';

    cout << " Array size is " << a.Size() << "\n";
    cout << " Please enter an array index: ";
    int index{};
    cin >> index;

    cout << " The element at index " << index << " is " << a[index] << '\n';

  } catch (const IndexOutOfBoundsException& e) {
    cout << "\n *** ERROR: Invalid array index!! \n";
  }
}
