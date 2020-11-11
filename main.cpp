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
    int defaultGCD = ExtentedGCD(b, a%b,x1,y1);
    x = y1;
    y = x1 - (a / b) * y1;
    cout << a << " " << b << " "<<  a%b <<" "<< a/b <<" "<< x <<" "<< y << endl;
    return defaultGCD;
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
    int randomGCD = GCD(a,b);
    cout << "Sollution for " << a << "x + " << b <<"y = "<< randomGCD << " : " << endl;

    // Debug
    if(a<b){
        swap(a,b);
    }

    // Main code
    randomExtendedGCDVar = ExtentedGCD(a,b,x,y);
    cout << "GCD: " << randomExtendedGCDVar << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "d = " << y%a<< endl; // Compiler bug??

}
