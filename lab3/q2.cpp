/*
name:Muhammad Abbas
ID:23lk-0068
purpose: program with water bottle class ad getter setter methods
*/

#include <iostream>

using namespace std;

//defining class for a water bottle
class WaterBottle {
    //private attributes
	private:
        string company;
		string color;
        float water_capacityL;
        float water_capacityML;
    
    //public getter and setter methods
    public:
        void setCompany(string acompany) {
            company = acompany;
        }
        
		void setColor(string acolor) {
            color = acolor;
        }
        
		void setwatercapacityL(float awater) {
            water_capacityL = awater/1000;
        }
    
	    void setwatercapacityML(float awater) {
            water_capacityML = awater;
        }
    
	    string getcompany() {
            return company;
        }
    
	    string getcolor() {
            return color;
        }
        
		float getwatercapacityL() {
            return water_capacityL;
       }
    
	   float getwatercapacityML() {
            return water_capacityML;
       }
};

int main() {
	
	//defining a instace of the class called an object
    WaterBottle bottle;
    
	float water_in_ml;
	//giving values to the setter functions
    bottle.setColor("blue");
    bottle.setCompany("nestle");

    cout<<"Enter amount of water consumed";
    cin>>water_in_ml;
    bottle.setwatercapacityL(water_in_ml);
    bottle.setwatercapacityML(water_in_ml);
    //printing the relevant data
    cout<<"Drank "<<bottle.getwatercapacityL()<<" liters or "<<bottle.getwatercapacityML()<<" mililiters from a "<<bottle.getcolor()<<" colored bottle of the "<<bottle.getcompany()<<"nestle"<<endl;

    return 0;
}
