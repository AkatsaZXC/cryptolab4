#include <iostream>
#include <cmath>
using namespace std;
int ExtentedGCD(int a, int b, int &x, int &y){
    if(b==0){
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int extendedGCDVar = ExtentedGCD(b, a%b,x1,y1);
    x = y1;
    y = x1 - (a / b) * y1;
    cout << a << " " << b << " "<<  a%b <<" "<< a/b <<" "<< x <<" "<< y << endl;
    return extendedGCDVar;
}
int GCD(int a, int b){
    while(a%b != 0){
        int c = a%b;
        a = b;
        b = c;
    }
    return b;
}
int main() {
    int a, b, x, y;
    int randomExtendedGCDVar;
    cout << "Please enter first natural number: " << endl;
    cin >> a;
    cout << "Please enter second natural number: " << endl;
    cin >> b;
    int randomGCDVar = GCD(a,b);
    cout << "Sollution for " << a << "x + " << b <<"y = "<< randomGCDVar << " : " << endl;

    // Debug
    if(a<b){
        swap(a,b);
    }

    // Main code
    randomExtendedGCDVar = ExtentedGCD(a,b,x,y);
    cout << "GCD: " << randomExtendedGCDVar << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    // Because of compiler bug
    if(y < 0){
        cout << "d = " << y << " % " << a << " = " << a + y;
    }else{
        cout << "d = " << y << " % " << a << " = " << y % a;
    }
    // cout << "d = " << y%a<< endl; // Compiler bug??
}
