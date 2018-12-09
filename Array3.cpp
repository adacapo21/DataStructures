#include <iostream>
#include <cassert>
#include <fstream>
#include <string>
class IntArray {
  
 private:
  int* m_ptr{nullptr};
  int  m_size{0};

 public:
  IntArray() = default;

  explicit IntArray(int size) {
    if (size != 0) {
      m_ptr = new int[size]{};
      m_size = size;
    }
  }
 
  int Size() const {
    return m_size;
  }
  //Destructor to avoid coredump
  ~IntArray() {
    delete[] m_ptr;
  }

  bool IsEmpty() const {
    return (m_size == 0);
  }
  //return by value without &
  int& operator[](int index){
      return m_ptr[index];
  }

};
int main(){
    using std::cout;
    IntArray c{3};
    cout <<"\nARRRAYYYYY 3\t\n";
    c[0]= 10; //asignment here requires reference so solution : int& operator
    return 0;
}