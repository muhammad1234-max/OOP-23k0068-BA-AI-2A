/*
Name: Muhammad Abbas
id: 23k-0068
purpose: using operator overloading to add area of 2 shapes
*/
#include <iostream>

using namespace std;

class Shape {
private:
    double length;
    double width;
    double area; 

public:
    //parametrized constructor
    Shape(double l, double w) : length(l), width(w) {
        area = length * width;
    }

    //overloading the operator to add the areas of two shape objects
    Shape operator+(const Shape& other) const {
        // Create a new shape object with combined dimensions
        Shape combined(length + other.length, width + other.width);
        // Set the area of the combined shape by adding areas of both objects
        combined.area = area + other.area;
        return combined;
    }

    void Display() const {
        cout << "Length: " << length << ", Width: " << width << endl;
    }

    // Function to display the area of the shape
    void DisplayArea() const {
        cout << "Area: " << area << endl;
    }
};

int main() {
    // Creating two shape objects
    Shape shape1(5, 3);
    Shape shape2(4, 2);

    // Displaying the dimensions of shape1 and shape2
    cout << "Shape 1:" << endl;
    shape1.Display();
    cout << "Shape 2:" << endl;
    shape2.Display();

    // Displaying the area of shape1 and shape2
    cout << "Area of Shape 1:" << endl;
    shape1.DisplayArea();
    cout << "Area of Shape 2:" << endl;
    shape2.DisplayArea();

    //Adding the areas of shape1 and shape2 
    Shape totalShape = shape1 + shape2;

    //Displaying the area of the resulting shape
    cout << "Total Area:" << endl;
    totalShape.DisplayArea();

    return 0;
}
