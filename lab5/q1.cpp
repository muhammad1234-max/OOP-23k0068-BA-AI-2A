/*
name: Muhammad Abbas
id: 23k-0068
purpose: a code with a square class and and some sample operations on it
*/
#include<iostream>

using namespace std;

class square {
	private:
		float sidelength;
		float area;
		//static variable to store sum of all areas of all squares
		static float allareas;
		
	public:
		square() {
			sidelength=0;
			area=0;
		}
		
		square(float sidelength) {
			this->sidelength=sidelength;
			area=0;
		}
		
		void calcarea() {
			area= sidelength * sidelength;
			allareas = allareas + area;
		}
		
		void setlength(int sidelength) {
			this->sidelength;
		}
		
		float getsidelength()const {
			return sidelength;
		} 
		
		float getarea()const {
			return area;
		}
		
		static float getallareas() {
			return allareas;
		}
		
};

float square::allareas=0;

int main() {
	square Square1(2.9); //create Square with side length 2.9
    Square1.calcarea();
    cout<<"area of square1: " <<Square1.getarea()<<endl;
    cout<<"All areas: " << square::getallareas() <<endl;

    square Square2(3.6); //create Square with side length 3.6
    Square2.calcarea();
    cout<<"\narea of square2: "<<Square2.getarea()<<endl;
    cout<<"All areas: "<<square::getallareas() <<endl;

    square Square3(4.4); //create Square with side length 4.4
    Square3.calcarea();
    cout<< "\narea of square3: " << Square3.getarea() <<endl;
    cout<< "all areas: " << square::getallareas() <<endl;

}
