/*
name:Muhammad Abbas
ID:23k-0068
purpose: a program with a class of board marker and its getter and setter methods as long with addtional methods for more functionalities
*/

#include <iostream>

using namespace std;

//main class for board marker
class BoardMarker {
	//private attributes can ony be accessed by code in the class
    private:
        string brand;
        string shade;
        bool refillable;
		bool ink_status;
    
    //getter and setter methods set as public so they can access the data in the privat attributes
    public:
        void setBrand(string nbrand) {
            brand = nbrand;
        }
        
		void setShade(string nshade) {
            shade = nshade;
        }
    
	    void setRefillable(bool refill) {
            refillable = refill;
        }
    
	    void setinkstatus(bool nstatus) {
            ink_status = nstatus;
        }

        string getBrand() {
            return brand;
        }
        
        string getShade() {
            return shade;
        }
        
        bool getRefillable() {
            return refillable;
        }
        
        bool getInkStatus() {
            return ink_status;
        }
    
};

//method to check if ink has run out
void write(BoardMarker marker) {
    if (marker.getInkStatus()) {
        cout<<marker.getBrand()<<" pen writing with a shade of "<<marker.getShade()<<endl;
        marker.setinkstatus(false);
        marker.setRefillable(true);
        return;
    }
    cout<<"depleted ink"<<endl;
}

//method to refill the ink if possible or required
void refill(BoardMarker marker) {
    if (marker.getRefillable()) {
        cout<<"refilling ink"<<endl;
        marker.setRefillable(false);
        marker.setinkstatus(true);
        return;
    }
    cout<<"ink not depleted. can't refill yet"<<endl;
}

int main()
{
	//defining a instance of the class called an object
    BoardMarker marker;
    //passing values in the object using the setter functions
    marker.setBrand("casio");
    marker.setShade("blue");

    write(marker);
    write(marker);
    refill(marker);
    write(marker);

    return 0;
}
