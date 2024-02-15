/*
Name:Muhammad Abbas
id:23k-0068
purpose: a program that is the second version of q1 which checks if book is completed
or not and if not then in which pages is the reader present and in addition displays info about the book
*/

#include<iostream>

using namespace std;

class book{
	private:
	    string name;
	    string author;
	    string ISBN;
	    int totalpages;
	    int currentpagesread;
	    
	public:
		//default constructor function
		book() {
			name="";
			author="";
			ISBN="";
			totalpages=1000;
			currentpagesread=0;
		}
		
		void set_name(string aname){
			name=aname;
		}
		
		void set_author(string aauthor) {
			author=aauthor;
		}
		
		void set_isbn(string aISBN) {
			ISBN=aISBN;
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
		
		//function to display all info about books
		void showBookInfo() {
            cout<<"Name: "<<name<<endl;
            cout<<"Author: "<<author<<endl;
            cout<<"ISBN: "<<ISBN<<endl;
            cout<<"Total Pages: "<<totalpages<<endl;
            cout<<"Pages Read: "<<currentpagesread<<endl;
        }
};

int main () {
	
	//initializing a object of the class
	book Book;
	//using setter methods to give values to the leftover attributes
	Book.set_name("Harry-potter");
	Book.set_author("JK-rowling");
	Book.set_isbn("123456789");
	
	//attempted to read 4 pages
	Book.read();
	Book.read();
	Book.read();
	Book.read();
	//calling functon to show information about the book
	Book.showBookInfo();
	
	
	
}
