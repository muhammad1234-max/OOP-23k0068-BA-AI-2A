/*
Name:Muhammad Abbas
ID:23K-0068
Purpose:a program to create classes for office and pass different number of arguments
*/

#include<iostream>
#include<string>

using namespace std;

class office {
private:
    string location;
    int seatingCapacity;
    string furniture[3];

public:
    // Parameterized constructor with default values
    office(string loc = "", int capacity = 0, string furn1 = "", string furn2 = "", string furn3 = "") :
        location(loc), seatingCapacity(capacity), furniture{furn1, furn2, furn3} {}

    // Function to display office information
    void displayInfo() {
        cout<<"Location: "<<location<<endl;
        cout<<"Seating Capacity: "<<seatingCapacity<<endl;
        cout<<"Furniture: ";
        for(int i=0;i<3;i++) {
            cout<<furniture[i];
            if(i!=2)cout<<", ";
        }
        cout<<endl;
    }
};

int main() {
    office office1; // no arguments given
    office office2("Building A"); // One argument gave
    office office3("Building B", 50); // Two arguments passed
    office office4("Building C", 100, "table", "kursi", "pc"); // Three arguments pass

    // Displaying all the office information
    cout<<"Office 1 Info:"<<endl;
    office1.displayInfo();
    cout<<endl;

    cout<<"Office 2 Info:"<<endl;
    office2.displayInfo();
    cout<<endl;

    cout<<"Office 3 Info: "<<endl;
    office3.displayInfo();
    cout<<endl;

    cout<<"Office 4 Info:"<<endl;
    office4.displayInfo();
    cout << endl;

    return 0;
}
