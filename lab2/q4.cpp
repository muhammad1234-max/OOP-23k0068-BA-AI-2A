/*
name: Muhammad Abbas
id=23k-0068
purpose: a database for student data implemented by structures
*/

#include <iostream>
#include <string>//getline fuction wont have to be used for string input by using this header file
using namespace std;

// Define structure for Register
struct Register {
    int courseId;
    string courseName;
};

// Define structure for Student, which will inherit the properties of Register
struct Student : public Register {
    int studentId;
    string firstName;
    string lastName;
    string cellNo;
    string email;
};

int main() {
    // Create an array of structures to store data for 5 students
    Student students[5];

    // Taking data for each student
    for (int i = 0; i < 5; i++) {
        cout<<"Enter details for student "<<i + 1<<":"<< endl;
        cout<<"Course ID: ";
        cin>>students[i].courseId;
        cout<< "Course Name: ";
        cin.ignore(); //clearing input buffer
        getline(cin, students[i].courseName);
        cout<< "Student ID: ";
        cin>> students[i].studentId;
        cout<< "First Name: ";
        cin>> students[i].firstName;
        cout<< "Last Name: ";
        cin>> students[i].lastName;
        cout<< "Cell No: ";
        cin>> students[i].cellNo;
        cout<< "Email: ";
        cin>> students[i].email;
    }

    // Display the info for all 5 students
    cout << "\nStudent Information:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "Student " << i + 1 << ":\n";
        cout << "Course ID: " << students[i].courseId << endl;
        cout << "Course Name: " << students[i].courseName << endl;
        cout << "Student ID: " << students[i].studentId << endl;
        cout << "First Name: " << students[i].firstName << endl;
        cout << "Last Name: " << students[i].lastName << endl;
        cout << "Cell No: " << students[i].cellNo << endl;
        cout << "Email: " << students[i].email << endl;
        cout << endl;
    }

    return 0;
}
