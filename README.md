# DataStructures
# 


# [SimpleSafeArray] Tasks 
# 

- Safe memory management with constructors/destructors
- safe element access with operator[]
- Bound checking
# 

# [ArrayAdvanced] Improving Array Implementation 
# 

- cout << myArray
- Copying Arrays >> Shallow vs deep copy
- Copy-and-swap idiom
- Move semantics
- Generic Array<T> using template

-- Array3.cpp -- 

Give external code access to the internal array elements ,allowing modifications.
What is allowing moification is returning a reference to the original array elements.

if you want Read only access then you have to add "const" :

int& operator[](int index) const{
      return m_ptr[index];
  }

---- Array 4 - Array implementation with bounds checking -- TRY - CATCH exception ----

---- Array 5 - Enable nice idiomatic array printing with operator<< overload ----

---- Array 6 - Show subtle bug involving array copy (due to lack of copy constructor) ----

---- Array 7 - Implement a Safe Custom Copy Constructor , a & b arrays objects have their own memory   block---

---- Array Test - Implementing swap for Array class / 
Swap array objects by swapping their data members - Test the Array<T> class template ----
# 

# [SearchArray]
# 

Show the differences between Linear (complexity O(N)) && Binary Search in an Array : 
Binary Search has a bog advantage on large amount of data. (complexity O(N))

# 
# [Stack]
# 
- Fundamental operations (Push , Pop ,Top)
- stack overflow (exception try/catch)

Array.hpp: A basic Array<T> class template implementation

Stack2.hpp -- Stack class template refined with overflow protection
Variations from Stack1.hpp:
- Added the StackOverflowException class
- Added code in Stack::Push() checking stack overflow conditions

Stack2.cpp

Simulate a Stack Overflow and show how to properly handle it via exceptions
# 

# [Linked Lists]

to be implemented

# 
# [Build && Run] 


If you want to run a specific file (ex.Array2.cpp) then :
Build project : clang++ -std=c++14 -Wall -fsanitize=address -g -fno-optimize-sibling-calls Array2.cpp -v
Run : g++ Array2.cpp -o Array2 or ./a.out or right click to your file that you want to run
Every file is independant with the others and is consisted by each own main()
Paste the output in a file by running: ./a.out >> output.txt


--- if you use Visual Studio Code --- 

Also , you have to be sure that in your "tasks.json" file you can see something like this: 

"args": [ "Array2.cpp"  ] <-- change it 





