#include <iostream>

using namespace std;


int maxArea(int height[], int n) {
    //variable to store the maximum area you are finding 
	int maxWater = 0;
    
    //nested loops using a 2-pointer approach to find the best possible combination of base and height to find the target area
    for (int left = 0; left < n - 1; left++) {
        for (int right = left + 1/*as second loop will run after the first loops value*/; right < n; right++) {
            //min function to find smallest value
			int h = min(height[left], height[right]);
			//calculating the best width
            int w = right - left;
            //max function to find biigest value
            maxWater = max(maxWater, h * w);
        }
    }

    return maxWater;
}

int main() {
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    //calculating the number of elements in thhe array by dividing total number of bytes in the array by number of bytes of one element in the array
    int n = sizeof(height) / sizeof(height[0]);
    
    //calling function
    int result = maxArea(height, n);

    cout << "Output: " << result <<endl;

    return 0;
}

