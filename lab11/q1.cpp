/*
 * Name: Muhamamd Abbas
 * id:23k-0068
 * purpose: to use polymorphism to create a program that can convert laboratory units
 * */
#include <iostream>

using namespace std;

//base class
class Convert {
protected:
    double val1; //initial value
    double val2; //converted value

public:
    //parameterized constructor with an initializer list
    Convert(double v1 = 0, double v2 = 0) : val1(v1), val2(v2) {}

    //pure virtual function for computing the conversion
    virtual void compute() = 0;

    void display() const {
        cout << "Converted value: " << val2 << endl;
    }
};

//derived class for converting liters to gallons
class L_to_G : public Convert {
public:
    //parameterized constructor with initializer list
    L_to_G(double liters) : Convert(liters) {}

    //implementation 1 of the compute function
    void compute() override {
        val2 = val1 * 0.264172; // 1 liter = 0.264172 gallons
    }
};

//derived class for converting Fahrenheit to Celsius
class F_to_C : public Convert {
public:
    //parameterized constructor with initializer list
    F_to_C(double fahrenheit) : Convert(fahrenheit) {}

    //implementation 2 of the compute function
    void compute() override {
        val2 = (val1 - 32) * 5 / 9; //formula from Fahrenheit to Celsius
    }
};

int main() {
    //dma for the conversion classes
    Convert* convert1 = new L_to_G(4);
    Convert* convert2 = new F_to_C(70);

    convert1->compute();
    convert2->compute();

    cout << "Conversion 1: Liters to Gallons" << endl;
    convert1->display();

    cout << "Conversion 2: Fahrenheit to Celsius" << endl;
    convert2->display();

    //destructor
    delete convert1;
    delete convert2;

    return 0;
}


