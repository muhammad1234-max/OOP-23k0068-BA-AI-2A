/*
Name: Muhammad Abbas
ID:23K-0068
Purpose: code to show hybrid inheritance between peopl in a school
*/


#include <iostream>
#include <string>

using namespace std;

//base class
class Person {
	protected:
    	string name;
    	int age;

	public:
    	//constructor with initializer list
    	Person(string aname, int aage) : name(aname), age(aage) {}

    	void display() const {
        	cout<<"Name: "<<name<<endl;
			cout<<"Age: "<<age<<endl;;
    	}
};

//derived class 1
class Student : public Person {
	protected:
    	string studentID;
    	int gradeLevel;

	public:
    	//constructor with intializer list
    	Student(string& aname, int aage, string astudentID, int agradeLevel) : Person(aname, aage), studentID(astudentID), gradeLevel(agradeLevel) {}


    	void display() const {
    		//existing implementation called
        	Person::display(); 
        	//extra implementation
        	cout <<"Student ID: "<<studentID<<endl;
			cout<<"Grade Level: "<<gradeLevel<<endl;
    	}
};

//derived class 2
class Teacher : public Person {
	protected:
    	string subject;
    	int roomNumber;

	public:
    	Teacher(string aname, int aage, string asubject, int aroomNumber) : Person(aname, aage), subject(asubject), roomNumber(aroomNumber) {}

    	//function to display 
    	void display() const {
        	Person::display(); // Call base class display function
        	cout<<"Subject: "<<subject<<endl;
			cout<<"Room Number: "<<roomNumber<<endl;
        }
};

//derived class with multiple inheritance
class GraduateStudent : public Student, public Teacher {
	public:
		//constructor with initializer list
    	GraduateStudent( string aname, int aage, string astudentID, int agradeLevel, string asubject, int aroomNumber)
        : Student(aname, aage, astudentID, agradeLevel), Teacher(aname, aage, asubject, aroomNumber) {}

    
    	void display() const {
        	Student::display(); // Call display function of Student class
        	cout<<"Teaching Subject: "<<subject<<endl;
			cout<<"Teaching Room Number: "<<roomNumber<<endl;
        }
};

int main() {
    //instance an object 
    GraduateStudent gradStudent("Muhammad Abbas", 20, "12345", 12, "Computer Science", 101);

    // Display details of the graduate student
    cout << "Details of Graduate Student:" <<endl;
    gradStudent.display();

    return 0;
}
