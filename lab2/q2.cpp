/*
name: Muhammad Abbas
ID: 23k-0068
purpose: Book database management system
*/

#include <iostream>
#include <string> //header file for string
#include <unistd.h> // header file for sleep function used in the code to pause the program
#include <cstdlib>  // header file for the system() function that we will use to clear the command console

using namespace std;

//a strucutre that defines a book data type
struct book {
    string title;
    string author;
    int publicationyr;
    string genre;
};


int main() {
    int choice, numBooks = 0/*variable that will hold the number of books present in the database*/;

    cout << "\n\n\n\n\t\t\t\t      welcome to the book management system" << endl;
    book books[100];//array of the structure books to hold all the data

    while (true) {
    	//custom menu to show the user all the options and functionalities of the prgram
        cout << "\n\n\t\t\t\t********choose from the following options:*******\n\n" << endl;
        cout << "\t\t\t\t|-----------------------------------------------|" << endl;
        cout << "\t\t\t\t|-----------------------------------------------|" << endl;
        cout << "\t\t\t\t|    1)find a book from the database            |" << endl;
        cout << "\t\t\t\t|    2)add a book to the database               |" << endl;
        cout << "\t\t\t\t|    3)update data of a existing book record    |" << endl;
        cout << "\t\t\t\t|    4)exit                                     |" << endl;
        cout << "\t\t\t\t|-----------------------------------------------|" << endl;
        cout << "\t\t\t\t|-----------------------------------------------|" << endl;
        cout << "enter your choice:" << endl;
        cin >> choice;
        
        //main switch statement that will execute program based on user choice
        switch (choice) {
            //code for updating a already present book record
			case 3: {
                string search2;
                cout << "enter the title of the book that you want to update" << endl;
                cin.ignore();//clearing the input buffer
                getline(cin, search2); //getline() used for string inpt
                  
                for (int i = 0; i < numBooks; i++) {
                    if (books[i].title == search2) {
                        cout << "book found enter new data" << endl;
                        cout << "add new author" << endl;
                        getline(cin, books[i].author);
                        cout << "add new year of publication" << endl;
                        cin >> books[i].publicationyr;
                        cout << "add new genre" << endl;
                        cin.ignore();//clearing the buffer
                        getline(cin, books[i].genre);
                        break;
                    }
                }
                break;
            }
            
            //code for entering new book data in the array
            case 2: {
                cout << "enter data for book " << endl;
                cout << "enter the title:" << endl;
                cin.ignore();//clearing buffer
                getline(cin, books[numBooks].title);
                cout << "enter the author name:" << endl;
                getline(cin, books[numBooks].author);
                cout << "enter the year of publication:" << endl;
                cin >> books[numBooks].publicationyr;
                cout << "enter the genre:" << endl;
                cin.ignore();
                getline(cin, books[numBooks].genre);
                numBooks++; // Increment the number of books after adding a new book
                cout << "Book added successfully!" << endl;
                break;
            }
            
            //code for searching for a book based on title or author
            case 1: {
                int choice2;
                string search;
                while (true) {
                    cout << "will you be searching with the title or author choose from below:" << endl;
                    cout << "1)search by title" << endl;
                    cout << "2)search by author" << endl;
                    cout << "enter your choice:" << endl;
                    cin >> choice2;

                    cout << "enter search value" << endl;
                    cin.ignore(); //cearing the input buffer
                    getline(cin, search);
                    
                    //switch statement that will search based on title or author whatever the user wants
                    switch (choice2) {
                        case 1:
                            for (int i = 0; i < numBooks; i++) {
                                if (books[i].title == search) {
                                    cout << "book found" << endl;
                                    cout << "the title of the book is:" << endl;
                                    cout << books[i].title << endl;
                                    cout << "the author of the book is:" << endl;
                                    cout << books[i].author << endl;
                                    cout << "the year of publication is:" << endl;
                                    cout << books[i].publicationyr << endl;
                                    cout << "the genre of the book is:" << endl;
                                    cout << books[i].genre << endl;
                                    break;
                                }
                            }
                            cout << "no relevant book record found" << endl;
                            break;

                        case 2:
                            for (int i = 0; i < numBooks; i++) {
                                if (books[i].author == search) {
                                    cout << "book found" << endl;
                                    cout << "the title of the book is:" << endl;
                                    cout << books[i].title << endl;
                                    cout << "the author of the book is:" << endl;
                                    cout << books[i].author << endl;
                                    cout << "the year of publication is:" << endl;
                                    cout << books[i].publicationyr << endl;
                                    cout << "the genre of the book is:" << endl;
                                    cout << books[i].genre << endl;
                                    break;
                                }
                            }
                            break;

                        default:
                            cout << "wrong choice enter again" << endl;
                            continue;
                    }
                    break;
                }
                break;
            }
            
            //code to exit the program when the user wants
            case 4:
                cout << "thank you use us again soon:)" << endl;
                exit(0); //exit function

            default:
                cout << "wrong choice, the program will pause for a few seconds then try again" << endl;
                sleep(3); //function to pause the program for 3 secods
                system("cls");//function to clear the command console
                continue; //keyword to continue to next iteration of the loop
        }
    }

    return 0;
}
