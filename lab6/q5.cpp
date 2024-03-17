/*
Name: Muhammad Abbas
ID:23k-0068
Purpose:Program for students and the courses they have enrolled in
*/
#include <iostream>
#include <string>

using namespace std;

class Course {
    private:
        string courseCode;
        string courseName;
        int creditHours;

    public:
    	//default constructor
    	Course() {
    		courseCode="";
    		courseName="";
    		creditHours=0;
		}
		
    	//parameterized constructor with initializer list
        Course(string acode, string aname, int hours) : courseCode(acode), courseName(aname), creditHours(hours) {}

        //getter methods
        string getCourseCode() const {
            return courseCode;
        }

        string getCourseName() const {
            return courseName;
        }

        int getCreditHours() const {
            return creditHours;
        }
};

class Student {
    private:
        string studentID;
        string studentName;
        //array of data type courses to store all courses the student is enrolled in
        Course* enrolledCourses;
        int numCourses;

    public:
        //parameterized constructor
        Student(string id, string name, Course* courses, int count) : studentID(id), studentName(name), enrolledCourses(courses), numCourses(count) {}

       void enroll(const Course& course) {
    // Allocate memory for the new array
    Course* temp = new Course[numCourses + 1];
    // Copy existing courses to the new array
    for (int i = 0; i < numCourses; i++) {
        temp[i] = enrolledCourses[i];
    }
    // Add the new course
    temp[numCourses] = course;
    // Delete the old array and save the new array
    delete[] enrolledCourses;
    enrolledCourses = temp;
    // Increment the course count
    numCourses++;
}

void drop(const Course& course) {
    // Search for the course in the array
    int index = -1;
    for (int i = 0; i < numCourses; i++) {
        // Finding index of desired course based on course code
        if (enrolledCourses[i].getCourseCode() == course.getCourseCode()) {
            index = i;
            break;
        }
    }
    
    // If required course code is found
    if (index != -1) {
        // Create a new array with one less element
        Course* temp = new Course[numCourses - 1];
        // Copy elements before the dropped course
        for (int i = 0; i < index; i++) {
            temp[i] = enrolledCourses[i];
        }
        // Copy elements after the dropped course
        for (int i = index + 1; i < numCourses; ++i) {
            temp[i - 1] = enrolledCourses[i];
        }
        // Remove the old array and assign the new array
        delete[] enrolledCourses;
        enrolledCourses = temp;
        // Reduce the course count by 1
        numCourses--;
    }
}


    //getter method to get total credit hours
    int getTotalCreditHours() const {
        int totalCreditHours = 0;
        for (int i = 0; i < numCourses;i++) {
            totalCreditHours += enrolledCourses[i].getCreditHours();
        }
        return totalCreditHours;
    }

    //display function to print enrolled courses
    void displayEnrolledCourses() const {
        cout<<"Enrolled Courses for Student "<<studentID<<" - "<<studentName<<":\n";
        for (int i = 0; i < numCourses; i++) {
            cout<<"Course Code: "<<enrolledCourses[i].getCourseCode()<<endl;
			cout<<"Course Name: "<<enrolledCourses[i].getCourseName()<<endl;
            cout<<"Credit Hours: "<< enrolledCourses[i].getCreditHours()<<endl;
        }
    }

    // Destructor to deallocate memory
    ~Student() {
        delete[] enrolledCourses;
    }
};

int main() {
	cout<<"Muhammad Abbas\n23k-0068\n\n"<<endl;
	
    Course course1("OOP101", "Object-oriented-programming", 3);
    Course course2("MATH345", "Multivariable Calculus", 4);
    Course course3("PHY851", "applied physics", 3);
    Course course4("ENG101", "English Composition", 3);
    Course course5("BIO201", "Biology", 4);

    //array of all the courses 
    Course courses[] = {course1, course2, course3};

    //Create a student and enroll in courses
    Student student("23k-001", "Ahmed", courses, 3);

    // Print enrolled courses
    student.displayEnrolledCourses();
    
    //enrolling in a course
    student.enroll(course5);
    //dropping a course
    student.drop(course4);

    //Print enrolled courses after dropping a course and enrolling in a course
    cout << "\nAfter changing courses:\n";
    student.displayEnrolledCourses();

    //find total credit hours
    cout<<"\nTotal Credit Hours: "<<student.getTotalCreditHours()<<endl;

    return 0;
}
