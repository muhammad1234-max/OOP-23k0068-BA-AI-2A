/*
 * Name:Muhammad abbas
 * id:23k-0068
 * purpose: using generic templates and polymorphism to show classes interacting with each other
 * */

#include <iostream>
#include <string>

using namespace std;

//base Pet class generic template
template <typename T>
class Pet {
protected:
    string name;
    int age;

public:
    //parameterized constructor
    Pet(const string& n, int a) : name(n), age(a) {}

    //pure virtual function to represent the pet's sound
    virtual void makeSound() const = 0;

    //getter methods which are constant to protect data while returning
    string getName() const {
        return name;
    }
    int getAge() const {
        return age;
    }
};

//special derived pet classes
class Cat : public Pet<Cat> {
public:
    //constructor with base class constructor
    Cat(const string& n, int a) : Pet<Cat>(n, a) {}

    //implementation of makeSound function for this class (overriding)
    void makeSound() const override {
        cout << "Meow!" << endl;
    }
};

class Dog : public Pet<Dog> {
public:
    //constructor
    Dog(const std::string& n, int a) : Pet<Dog>(n, a) {}

    //implementation 2
    void makeSound() const override {
        cout << "Woof!" << endl;
    }
};

class Bird : public Pet<Bird> {
public:
    // Constructor
    Bird(const std::string& n, int a) : Pet<Bird>(n, a) {}

    //implementation 3
    void makeSound() const override {
        cout << "Chirp!" << endl;
    }
};

int main() {
    cout<<"muhammad abbas" <<endl;
    cout<<"23k-0068" <<endl;
    // Create instances of different pets
    Cat cat("Tom", 3);
    Dog dog("Jack", 5);
    Bird bird("fluffy", 2);

    //saving address of these objects in pointers
    //accessing their functions with these pointers wil show polymorphism
    Pet<Cat>* catPtr = &cat;
    Pet<Dog>* dogPtr = &dog;
    Pet<Bird>* birdPtr = &bird;

    // Display each pet's information and make them produce their unique sound
    cout << "Cat: " << catPtr->getName() << ", Age: " << catPtr->getAge() << ", Sound: ";
    catPtr->makeSound();

    cout << "Dog: " << dogPtr->getName() << ", Age: " << dogPtr->getAge() << ", Sound: ";
    dogPtr->makeSound();

    cout << "Bird: " << birdPtr->getName() << ", Age: " << birdPtr->getAge() << ", Sound: ";
    birdPtr->makeSound();

    return 0;
}

