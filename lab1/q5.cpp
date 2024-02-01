#include<iostream>
#include<string>

using namespace std;

//structure to store events data
struct Events{
	string name;
	string date;
	string venue;
	string organizer;
};

//function to enter event detail
void inputEventDetails(Events& event) {
    cout << "Event Name: ";
    cin.ignore(); // Ignore newline left in the buffer
    getline(cin, event.name);
    cout << "Date: ";
    getline(cin, event.date);
    cout << "Venue: ";
    getline(cin, event.venue);
    cout << "Organizer: ";
    getline(cin, event.organizer);
}

//function to display all events
void displayAllEvents(const Events* events, int totalEvents) {
    cout << "\nAll Events:" << endl;
    
    for (int i = 0; i < totalEvents; ++i) {
        cout << "\nEvent " << i + 1 << " details:" << endl;
        cout << "Event Name: " << events[i].name << endl;
        cout << "Date: " << events[i].date << endl;
        cout << "Venue: " << events[i].venue << endl;
        cout << "Organizer: " << events[i].organizer << endl;
    }
}

//function to search events by date
void searchEventsByDate(const Events* events, int totalEvents, const string& searchDate) {
    
	bool found = false;

    cout << "\nEvents on " << searchDate << ":" << endl;

    for (int i = 0; i < totalEvents; ++i) {
        if (events[i].date == searchDate) {
            // Display event details
            cout << "Event Name: " << events[i].name << endl;
            cout << "Date: " << events[i].date << endl;
            cout << "Venue: " << events[i].venue << endl;
            cout << "Organizer: " << events[i].organizer << endl << endl;

            found = true;
        }
    }

    if (!found) {
        cout << "No events found on the specified date." << endl << endl;
    }
}


int main() {
    int totalEvents;

    // Prompt the user to input the total number of events
    cout << "Enter the total number of events to manage: ";
    cin >> totalEvents;

    // Dynamically allocate memory to store event details
    Events* events = new Events[totalEvents];

    // Input event details for each event
    for (int i = 0; i < totalEvents; ++i) {
        cout << "\nEnter details for Event " << i + 1 << ":" << endl;
        inputEventDetails(events[i]);
    }

    // Display all events
    displayAllEvents(events, totalEvents);

    // Search events based on a specific date
    string searchDate;
    cout << "\nEnter the date to search events: ";

    getline(cin, searchDate);

    searchEventsByDate(events, totalEvents, searchDate);

    // Deallocate dynamically allocated memory
    delete[] events;

    return 0;
}
