/*
name:Muhammad Abbas
id:23K-0068
purpose: program to calculate the GCD and LCM of 2 numbers using recursion
*/
#include <iostream>

using namespace std;

//Euclidean algorithm used to find GCD or HCF
int calculateGCD(int a, int b) {
    if (b == 0) {
        return a;//basecase
    } else {
    	//according to the algorithm each consecutive calls will see the value of a being replaced by b and b getting the remainder of a/b
        return calculateGCD(b, a % b);//recursive case
    }
}

// LCM calculation using a simple formula which includes the gcd euclidean algorthm as well. so basecase of the above function will be the basecase of this function as well
int calculateLCM(int a, int b) {
    return (a * b) / calculateGCD(a, b);
}

int main() {
    int num1, num2;

    cout<<"Enter the first number: ";
    cin>>num1;
    cout<<"Enter the second number: ";
    cin>>num2;

    cout<<"GCD of "<<num1<<" and "<<num2<<" is: "<<calculateGCD(num1, num2)<<endl;

    cout<<"LCM of "<<num1<<" and "<<num2<<" is: "<<calculateLCM(num1, num2)<<endl;

    return 0;
}
