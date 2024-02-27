/*
name:Muhammad Abbas
id:23k-0068
purpose: table management system
*/

#include <iostream>

using namespace std;

class Table {
    private:
	    //since it can only be 4 or 8 seats
        const int capacity;
        int occupiedSeats;
        bool clean;

    public:
        //Default constructor with initializer list
        Table() : capacity(4), occupiedSeats(0), clean(true) {}

        //Parameterized constructor initializer list is used as capacity is const so it cannot be changes using normal data assignment
        Table(int cap) : capacity((cap == 8 || cap == 4) ? cap : ((cap + 2) / 4 * 4)), clean(true), occupiedSeats(0) {}
        
        //all getters are intiialized as constant to make sure data isnt altered when being returned
        //Getter for capacity of the tabel
        int getCapacity() const {
            return capacity;
        }

        //Getter for occupied Seats of the table
        int getOccupiedSeats() const {
            return occupiedSeats;
        }

        //Getter for clean
        bool isClean() const {
            return clean;
        }

        //Function to use the table
        void useTable(int groupSize) {
        	// table can only be used if table is clean and group size if suitable for the table capacity(4 or 8)
            if(clean && groupSize<=capacity) {
                occupiedSeats=groupSize;
                cout<<"Table with capacity "<<capacity<<" is now occupied by a group of "<<groupSize<<endl;
            } else {
                cout<<"Table cannot be used by this group."<<endl;
            }
        }

        //Function for having lunch on the table
        void haveLunch() {
        	//table is no longer clean after lunch is had on the table
            clean=false;
            cout<<"Lunch is being had on the table."<<endl;
        }

        //Function for leaving the table
        void leaveTable() {
            occupiedSeats = 0;
            cout<<"occupants have left the table."<<endl;
        }

        // Function to clean the table
        void cleanTable() {
        	//if noone is sitting at the table so table can be cleaned
            if(occupiedSeats==0) {
                clean=true;
                cout<<"Table has been cleaned."<<endl;
            } else {
                cout<<"people are sitting at the table currently it cant be cleaned"<<endl;
            }
        }
};

//Globallly accessable function to occupy or use a table
void OccupyTable(Table tables[]/*array of tables*/, int groupSize) {
    for(int i=0;i<5;i++) {
    	//if current table that is being checked is not clean then move on to another table(next iteration of the loop) to seat the people
        if(!tables[i].isClean()) continue;
        //if num of people can be seated in the capacity of the table then use this table
        if (groupSize <= tables[i].getCapacity()) {
            tables[i].useTable(groupSize);
            return;
        }
    }
    cout << "No suitable table available."<<endl;
}

//Globally accessable function to empty a table
void EmptyTable(Table tables[], int tableNumber) {
	//emptying one of the 5 available tables
    if (tableNumber>=0 && tableNumber<5) {
    	//emptying a table and then cleaning it
        tables[tableNumber].leaveTable();
    } else {
        cout<<"Invalid table number."<<endl;
    }
}


int main() {
	cout<<"Muhammad Abbas\n23k-0068\n\n"<<endl;
	cout<<"welcome to table management system\n\n"<<endl;
	
    //initializing an array of 5 tables with their capacities
    Table tables[5] = {Table(8), Table(8), Table(4), Table(4), Table(4)};

    //Occupying table 1 with a group of 4
    cout<<"table1"<<endl;
    OccupyTable(tables, 4);
    cout<<endl;
    cout<<"table2"<<endl;
    //Occupying table 2 with a group of 6
    OccupyTable(tables, 6);
    cout<<endl;

    //Performing some actions on table 1
    //using table
    cout<<"actions being performed on table 1"<<endl;
    tables[0].useTable(4);
    //occupants having lunch on the table
    tables[0].haveLunch();
    //occupants leaving the table
    tables[0].leaveTable();
    //cleaning the table
    tables[0].cleanTable();
    cout<<endl;
    //Empty table 2 so index 1 is used as that is the second table
    cout<<"table2"<<endl;
    EmptyTable(tables, 1);

    return 0;
}
