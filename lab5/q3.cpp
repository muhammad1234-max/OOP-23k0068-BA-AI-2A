/*
Name: Muhammad Abbas
id: 23k-0068
purpose: to validate a string if it only has alphabets or not
*/

#include <iostream>
#include <string>

class ValidateString {
    private:
        string str;

    public:
    	//parametrized constuctor with initializer list
        ValidateString(const string &s) : str(s) {}

       //a constant function to check the string.the function is made constant so that the value it gives doesnt change
        bool isValid() const {
            for(char c : str) {
            	//using ASCII values to check of entered data is alphabet or not
                if (!(c >= 'A' && c <= 'Z') && !(c >= 'a' && c <= 'z')) {
                    return false;
                }
            }
            return true;
        }
};

int main() {
    
	ValidateString str1("helloeveryone");
    ValidateString str2("9876");
    ValidateString str3("blahblah123");

    //checking if the strings are valid using ternary operators
    cout<<"String 1 is "<< (str1.isValid() ? "valid" : "invalid")<<endl;
    cout<<"String 2 is "<< (str2.isValid() ? "valid" : "invalid")<<endl;
    cout<<"String 3 is "<< (str3.isValid() ? "valid" : "invalid")<<endl;

    return 0;
}
