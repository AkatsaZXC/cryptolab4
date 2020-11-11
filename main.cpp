#include <iostream>
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
    return defaultGCD;
}
int main() {
    int a, b, x, y;
    int defaultGCD;
    cout << "Please enter first natural number: " << endl;
    cin >> a;
    cout << "Please enter second natural number: " << endl;
    cin >> b;

    cout << "|A| "<<"|B| "<<"|A%B| " << "|A/B| "<< "x " << "y " << endl;

    // Debug
    if(a<b){
        swap(a,b);
    }

    // Main code

    defaultGCD = ExtentedGCD(a,b,x,y);
    cout << "GCD: " << defaultGCD << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}
