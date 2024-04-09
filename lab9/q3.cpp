#include <iostream>
#include <string>

using namespace std;

//base class
class Employee {
	//protected so derived classes can access these data attributes
	protected:
    	int employeeID;
    	string employeeName;

	public:
    	//parameterized constructor with initalizer list
		Employee(int id, const string& name) : employeeID(id), employeeName(name) {}
		
		//default implementation. function is virtual so function overriding could occer
    	virtual double calculatePay() const {
        	return 0.0; // Default implementation
    	}
		
		//function is const as its a type of getter method
    	virtual void displayDetails() const {
        	cout<< "Employee ID: "<<employeeID << ", Name: "<<employeeName;
    	}
};

//derived class
class FullTimeEmployee : public Employee {
	private:
    	double monthlySalary;

	public:
		//parameterized constructor with initalizer list
    	FullTimeEmployee(int id, const string& name, double salary) : Employee(id, name), monthlySalary(salary) {}

		//overriding virtual function in base class
    	double calculatePay() const override {
        	return monthlySalary;
    	}
		//overriden virtual function
    	void displayDetails() const override {
    		//using scope resolution operator to access virtual function
        	Employee::displayDetails();
        	//adding more to the implementation of the previous function
        	cout<<", Type: Full-time, Monthly Salary: "<<monthlySalary << endl;
    	}
};

//derived class 2
class PartTimeEmployee : public Employee {
	private:
    	double hourlyWage;
    	double hoursWorked;
	
	public:
		//parametrized constructor with initializer list
    	PartTimeEmployee(int id, const string& name, double wage, double hours) : Employee(id, name), hourlyWage(wage), hoursWorked(hours) {}

    	double calculatePay() const override {
        	return hourlyWage * hoursWorked;
    	}

    	void displayDetails() const override {
        	Employee::displayDetails();
        	cout<<", Type: Part-time, Hourly Wage: "<< hourlyWage <<", Hours Worked: "<<hoursWorked<<endl;
    	}
};

int main() {
	cout<<"Muhammad Abbas\n23k-0068\n\n"<<endl;
    FullTimeEmployee fullTimeEmp(101, "Ahmed", 5000);
    PartTimeEmployee partTimeEmp(102, "Muhammad", 15, 40);

    cout<<"Displaying Details:"<<endl;
    fullTimeEmp.displayDetails();
    partTimeEmp.displayDetails();

    cout<<"\nCalculating Pay:"<<endl;
    cout<<"Full-time Employee Pay: $" <<fullTimeEmp.calculatePay()<<endl;
    cout<<"Part-time Employee Pay: $" <<partTimeEmp.calculatePay()<<endl;

    //using base class pointer to demonstrate early or static binding by storing derived class address in a base class pointer
    Employee* empPtr = &fullTimeEmp;
    //accessing a method using pointer
    cout<<"\nUsing base class pointer to calculate Full-time Employee Pay: $" << empPtr->calculatePay() << endl;

    return 0;
}
