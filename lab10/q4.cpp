/*
Name: Muhammad Abbas
id: 23k-0068
purpose: Using friend functions to access private members and calculate perimeter of a shape
*/
#include <iostream>

using namespace std;

// Forward declaration of Perimeter class
class Perimeter {
private:
    double length;
    double breadth;

public:
    // Constructor to initialize length and breadth
    Perimeter(double l, double b) : length(l), breadth(b) {}

    // Friend function declaration
    friend class PrintClass;

    // Function to calculate perimeter
    double calculatePerimeter() const {
        return 2 * (length + breadth);
    }
};
// PrintClass class
class PrintClass {
public:
    // Function to display perimeter (friend function of Perimeter class)
    void displayPerimeter(const Perimeter& obj) {
        cout << "Perimeter: " << obj.calculatePerimeter() << endl;
    }
};

// Perimeter class


int main() {
    // Create an object of Perimeter class
    Perimeter perimeterObj(5, 3);

    // Create an object of PrintClass to display perimeter
    PrintClass printObj;

    // Display perimeter using PrintClass object
    printObj.displayPerimeter(perimeterObj);

    return 0;
}
