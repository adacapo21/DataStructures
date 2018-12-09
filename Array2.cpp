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
  //return by value 
  int operator[](int index){
      return m_ptr[index];
  }
};


int main(){
    std::ofstream out;
    //create filename.txt and paste tehe result of the above
    out.open( "filename.txt" );
    out<<"\nARRRAYYYYY 3\t\n";
    out << ":D :D :D :D ! \n" ;
    out.close(); //close of filename.txt

IntArray c{3};
    std::cout<<"\nARRRAYYYYY 3\t\n";
    std::cout << "\n:D :D :D :D ! \n" ; 
    std::cout<< "Create array \n";
    IntArray a{};
    std::cout<< "a.size() is " << a.Size() << '\n';
    assert(a.IsEmpty());
    std::cout<< "---------------\n";
    IntArray b{10};
    std::cout<< "b.Size() is " << b.Size() << '\n';
    assert(!b.IsEmpty());
    std::cout<< "----------------\n";

    return 0;
}

