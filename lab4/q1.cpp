/*
Name:Muhammad Abbas
id:23k-0068
purpose: a program that checks if book is completed or not and if not then in which pages is the reader present
*/

#include<iostream>

using namespace std;

class book{
	private:
	    string name;
	    string author;
	    int ISBN;
	    int totalpages;
	    int currentpagesread;
	    
	public:
		//default constructor function
		book() {
			name="";
			author="";
			ISBN=0;
			totalpages=0;
			currentpagesread=0;
		}
		
		//parameterized constructor function
		book(string aname, string aauthor, int aisbn, int total, int current) {
			name=aname;
			author=aauthor;
			ISBN=aisbn;
			totalpages=total;
			currentpagesread=current;
		}
		
		//function to update pages and to check if book is finished
		void read() {
			if(currentpagesread<totalpages) {
				currentpagesread++;
				cout<<"you have read the page "<< currentpagesread<<endl;
			} else {
				cout<<"book is finished"<<endl;
			}
		}
};

int main () {
	
	//initializing a object of the class
	book Book("harry potter","jk-rowling",234567,3,0);
	
	//attempted to read 4 pages
	Book.read();
	Book.read();
	Book.read();
	Book.read();
	
	
	
}
