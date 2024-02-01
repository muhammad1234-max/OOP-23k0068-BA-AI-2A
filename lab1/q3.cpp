#include<iostream>

//importing the standard namespace
using namespace std;

int main() {
	
	int n,target,i,j;
	
	//entering the size of the array
	cout<<"enter the size of the number options array:";
	cin>>n;
	
	//declaring the options array
	int number[n];
	
	//populating the number variable
	for(i=0;i<n;i++) {
		cout<<"enter the "<<i+1<<" value:"<<endl;
		cin>>number[i];
		cout<<"\n"<<endl;
	}
	
	//the target sum that has to be found out
	cout<<"enter the target number that you want to find out: ";
	cin>>target;
	
	//nested for loops being used to find the index of the values in the numbers array that make up the target sum
	for(i=0;i<n;i++) {
		for(j=i+1;j<n;j++) {
			if(number[i]+number[j]==target) {
				cout<<"the first number is "<<i<<endl;
				cout<<"the second number is "<<j<<endl;
				return 0;			
			}
		}
	}
	
}
