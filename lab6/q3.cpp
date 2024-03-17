/*
Name: Muhammad Abbas
id:23k-0068
Purpose: Hair saloon program to calculate average appointment cost
*/
#include <iostream>

using namespace std;

class appointment {
    private:
        string Name;
        double cost;
        static int totalAppointments;
        static double totalEarnings;

    public:
    	//parameterized constructor
        appointment(const string& name, double acost) : Name(name), cost(acost) {
            totalAppointments++;
            totalEarnings += cost;
        }
        
        //static function to calculate average cost of each appointment
        static double averageCost() {
            //returns 0 if no appointments have been made to avoid division by zero error
			if (totalAppointments == 0) {
                return 0; 
            }
            //calculating average
            return totalEarnings/totalAppointments;
        }
        
        //getter functions
        string getName() const {
            return Name;
        }

        double getCost() const {
            return cost;
        }
        
        void displayAppointment() const {
            cout<<"Customer Name: "<<Name<<"\nAppointment Cost: $" <<cost<<endl;
            cout<<endl;
        }
};

//Initializing static data members
int appointment::totalAppointments = 0;
double appointment::totalEarnings = 0;

int main() {
	cout<<"Muhammad Abbas\n23k-0068\n\n"<<endl;
	
    //creating appointments with different details
    appointment appointment1("muhammad", 89.0);
    appointment appointment2("ali", 46.0);
    appointment appointment3("Ahmed", 64.0);
    appointment appointment4("Adil", 36.0);
    
    //displaying all the customer data
    appointment1.displayAppointment();
    appointment2.displayAppointment();
    appointment3.displayAppointment();
    appointment4.displayAppointment();

    //Calculate and display average cost per appointment
    cout<<"average cost per appointment: $" <<appointment::averageCost()<<endl;

    return 0;
}
