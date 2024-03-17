/*
Name: Muhammad Abbas
ID: 23k-0068
purpose: Code to show a sample bank account and how to simulate changing of transaction history
*/

#include<iostream>
#include<cstring>

using namespace std;

class BankAccount {
    private:
        int accountId;
        double balance;
        int* transactionHistory;
        int numTransactions;

    public:
        //parameterized constructor
        BankAccount(int id, double bal, int* transhist, int transnum) {
            accountId=id;
            balance=bal;
            numTransactions=transnum;
            //DMA for the array to store the transacton history
            transactionHistory = new int[numTransactions];
            //copying memory for allocation
            memcpy(transactionHistory, transhist, numTransactions * sizeof(int));
        }

        //copy constructor with initializer list
        BankAccount(const BankAccount& other/*copying one bankaccount object to another*/) : accountId(other.accountId), balance(other.balance), numTransactions(other.numTransactions) {
            //allocate memory for transaction history and copy transactions
            transactionHistory = new int[numTransactions];
            memcpy(transactionHistory, other.transactionHistory, numTransactions * sizeof(int));
        }

        //destructor
        ~BankAccount() {
            delete[] transactionHistory;
        }
       
        //display function for information
        void display() {
            cout<<"Account ID: "<<accountId<<endl;
            cout << "Balance: " <<balance<<endl;
            cout << "Transaction History: ";
            for (int i = 0; i<numTransactions;i++){
                cout<<transactionHistory[i]<<" ";
            }
            cout<<endl;
        }
        
		//function to add trasaction data to the tansaction history array
        void updateTransactionHistory(int* transactions, int numTrans) {
            //deallocate existing transaction history
            delete[] transactionHistory;
       
           //allocate memory for new transaction history and copy transactions
           numTransactions = numTrans;
           transactionHistory = new int[numTransactions];
           memcpy(transactionHistory, transactions, numTransactions * sizeof(int));
        }
};

int main() {
    cout<<"Muhammad Abbas\n23k-0068\n\n"<<endl;
	int transactions1[] = {600, -500, 700}; //sample transaction history
    //to find number of data elements in the array (size of whole array / size of one data item in the array)
	int numTrans1 = sizeof(transactions1) / sizeof(transactions1[0]);

    //sample bank account
    BankAccount account1(033222, 1000.0, transactions1, numTrans1);

    //creating a copy of the original account
    BankAccount account2 = account1;

    //displaying the account details of both the original and copied accounts
    cout<<"Original Account:"<<endl;
    account1.display();
    cout<<endl;

    cout<<"Copied Account:"<<endl;
    account2.display();
    cout<<endl;

    //chage the transaction history of the original account
    int newTrans[] = {-200, 300};
    //finding num of data items in the array
    int numNewTrans = sizeof(newTrans) / sizeof(newTrans[0]);
    account1.updateTransactionHistory(newTrans, numNewTrans);

    //showing the details of the original account after updating transaction history
    cout<<"original Account after changing transaction history:"<<endl;
    account1.display();
    cout<<endl;

    return 0;
}
