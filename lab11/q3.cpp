/*
 * Name: Muhammad Abbas
 * id:23k-0068
 * purpose: setting up a vehicle inheritance hierarchy based in abstract classes and virtual pure functions
 * */

#include <iostream>
#include <string>

using namespace std;

//abstract base class
class Vehicle {
protected:
    string make;
    string model;
    int speed;

public:
    Vehicle(const std::string& mk, const std::string& mdl, int spd)
            : make(mk), model(mdl), speed(spd) {}

    //pure virtual functions
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void calculateFuelEfficiency() const = 0;

    //concrete member functions
    string getMake() const {
        return make;
    }

    string getModel() const {
        return model;
    }

    int getSpeed() const {
        return speed;
    }
};

//concrete subclass 1
class Car : public Vehicle {
private:
    double fuelCapacity;

public:
    Car(const string& mk, const string& mdl, int spd, double fuelCap)
            : Vehicle(mk, mdl, spd), fuelCapacity(fuelCap) {}

    //overridden member functions
    void accelerate() override {
        speed += 10;
    }

    void brake() override {
        speed -= 10;
        if (speed < 0) speed = 0;
    }

    void calculateFuelEfficiency() const override {
        cout << "Fuel efficiency of the car is calculated based on its fuel capacity." <<endl;
    }
};

//concrete subclass 2
class Truck : public Vehicle {
private:
    int cargoCapacity;

public:
    Truck(const std::string& mk, const std::string& mdl, int spd, int cargoCap)
            : Vehicle(mk, mdl, spd), cargoCapacity(cargoCap) {}

    //overridden member functions
    void accelerate() override {
        speed += 5;
    }

    void brake() override {
        speed -= 5;
        if (speed < 0) speed = 0;
    }

    void calculateFuelEfficiency() const override {
        cout << "Fuel efficiency of the truck is calculated based on its cargo capacity." << endl;
    }
};


int main() {
    Car car("Toyota", "Camry", 60, 50.5); // Make, model, speed, fuel capacity
    cout << "Car Details:" << endl;
    cout << "Make: " << car.getMake() << endl;
    cout << "Model: " << car.getModel() << endl;
    cout << "Speed: " << car.getSpeed() << " km/h" << endl;
    car.accelerate();
    cout << "Speed after acceleration: " << car.getSpeed() << " km/h" << endl;
    car.brake();
    cout << "Speed after braking: " << car.getSpeed() << " km/h" << endl;
    car.calculateFuelEfficiency();

    // Creating a truck object
    Truck truck("Ford", "F-150", 50, 1000); // Make, model, speed, cargo capacity
    cout << "\nTruck Details:" << endl;
    cout << "Make: " << truck.getMake() << endl;
    cout << "Model: " << truck.getModel() << endl;
    cout << "Speed: " << truck.getSpeed() << " km/h" << endl;
    truck.accelerate();
    cout << "Speed after acceleration: " << truck.getSpeed() << " km/h" << endl;
    truck.brake();
    cout << "Speed after braking: " << truck.getSpeed() << " km/h" << endl;
    truck.calculateFuelEfficiency();

    return 0;
}


