/*
name:Muhammad Abbas
ID;23k-0068
purpose: this is a basic calender management system that can add tasks remove them and display the itenary of the whole year
*/

#include <iostream>
#include <string>
#include <cstdlib> //header file to use exit function
#include <unistd.h> //header file to use sleep function to pause the program

using namespace std;

//class to hold the data of the calender
class Calendar {
private:
	//a array for the 12 months of the year
    string months[12];
    // a 2D array to hold task for all the days of the year (february"s less days havent been accounted for here)
    string tasks[12][31];
    int currentYear;

public:
	//constructor function to initialize calender objects for different years
    Calendar(int year) : currentYear(year) {}
    
    //function to add tasks in 2-d tasks array and with validation for february included
    void addTask(int month, int day, const string& task) {
    	if(month==2) {
    		if(day>=1 && day<=28) {
    			tasks[month - 1][day - 1] = task;
                cout << "Task added successfully on " << day << "/" << month << "/" << currentYear << endl;
			} else{
				cout<<"invalid date!"<<endl;
			}
		} else if (month >= 1 && month <= 12 && day >= 1 && day <= 31) {
            tasks[month - 1][day - 1] = task;
            cout << "Task added successfully on " << day << "/" << month << "/" << currentYear << endl;
        } else {
            cout << "Invalid date!" << endl;
        }
        
    }
    
    //function to remove tasks from the 2-d tasks array
    void removeTask(int month, int day) {
        if(month==2) {
    		if(day>=1 && day<=28) {
    			tasks[month - 1][day - 1] = "";
                cout << "Task removed successfully from " << day << "/" << month << "/" << currentYear << endl;
			} else{
				cout<<"invalid date!"<<endl;
			}
		} else if (month >= 1 && month <= 12 && day >= 1 && day <= 31) {
            tasks[month - 1][day - 1] = "";
            cout << "Task removed successfully from " << day << "/" << month << "/" << currentYear << endl;
        } else {
            cout << "Invalid date!" << endl;
        }
    }
    
    //function to display all the tasks throughout the year in a organized format
    void displayTasks() {
        cout << "Tasks for the year " << currentYear << ":" << endl;
        for (int i = 0; i < 12; ++i) {
            cout << "Month " << i + 1 << ":" << endl;
            for (int j = 0; j < 31; ++j) {
                if (!tasks[i][j].empty()) {
                    cout << j + 1 << "/" << i + 1 << ": " << tasks[i][j] << endl;
                }
            }
        }
    }
    
};

int main() {
	int year,choice;
	
    cout<<"welcome to calendar management system\n"<<endl;
    cout<<"enter the year for which you want to create a calender:"<<endl;
    cin>>year;
    cin.ignore(); //to clear the input buffer
    //declaring an instance of the calender object
    Calendar myCalendar(year);
    cout<<"\ncalender successfully created"<<endl;
    
    //loop that will contine to run until user exits the program
    while(true) {
	    
	    //user interface to choose functionality
        cout << "\n\n\t\t\t\t********choose from the following options:*******\n\n" << endl;
        cout << "\t\t\t\t|-----------------------------------------------|" << endl;
        cout << "\t\t\t\t|-----------------------------------------------|" << endl;
        cout << "\t\t\t\t|    1)add a task in the calender               |" << endl;
        cout << "\t\t\t\t|    2)remove a task from the calender          |" << endl;
        cout << "\t\t\t\t|    3)display all the tasks in the calender    |" << endl;
        cout << "\t\t\t\t|    4)exit                                     |" << endl;
        cout << "\t\t\t\t|-----------------------------------------------|" << endl;
        cout << "\t\t\t\t|-----------------------------------------------|" << endl;
        cout << "enter your choice:" << endl;
        cin >> choice;
    
        int rday,rmonth;
        string details;
        int day,month;
    
	    switch(choice) {
    	    case 1:
    		    cin.ignore();//ignoring newline character in the input buffer
    		    cout<<"enter the detail of the task you want to add:"<<endl;
    		    getline(cin,details);
    		    cout<<"enter the day of the task"<<endl;
    		    cin>>day;
    		    cout<<"enter the month of the task"<<endl;
    		    cin>>month;
    		    //calling the repective method of the object
    		    myCalendar.addTask(month, day, details);
    		    break;
    	
    	    case 2:
    		    cout<<"enter the day of the task you want to remove:"<<endl;
    		    cin>>rday;
    		    cout<<"enter the month of the task you want to remove:"<<endl;
    		    cin>>rmonth;
    		    myCalendar.removeTask(rmonth, rday);
    		    break;
    		
    	    case 3:
    		    myCalendar.displayTasks();
    		    break;
    		
    	    case 4:
    		    cout<<"thank you for using our calender please come again:)"<<endl;
    		    exit(0);//exit function to leave the program
    		    break;
    		
    	    default:
    		    cout << "wrong choice, the program will pause for a few seconds then try again" << endl;
                sleep(3); //function to pause the program for 3 secods
                system("cls");//function to clear the command console
                continue; //keyword to continue to next iteration of the loop
    		
        }
    }
    return 0;

}
