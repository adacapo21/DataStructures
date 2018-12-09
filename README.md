# DataStructures
If you want to run a specific file (ex.Array2.cpp) then you have to do this:

Build project : clang++ -std=c++14 -Wall -fsanitize=address -g -fno-optimize-sibling-calls Array2.cpp -v

Run : g++ Array2.cpp -o Array2 or ./a.out

See the output in a file by running: ./a.out >> output.txt

--- if you use Visual Studio Code --- 
Also , you have to be sure that in your "tasks.json" file you can see something like this:

"args": [
            "-std=c++14",
            "-Wall",
            "-fsanitize=address", // ANas : Address Sanitizer
            "-g", 
            //"-fno-omit-frame-pointer", // ASan :nice stack traces
            "-fno-optimize-sibling-calls", //ASan :perfect stack traces , use it with "-01"
            "Array2.cpp", <-- change it
            "-v"
        ],

-- Array3.cpp -- 
Give external code access to the internal array elements ,allowing modifications.
What is allowing moification is returning a reference to the original array elements.

if you want Read only access then you have to add "const" :
int& operator[](int index) const{
      return m_ptr[index];
  }
