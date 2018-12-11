#include <iostream>
using std::cout;

// since Swap needs to *modify* its parameteres
// pass the by *reference (&)
void Swap(int& a,int& b){
    int temp{a};  // temp <== a
    a=b;          // a <== b
    b=temp;       // b <== temp
}

int main(){
    int x{2};
    int y{10};

    cout << "Before swap x = " << x << " & y = " << y << '\n' ;
    Swap(x,y);
    cout << "After swap x = " << x << " & y = " << y << '\n' ;

}