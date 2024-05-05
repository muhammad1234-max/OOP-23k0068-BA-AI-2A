#include <iostream>
#include <string>

using namespace std;

//base class Medicine
class Medicine {
protected:
    string name;
    string formula;
    float retailPrice;
    string manufactureDate;
    string expirationDate;

public:
    //parameterized costructor with initializer list
    Medicine(const string& n, const string& f, float rp, const string& mfgDate, const string& expDate)
            : name(n), formula(f), retailPrice(rp), manufactureDate(mfgDate), expirationDate(expDate) {}

    //getter setters getters are const functions so during data fetching data doesnt change
    // string parameters of setter functions are const again to ensure no data change
    string getName() const {
        return name;
    }
    void setName(const string& n) {
        name = n;
    }
    string getFormula() const {
        return formula;
    }
    void setFormula(const string& f) {
        formula = f;
    }
    float getRetailPrice() const {
        return retailPrice;
    }
    void setRetailPrice(float rp) {
        retailPrice = rp;
    }
    string getManufactureDate() const {
        return manufactureDate;
    }
    void setManufactureDate(const string& mfgDate) {
        manufactureDate = mfgDate;
    }
    string getExpirationDate() const {
        return expirationDate;
    }
    void setExpirationDate(const string& expDate) {
        expirationDate = expDate;
    }

    //virtual pure function to print medicine details
    virtual void printDetails() const = 0;
    //operator overloading
    bool operator==(const Medicine& med) const {
        return getExpirationDate() == med.getExpirationDate();
    }

};

//derived class 1
class Tablet : public Medicine {
private:
    float sucrose;

public:
    //parametrized constructor with initializer ist an the constructor of the base class as well
    Tablet(const string& n, const string& f, float rp, const string& mfgDate, const string& expDate, float sl)
            : Medicine(n, f, rp, mfgDate, expDate) {
        if(sl>=0 && sl<= 1) {
            sucrose=sl;
        } else {
            cout<<"invalid sucrose levels must be between 0 and 1" <<endl;
        }
    }

    //overridden the pure virtual function to print tablet details
    void printDetails() const override {
        cout << "Tablet Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Formula: " << formula << endl;
        cout << "Retail Price: " << retailPrice << endl;
        cout << "Manufacture Date: " << manufactureDate << endl;
        cout << "Expiration Date: " << expirationDate << endl;
        cout << "Sucrose Level: " << sucrose << endl;
    }
};

// Derived class 2
class Capsule : public Medicine {
private:
    float absorptionPercentage;

public:
    Capsule(const string& n, const string& f, float rp, const string& mfgDate, const string& expDate, float ap)
            : Medicine(n, f, rp, mfgDate, expDate) {
        if(ap>=0 && ap<=100) {
            absorptionPercentage=ap;
        } else {
            cout<<"invalid value entered" <<endl;
        }
    }

    //overridden function
    void printDetails() const override {
        cout << "Capsule Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Formula: " << formula << endl;
        cout << "Retail Price: " << retailPrice << endl;
        cout << "Manufacture Date: " << manufactureDate << endl;
        cout << "Expiration Date: " << expirationDate << endl;
        cout << "Absorption Percentage: " << absorptionPercentage << endl;
    }
};

//derived class 3
class Syrup : public Medicine {
public:
    //parameterized constructor with initializer lit
    Syrup(const string& n, const string& f, float rp, const string& mfgDate, const string& expDate)
            : Medicine(n, f, rp, mfgDate, expDate) {}

    //overridden function
    void printDetails() const override {
        cout << "Syrup Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Formula: " << formula << endl;
        cout << "Retail Price: " << retailPrice << endl;
        cout << "Manufacture Date: " << manufactureDate << endl;
        cout << "Expiration Date: " << expirationDate << endl;
    }
};

//pharmacist
class Pharmacist {
public:
    //function to search medicines based on the formula
    void searchMedicine(Medicine* med, const string& searchFormula) const {
        cout << "Searching for medicine with formula: " << searchFormula << endl;
        if (med->getFormula() == searchFormula) {
            cout << "Medicine found: " << med->getName() << endl;
            med->printDetails();
        } else {
            cout << "Medicine with formula " << searchFormula << " not found." << endl;
        }
    }
};

// Counter class
class Counter {
private:
    float revenue;

public:
    //initial value of revenue is zero as it is a sum variable
    Counter() : revenue(0) {}
    //method overloading
    //search medicine based on name
    void searchMedicine(Medicine* med, const string& searchName) const {
        cout << "Searching for medicine with name: " << searchName << endl;
        if (med->getName() == searchName) {
            cout << "Medicine found: " << med->getName() << endl;
            med->printDetails();
        } else {
            cout << "Medicine with name " << searchName << " not found." << endl;
        }
    }

    void updateRevenue(float amount) {
        revenue += amount;
        cout << "Revenue updated: " << revenue << endl;
    }
};

int main() {
    cout<<"Muhammad Abbas"<<endl;
    cout<<"23k-0068"<<endl;
    Pharmacist pharmacist;
    Counter counter;

    //creating some medicine objects and allocating them memory
    Medicine* aspirin = new Tablet("Aspirin", "C9H8O4", 10.5f, "2022-01-01", "2023-01-01", 0.2f);
    Medicine* paracetamol = new Capsule("Paracetamol", "C8H9NO2", 8.75f, "2022-02-01", "2023-02-01", 50.0f);
    Medicine* panadol = new Syrup("panadol", "P6H12O6", 15.25f, "2022-03-01", "2023-03-01");

    //search for medicine by formula
    //will give wrong answer as formula for paracetamol is used
    cout<<endl;
    pharmacist.searchMedicine(aspirin, "C8H9NO2");
    cout<<endl;
    pharmacist.searchMedicine(paracetamol, "C8H9NO2");

    //search for medicine by name
    cout<<endl;
    counter.searchMedicine(aspirin, "Aspirin");

    // Update revenue
    cout<<endl;
    counter.updateRevenue(25.5f);
    cout<<endl;
    //using overloaded operator to compare the expiration dates
    if (aspirin == paracetamol) {
        cout << "Both medicines have the same expiration dates." << endl;
    } else {
        cout << "The expiration dates of the medicines are different." << endl;
    }

    //delete dynamic memory
    delete aspirin;
    delete paracetamol;
    delete panadol;

    return 0;
}
