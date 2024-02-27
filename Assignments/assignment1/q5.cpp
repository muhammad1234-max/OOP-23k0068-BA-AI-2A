/*
Name:Muhammad Abbas
id: 23k-0068
Purpose: a restaurant coupon code management system
*/

#include <iostream>

using namespace std;

class restaurant{
	private:
		string name;
		string location;
		string menu_list[5];
		float prices[5];
		string coupon_codes[5];
		//static variable to record number of coupons already used
		static int redeemed_coupons;
		
	public:
		
		//parameterized constructor with initializer list
		restaurant(string aname, string loc, string* menu, float* price, string* coupons) {
            name=aname;
			location = loc;
			for(int i=0 ;i<5;i++) {
				menu_list[i] = menu[i];
				prices[i] = price[i];
                coupon_codes[i] = coupons[i];
			}
            
        }
        
        
        
		
		void display_menu() {
			cout<<"this is the menu of the restaurant "<<name<<endl;
			for(int i =0; i<5;i++) {
				cout<<"menu item "<<i<<" is "<<menu_list[i]<<" with the price $"<<prices[i]<<endl;
			}
			cout<<endl;
		}
		
		void generate_bill(int* quantity) {
			float sum = 0;
			cout<<"\n\nbill for "<<name<<endl;
			for(int i =0; i<5;i++) {
				if(quantity[i]!=0) {
					cout<<"item name: "<<menu_list[i]<<"\tquantity: "<<quantity[i]<<" \tprice: $"<<prices[i]*quantity[i]<<endl;
					sum =sum+ (prices[i] * quantity[i]);
				}
			}
			cout<<"the total amount is: $"<<sum<<endl;
		}
		
		//function to check if coupon codes are valid
		bool valid_coupon(string code) {
			for(int i=0;i<5;i++) {
				if(coupon_codes[i]==code) {
					return true;
				}
			}
			return false;
		}
		
		static int get_redeemed_coupons_count() {
			return redeemed_coupons;
		}
		
};



class BOGOCoupon{
	public:
		//specific alphanumeric code to identify coupon
		string code;
		//month number will be used to check validity
		int valid_from;
		int valid_until;
		//special code to show which restaurant is the coupon associated with
		string restaurant_name;
		
	public:
		//parameterized constructor with initializer list
		BOGOCoupon(string acode, int from, int until, string restaurant) : code(acode), valid_from(from), valid_until(until), restaurant_name(restaurant) {}
        
        bool is_valid(string restaurant, string code, int current_month) {
        	//checking if coupon is of the selected restaurant
			if(restaurant_name!=restaurant) {
        		cout<<"this coupon does not belong to this restaurant"<<endl;
        		return false;
			}
			
			//checking the expiry date of the coupon code
			if(current_month >= valid_from && current_month <= valid_from) {
				cout<<"coupon is valid"<<endl;
				return true;
			} else {
				cout<<"the coupon has expired"<<endl;
				return false;
			}
		}
		
};

class user:  public BOGOCoupon{
	private:
		string name;
		int age;
		string mobile_num;
		//pointer to array of strings holding the coupons held by the user and the coupons that have already been used by the user
	public:
		string* coupons;
		string* redeemed_coupons;
		
	public:
		//parameterixed constructor with initalizer list and constructor of inherited class as well
	    user(string n, int a, string mobile, string acode, int from, int until, string restaurant) :
            BOGOCoupon(acode, from, until, restaurant), name(n), age(a), mobile_num(mobile) {
            //using DMA for giving storage to these arrays
            coupons = new string[5];
            redeemed_coupons = new string[5];
        }
        
        //destructor
        ~user() {
            delete[] coupons;
            delete[] redeemed_coupons;
        }
        
        //function to add a coupon to the coupon list of the user
        void accumulate_coupon(string coupon) {
           //assuming coupons list is not full
            for (int i = 0; i < 5;i++) {
            	//will find next empty space and store the coupon code in that space
                if (coupons[i] == "") {
                    coupons[i] = coupon;
                    break;
                }
            }  
        }
		
		//using inherited method from base class BOGOCoupon for this function implementation
		bool Has_valid_coupon(string code, string restaurant, int current_month) {
			for(int i=0;i<5;i++) {
				if(redeemed_coupons[i]!=code) {
					if (is_valid(restaurant, code, current_month)) {
				            return true;
			        } 
			        return false;
		        } else {
		        	cout<<"coupon has already been redeemed"<<endl;
		        	return false;
				}
						
			}
		}
		
		//function to redeem coupon code with validity checks made with another function within the same class
		bool redeem_coupon(string code, string restaurant, int current_month) {
			
			if(!Has_valid_coupon(code, restaurant, current_month) ) {
                cout<<"Coupon is not valid check validity"<<endl;
                return false;
            } else {
            	//if coupon is vaid it is redeemed successfully
            	for(int i=0;i<5;i++) {
            		if(redeemed_coupons[i]=="") {
            			redeemed_coupons[i]=code;
            			cout<<"coupon redeemed successfully"<<endl;
            			return true;
					}
				}
			}
			cout<<"coupon not found"<<endl;
		}

};

//simulated various functionaities in the main function
int main() {
	cout<<"Muhammad Abbas\n23k-0068\n\n"<<endl;
	
	//intializing menu for first restaurant
	string food_haven_menu[5] = {"Sushi", "Pad Thai", "Mango Tango", "",""};
	//initalizing prices for the above dishes
    float food_haven_prices[5] = {10.99, 12.99, 8.99,0,0};
    string food_haven_coupons[5] = {"FH-BOGO-12345", "","","",""};
    //initializig object of type restaurant with all values
	restaurant food_haven("Food Haven", "City Center", food_haven_menu, food_haven_prices, food_haven_coupons);
    
    //menu for the second restaurant
    string pixel_bites_menu[5] = {"Binary Burger", "Quantum Quinoa", "Data Donuts", "",""};
    //prices for the above items
	float pixel_bites_prices[5] = {8.99, 10.99, 6.99,0,0};
    string pixel_bites_coupons[5] = {"PB-BOGO-67890", "","","",""};
    //instance of the class
	restaurant pixel_bites("Pixel Bites", "Cyber Street", pixel_bites_menu, pixel_bites_prices, pixel_bites_coupons);

    food_haven.display_menu();
    pixel_bites.display_menu();
    
    
    
    //initializing coupon objects
    BOGOCoupon coupon1("FH-BOGO-12345",3,6,"Food Haven");
    BOGOCoupon coupon2("PB-BOGO-6789",2,5,"Pixel Bites");
    BOGOCoupon coupon3("PB-BOGO-67890",2,5,"Pixel Bites");
    
    //a user object to use this system
    user User("Muhammad", 20, "03322236757","FH-BOGO-12345",3,6,"Food Haven");
    User.accumulate_coupon("FH-BOGO-12345");
    User.accumulate_coupon("PB-BOGO-67890");
    User.accumulate_coupon("PB-BOGO-6789");

    cout<<"a instance where coupon is valid"<<endl;
    if (User.Has_valid_coupon(coupon1.code, coupon1.restaurant_name, 3)) {
        if (User.redeem_coupon(coupon1.code, coupon1.restaurant_name, 3)) {
            cout << "Coupon redeemed successfully!" <<endl;
        }
    }
    
    cout<<"\na instance where the coupon code in entered incorrectly:"<<endl;
    if (User.Has_valid_coupon(coupon2.code, coupon2.restaurant_name, 3)) {
        if (User.redeem_coupon(coupon2.code, coupon2.restaurant_name, 3)) {
            cout << "Coupon redeemed successfully!" <<endl;
        }
    }
    
    cout<<"\na instance where the coupon entered has already been redeemed"<<endl;
    if (User.Has_valid_coupon(coupon1.code, coupon1.restaurant_name, 3)) {
        if (User.redeem_coupon(coupon1.code, coupon1.restaurant_name, 3)) {
            cout << "Coupon redeemed successfully!" <<endl;
        }
    }
    
    cout<<"\ndemonstrating printing the bill when a user chooses something to order"<<endl;
    
    cout<<"lets say we are generating a bill for the food haven restaurant"<<endl;
    
    int quantity[5];
	for(int i=0; i<5; i++) {
    	cout<<"enter quantity for menu item "<<i+1<<endl;
    	cin>>quantity[i];
	}
	food_haven.generate_bill(quantity);
	
	cout<<"\nnow lets say we are generating a bill for the pixel bites restaurant"<<endl;
    int quantity2[5];
	for(int i=0; i<5; i++) {
    	cout<<"enter quantity for menu item "<<i+1<<endl;
    	cin>>quantity2[i];
	}
	pixel_bites.generate_bill(quantity2);
    
	
}
