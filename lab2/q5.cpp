/*
name:Muhammad Abbas
ID:23k-0068
purpose: a product management system with a user interface
*/

#include<iostream>
#include<unistd.h>//header added for sleep() function to pause program

using namespace std;

//global variable to hold the number of items in the main database array
int position=0;

//structure template for each product
struct product{
	int productid;
	string name;
	float price;
	int quantity;
};

//global array of structures as it has to be used outside the main function
product products[100];

//function to add new product records to the array
void addProduct(product products[],int &position) {
	cout<<"add the details of the product you want to add to the database"<<endl;
	cout<<"enter the product ID:"<<endl;
	cin>>products[position].productid;
	cout<<"enter the product name"<<endl;
	cin.ignore();//clearing the input bffer
	getline(cin,products[position].name);
	cout<<"enter the product price"<<endl;
	cin>>products[position].price;
	cout<<"enter the product quantity"<<endl;
	cin>>products[position].quantity;
	cout<<"\nproduct added successfully!"<<endl;
	position++;//incrementing the global variable telling the number of items in the array so next time the next location in the array is used to store the next data
}

//function to find a product from the array
void findProduct(product products[],int productid) {
	for(int i=0;i<position;i++) {
		if(products[i].productid==productid) {
			cout<<"product found"<<endl;
			cout<<"product id is:"<<endl;
			cout<<products[i].productid<<endl;
			cout<<"product name is:"<<endl;
			cout<<products[i].name<<endl;
			cout<<"product price is:"<<endl;
			cout<<products[i].price<<endl;
			cout<<"product quantity is:"<<endl;
			cout<<products[i].quantity<<endl;
		}
	}
	cout<<"no such product found"<<endl;
}

//function to update existing record
void updaterecord(product products[],int productid) {
	for(int i=0;i<position;i++) {
		if(products[i].productid==productid) {
			cout<<"add new product name:"<<endl;
			cin.ignore();//clearing buffer
			getline(cin,products[i].name);
			cout<<"add new product price:"<<endl;
			cin>>products[i].price;
			cout<<"add new product quantity:"<<endl;
			cin>>products[i].quantity;
			cout<<"record updated successfully!"<<endl;
		}
	}
}


int main() {
	int choice;
	//label used to bring back program execution here when required
	again:
	cout<<"\t\t\t\t   welcome to the product management system";
	cout << "\n\n\t\t\t\t********choose from the following options:*******\n\n" << endl;
    cout << "\t\t\t\t|-----------------------------------------------|" << endl;
    cout << "\t\t\t\t|-----------------------------------------------|" << endl;
    cout << "\t\t\t\t|    1)add a product to the database            |" << endl;
    cout << "\t\t\t\t|    2)find a product from the database         |" << endl;
    cout << "\t\t\t\t|    3)update a existing record                 |" << endl;
    cout << "\t\t\t\t|    4)exit                                     |" << endl;
    cout << "\t\t\t\t|-----------------------------------------------|" << endl;
    cout << "\t\t\t\t|-----------------------------------------------|" << endl;
    cout << "enter your choice:" << endl;
    cin >> choice;
    
    //calling the respective functions based on user choice
    switch (choice) {
    	case 1:
    		addProduct(products,position);
    		break;
    		
    	case 2:
    		int productid;
    		cout<<"enter the id of the product you want to find"<<endl;
    		cin>>productid;
    		findProduct(products,productid);
    		break;
    		
    	case 3:
    		int productid2;
    		cout<<"enter the id of the product you want to find"<<endl;
    		cin>>productid2;
    		updaterecord(products,productid2);
    		break;
    		
    	case 4:
    		cout<<"thank you for coming use us again:)"<<endl;
    		exit(0);//function to exit the program
    		break;
    		
        default:
        	cout<<"wrong input program loading again choose again"<<endl;
        	sleep(2);//function to pause the program for required seconds
        	break;
	}
	//goto statement will take program execution to where the mentioned label is
	goto again;
	
}
