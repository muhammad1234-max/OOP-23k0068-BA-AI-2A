/*
Name: Muhammad Abbas
id: 23k=0068
purpose: code to calclate loan payments based on interest rate
*/

#include<iostream>

using namespace std;

class Loanhelper{
	private:
	    const float rate;
	    float amount;
	    int timeMonths;
	
	public:
		//parameterized constructor with initializer list
		Loanhelper(float arate, float aamount, int atimeMonths) : rate(arate), amount(aamount), timeMonths(atimeMonths) {}
		
		void calculateMonthlyPayment() {
        //calculate monthly payment
        float monthlyPayment = amount / timeMonths;
        float monthlyInterest = monthlyPayment * rate;

        //adding interest to payments
        monthlyPayment = monthlyPayment+monthlyInterest;

        cout << "You have to pay " << monthlyPayment << " every month for " << timeMonths << " months to repay your loan" << endl;
        }
};

int main() {
	Loanhelper loan(0.07, 10000.0, 8);

    // Calculate and display monthly payment
    loan.calculateMonthlyPayment();
    return 0;
}
