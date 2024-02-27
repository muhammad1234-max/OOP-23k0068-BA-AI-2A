/*
Name:Muhammad Abbas
id:23k-0068
purpose: a roller coaster ride manaegment system-
*/

#include<iostream>
#include<string>
#include<cmath>

using namespace std;

class roller_coaster{
	private:
	    string name;
	    //max height the roller coaster can reach
	    float height;
	    //length of the roller coaster track
	    float length;
	    float speed;
	    int capacity;
	    int current_riders;
	    bool ride_in_progress;
	    
	public:
		//default constructor
		roller_coaster() : name("roller coaster"), height(500), length(2000), speed(0), capacity(20), current_riders(0), ride_in_progress(false) {}
		
		//parameterized constructor
		roller_coaster(string aname, float aheight, float alength, float aspeed, int acapacity, int occupiers) {
			name=aname;
			height=aheight;
			length=alength;
			speed=aspeed;
			//checks for the capacity values being made
			if(acapacity>3) {
				if(acapacity%2==0 || acapacity%3==0){
					capacity=acapacity;
				} else{
					 capacity = ((acapacity + 1) / 2) * 2;//formula to round to the nearest multiple of 2
				}
			}else {
				cout<<"minimum limit of people not reached"<<endl;
			}
			current_riders=occupiers;
		}
		
		//setter functions
		void set_name(string aname) {
			name=aname;
		}
		void set_height(float aheight) {
			height=aheight;
		}
		void set_length(float alength) {
			length=alength;
		}
		void set_speed(float aspeed) {
			speed=aspeed;
		}
		void set_capacity(int acapacity) {
			if(acapacity>3) {
				if(acapacity%2==0 || acapacity%3==0){
					capacity=acapacity;
				} else{
					 capacity = ((acapacity + 1) / 2) * 2;;
				}
			}else {
				cout<<"minimum limit of people not yet exceeded"<<endl;
			}
		}
		void set_currentriders(int occupiers) {
			current_riders=occupiers;
		}
		void set_flag(bool aflag) {
			ride_in_progress=aflag;
		}
		
		//getter functions
		string get_name() {
			return name;
		}
		float get_height() {
			return height;
		}
		float get_length() {
			return length;
		}
		float get_speed() {
			return speed;
		}
		int get_capacity() {
			return capacity;
		}
		int get_currentriders() {
			return current_riders;
		}
		bool get_flag() {
			return ride_in_progress;
		}
		
		//function to load riders on the roller coaster
		int loadRiders(int numRiders) {
            if (!ride_in_progress && numRiders<=(capacity-current_riders)) {
                current_riders=current_riders+numRiders;
                return 0; //all riders were successfully seated
            } else {
            	//calculating leftover people after railway is full
                int remainingRiders = numRiders - (capacity - current_riders);
                //since ride is at full capacity               
				current_riders=capacity;
                return remainingRiders; // Return the remaining riders not seated
            }
        }
        
        int startRide() {
        	//if ride is not started yet
            if (!ride_in_progress) {
            	//checking if al the seats in the ride have been occupied or not
                if(current_riders==capacity) {
                    ride_in_progress=true;
                    return 0; //Ride has started successfully
                } else {
                    return capacity - current_riders; //Return number of empty seats yet left
                }
            } else {
                return -1; //this tell that ride is already in progress
            }
        }   
        
        void stopRide() {
        	//stopping the ride if it is in progress
            if (ride_in_progress) {
                ride_in_progress = false;
                cout<<"ride is stopping"<<endl;
            }
        }
        
        void unloadRiders() {
        	if(!ride_in_progress) {
			    current_riders = 0;
				cout<<"unloading people from the ride"<<endl;	
			}
        }
        
        //function to accelerate the ride(my roll number will be added)
        void accelerate(int aspeed) {
        	int digit;
        	//will keep extarcting last digits untill it not zero and then add that digit to the speed of the roller coaster
        	while(aspeed!=0) {
        		digit=aspeed%10;
        		if(digit!=0) {
        		    speed=speed+digit;
        		    cout<<"speed has been accelerated to "<<speed<<endl;
        		    break;
			    } else{
			    	aspeed=aspeed/10;
				}   
			}
		}
		
		//brake function as the same logic as the accelerate function
		void brake(int aspeed) {
        	int digit;
        	//will keep extarcting last digits untill it not zero and then add that digit to the speed of the roller coaster
        	while(aspeed!=0) {
        		digit=aspeed%10;
        		if(digit!=0) {
        		    speed=speed-digit;
        		    cout<<"speed has been slowed down to "<<speed<<endl;
        		    break;
			    } else{
			    	aspeed=aspeed/10;
				}   
			}
		}
		
};

int main() {
	cout<<"Muhammad Abbas\n23k-0068\n\n"<<endl;
	
    //first instance of the class being initialized with the default constructor	
	roller_coaster rollerCoaster1; 
	//second instance of the class being initialized with the default constructor
    roller_coaster rollerCoaster2("playing with life", 600, 2500, 30, 50, 40); 

    //Displaying the roller coaster details
    cout<<"Roller Coaster 1 Details:"<<endl;
    cout<<"Name: " <<rollerCoaster1.get_name()<<endl;
    cout<<"Height: " <<rollerCoaster1.get_height()<<" meters"<<endl;
    cout<<"Length: " << rollerCoaster1.get_length() << " meters"<<endl;
    cout<<"Speed: " << rollerCoaster1.get_speed()<< " km/h"<<endl;
    cout<<"Capacity: " << rollerCoaster1.get_capacity()<<" riders"<<endl;
    cout<<"current riders: "<<rollerCoaster1.get_currentriders()<<endl;
    cout<<endl;

    cout<<"Roller Coaster 2 Details:"<<endl;
    cout<<"Name: " << rollerCoaster2.get_name()<<endl;
    cout<<"Height: " << rollerCoaster2.get_height()<< " meters" <<endl;
    cout<<"Length: " << rollerCoaster2.get_length()<< " meters" <<endl;
    cout<<"Speed: " << rollerCoaster2.get_speed()<< " km/h" <<endl;
    cout<<"Capacity: " << rollerCoaster2.get_capacity()<<" riders"<<endl;
    cout<<"current riders: "<<rollerCoaster2.get_currentriders()<<endl;
    cout<<endl;
    
    //giving my roll number as argument to the brake and accelerate functions
    cout<<"performing actions on roller coaster 2"<<endl;
    if(rollerCoaster2.loadRiders(10)==0) {
    	cout<<"all riders were seated successfuly"<<endl;
	} else {
		cout<<"remaining number of riders are: "<<rollerCoaster2.loadRiders(10)<<endl;
	}
    rollerCoaster2.loadRiders(10);
    rollerCoaster2.startRide();
    rollerCoaster2.accelerate(230068);
    rollerCoaster2.brake(230068);
    rollerCoaster2.stopRide();
    rollerCoaster2.unloadRiders();

    return 0;
	
}
