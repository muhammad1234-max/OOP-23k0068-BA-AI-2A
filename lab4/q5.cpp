/*
Name:Muhammad Abbas
ID:23K-0068
Purpose:a program to create classes for office and use DMA for array memory allocaion
*/

#include<iostream>
#include<string>

using namespace std;

class office {
private:
    string location;
    int seatingCapacity;
    //pointer to array furiture that wil store all the furniture in the office
    string* furniture;

public:
    // Parameterized constructor with default values and dynamic memory allocation for furniture array
    office(string loc = "", int capacity = 0, int furniturenum=3) :
        location(loc), seatingCapacity(capacity) {
        	furniture= new string[furniturenum]; 
		}
    
    //destructor to de-alocate memory for furniture array
    ~office() {
        delete[] furniture;
    }
    
    //function to set furniture in the array at the next available location
    void set_furniture(int index, const string& item/*address of an item of the array furniture is being given1*/) {
    	furniture[index]=item;
	}
    
    // Function to display office information
    void displayInfo() {
        cout<<"Location: "<<location<<endl;
        cout<<"Seating Capacity: "<<seatingCapacity<<endl;
        cout<<"Furniture: ";
        for(int i=0;i<3;i++) {
            cout<<furniture[i]<<", ";
            
        }
        cout<<endl;
    }
};

int main() {
	
	//initializing a pointer of type office to store the object of the class and giing it inital values of some data members
	office* Officeptr = new office ("clifton",100,3);
	
	//giving values to the 
	Officeptr->set_furniture(0,"table");
	Officeptr->set_furniture(1,"kursi");
	Officeptr->set_furniture(2,"PC"); 
	

    // Displaying the office information
    cout<<"Office Info:"<<endl;
    Officeptr->displayInfo();
    cout<<endl;
    
    //clearing the dynamically allocated memory
    delete Officeptr;

    
    return 0;
}
