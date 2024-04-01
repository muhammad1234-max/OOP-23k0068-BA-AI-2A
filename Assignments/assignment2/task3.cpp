/*
Name: Muhammad Abbas
id: 23k-0068
purpose: Daraz customer loyalty system 
*/

#include <iostream>

using namespace std;

class DarazPersonData {
	private:
		string lastname;
		string firstname;
		string address;
		string city;
		string state;
		string zip;
		string phone;
		
	public:
		//getter functions
		string get_lname() const {
			return lastname;
		}
		string get_fname() const {
			return firstname;
		}
		string get_address() const {
			return address;
		}
		string get_city() const {
			return city;
		}
		string get_state() const {
			return state;
		}
		string get_zip() const {
			return zip;
		}
		string get_phone() const {
			return phone;
		}
		//setter functions
		void set_lname(string lname) {
			lastname=lname;
		}
		void set_fname(string fname) {
			firstname=fname;
		}
		void set_address(string add) {
			address=add;
		}
		void set_city(string acity) {
			city=acity;
		}
		void set_state(string astate) {
			state=astate;
		}
		void set_zip(string azip) {
			zip=azip;
		}
		void set_phone(string aphone) {
			phone=aphone;
		}
};

//inheritance to provide complete info about the customer
class DarazCustomerData : public DarazPersonData {
	private:
		int customernum;
		int loyaltypoints;
		
	public:
		//getter functions
		int get_num() const {
			return customernum;
		}
		int get_loyaltypoints() const {
			return loyaltypoints;
		}
		//setter functions
		void set_num(int number) {
			customernum=number;
		}
		void set_lpoints(int lp) {
			if (lp >= 0) {
            	loyaltypoints = lp;
        	} else {
            	cout<<"Invalid loyalty points value. Loyalty points cannot be negative."<<endl;
        	}
		}
};

//all functions in this class are static because they all need to be associate with the class itself rather then the object
class DarazLoyaltyProgram {
	public:

       	static void addLoyaltyPoints(DarazCustomerData& customer, int points) {
        	int currentPoints = customer.get_loyaltypoints();
        	customer.set_lpoints(currentPoints + points);
        	cout<<points<<" loyalty points added for customer# "<<customer.get_num()<<endl;
    	}

    	static void redeemLoyaltyPoints(DarazCustomerData& customer, int points) {
        	int currentPoints = customer.get_loyaltypoints();
        	if (currentPoints >= points) {
            	customer.set_lpoints(currentPoints - points);
            	cout<<points<<" loyalty points redeemed for customer# "<<customer.get_num()<<endl;
        	} else {
            	cout<<"Insufficient loyalty points for point redemption."<<endl;
        	}
    	}

    	static void displayTotalLoyaltyPoints(const DarazCustomerData& customer) {
        	cout<<"Total loyalty points for customer# "<<customer.get_num()<<": "<< customer.get_loyaltypoints()<<endl;
    	}
};

int main() {
	cout<<"Muhammad Abbas\n23k-0068\n\n"<<endl;
	
	cout<<"scenario 1"<<endl;
	DarazCustomerData customer1;
    customer1.set_num(1111);
    customer1.set_lpoints(100);
    //scope resolution operator is used to access the static functions
    DarazLoyaltyProgram::addLoyaltyPoints(customer1, 50);
    DarazLoyaltyProgram::redeemLoyaltyPoints(customer1, 30);
    DarazLoyaltyProgram::displayTotalLoyaltyPoints(customer1);
    cout<<"\n\n";
    
    cout<<"scenario 2"<<endl;
	DarazCustomerData customer2;
    customer2.set_num(1100);
    customer2.set_lpoints(10);
    DarazLoyaltyProgram::addLoyaltyPoints(customer2, 50);
    DarazLoyaltyProgram::redeemLoyaltyPoints(customer2, 90);
    DarazLoyaltyProgram::displayTotalLoyaltyPoints(customer2);
    return 0;
}
