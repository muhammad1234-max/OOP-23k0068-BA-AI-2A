#include <iostream>
using namespace std;

//function to check if a number is prime or not
bool isPrime(int num) {
    int i;
	//validation
	if (num <= 1) {
        return false;
    }
    
    //conditions to check if it is prime number or not
    for ( i = 2/*starting with 2 as 1 is a factor of all the numbers*/; i * i <= num/*condition to check for prime numbers*/; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int number;

    // Get input from the user
    cout << "Enter a number: ";
    cin >> number;

    // Check if the number is prime
    if (isPrime(number)) {
        cout << number << " is a prime number." << endl;
    } else {
        cout << number << " is not a prime number." << endl;
    }

    return 0;
}
