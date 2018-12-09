#include <iostream>
#include <cassert>

class IntArray {
  
 private:
  int* m_ptr{nullptr};
  int  m_size{0};
//
//enum logDEBUG;
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
};


int main(){
    
    std::cout<<"AAAAAAAAAAAAAAA\t";
    std::cout << "Hello World :D :D :D :D ! \n" ; 

    std::cout<< "create empty array \n";
    IntArray a{};
    std::cout<< "a.size() is " << a.Size() << '\n';
    assert(a.IsEmpty());
    std::cout<< "----------\n";
    IntArray b{10};
    std::cout<< "b.Size() is " << b.Size() << '\n';
    assert(!b.IsEmpty());
    return 0;
}

