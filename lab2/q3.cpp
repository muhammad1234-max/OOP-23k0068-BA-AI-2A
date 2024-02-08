/*
name: Muhammad Abbas
ID: 23k-0068
purpose: to find a subset of values from a array whose sum gives us a target value and to achieve this recursively
*/

#include<iostream>

using namespace std;

bool hasSubsetSum(int arr[], int size, int targetSum) {
	
	if (targetSum == 0) {
        return true;  // Subset with sum 0 always exists (empty subset)
    }
    
    if (size == 0) {
        return false;  // No numbers left to check
    }

    // If the last element is greater than the target sum, it wont be included in the subset as 2 numbers are needed
    if (arr[size - 1] /*last element index*/> targetSum) {
        //recursive case
		return hasSubsetSum(arr, size - 1, targetSum);
    }

    // if neither of the above conditions are true then the recursive condition checks if either including the last element or excluding it gives the target sum
    return hasSubsetSum(arr, size - 1, targetSum) || hasSubsetSum(arr, size - 1, targetSum - arr[size - 1]);
}



int main() {
	int n,target,i;
	cout<<"enter the size of the integer array"<<endl;
	cin>>n;
	int numeric[n];
	
	cout<<"enter the target sum"<<endl;
	cin>>target;
	
	for(i=0;i<n;i++) {
		cout<<"enter value "<<i+1<<endl;
		cin>>numeric[i];
	}
	
	if (hasSubsetSum(numeric, n, target) ) {
        cout << "Subset with sum " << target << " exists." << endl;
    } else {
        cout << "subset with sum " << target << " does NOT exists." << endl;
    }
	
	return 0;
}
