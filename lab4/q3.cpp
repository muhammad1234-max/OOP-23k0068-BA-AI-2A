/*
Name:Muhammad Abbas
ID:23k-0068
purpose: a program to find out next day or previous day or the nth day
*/

#include <iostream>
#include <string>

using namespace std;

class weekDays {
private:
    string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int currentDay;

public:
    // Default constructor
    weekDays() {
        currentDay = 0; //starting current day is sunday
    }

    // Parameterized constructor
    weekDays(int acurrentday) {
        if (acurrentday > 6) {
            currentDay = acurrentday % 7;
        } else {
            currentDay = acurrentday;
        }
    }

    string getCurrentDay() {
        return days[currentDay];
    }

    string getNextDay() {
        return days[(currentDay + 1) % 7]; // Ensure index remains within bounds
    }

    string getPreviousDay() {
        return days[(currentDay + 6) % 7]; 
    }

    string getNthDayFromToday(int n) {
        return days[(currentDay + n) % 7];
    }
};

int main() {
    int n;
    weekDays week;

    cout << "Current Day: " << week.getCurrentDay() << endl;
    cout << "Next Day: " << week.getNextDay() << endl;
    cout << "Previous Day: " << week.getPreviousDay() << endl;
    cout << "Enter the value of n to find the Nth day from today: " << endl;
    cin >> n;
    cout << "Nth Day from Today: " << week.getNthDayFromToday(n) << endl;

    return 0;
}
