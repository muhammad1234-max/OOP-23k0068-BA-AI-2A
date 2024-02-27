/*
Name:Muhammad Abbas
id:23k-0068
purpose: a program of a virtual pet adoption system
*/

#include <iostream>
#include <string>
#include <cstddef> // for NULLptr

using namespace std;

//class of pet
class Pet {
private:
    string name;
    string species;
    string healthStatus;
    int hungerLevel;
    int happinessLevel;
    string specialSkills[5];
    int numSpecialSkills;

public:
	// parametrized constructor with initializer list
    Pet(string n, string sp, string hs = "Healthy", int hl = 5, int hapl = 5) :
            name(n), species(sp), healthStatus(hs), hungerLevel(hl), happinessLevel(hapl), numSpecialSkills(0) {}
    
    //function to display pet details
    void displayPetDetails() {
        cout<<"Pet Name: "<<name<<endl;
        cout<<"Species: "<<species<<endl;
        cout<<"Health Status: "<<healthStatus<<endl;
        cout<<"Hunger Level: "<<hungerLevel<<endl;
        cout<<"Happiness Level: "<<happinessLevel<<endl;
        cout<<"Special Skills: ";
        for(int i=0;i< numSpecialSkills;i++) {
            cout<<specialSkills[i]<<", ";
        }
        cout<<endl;
    }
    
    //getter to access the name
    string getName() const { 
        return name;
    }
    
    //function to add special skills for the pet
    void addSpecialSkill(string skill) {
    	//only 5 skills per pet is possible max
        if (numSpecialSkills < 5) {
            specialSkills[numSpecialSkills++] = skill;
        }
    }

    void updateHappiness(string action) {
    	//updating happiness based on actions
    	//min max function used to implement limits for the values
        if(action=="feed") {
            happinessLevel=min(happinessLevel + 1, 10);
        } else if(action=="play") {
            happinessLevel=max(happinessLevel - 1, 0);
        }
        if(hungerLevel>=8) {
            happinessLevel=max(happinessLevel - 1, 0);
        }
    }

    void updateHealth() {
    	//updating hunger based on user action
        if (hungerLevel >= 8) {
            healthStatus = "Sick";
        } else if (hungerLevel <= 2) {
            healthStatus = "Healthy";
        }
    }
    
    void updateHunger(string action) {
    	//min max functions used to implement limits
        if (action == "feed") {
            hungerLevel = max(hungerLevel - 1, 0);
        } else if (action == "play") {
            hungerLevel = min(hungerLevel + 1, 10);
        }
        if (happinessLevel <= 2) {
            hungerLevel = min(hungerLevel + 1, 10);
        }
    }
};

class Adopter {
    private:
        string adopterName;
        string adopterMobileNum;
        //array of objecs of data-type pet
        Pet *adoptedPetRecords[3];
        int numAdoptedPets;

    public:
	    //parameterized constructor function with initalizer list
        Adopter(string name, string mobileNum) : adopterName(name), adopterMobileNum(mobileNum), numAdoptedPets(0) {}

        void adoptPet(Pet *pet/*passing pointer of array of data type object*/) {
        	//one adopter can oly adopt a max of 3 pets
            if (numAdoptedPets < 3) {
                adoptedPetRecords[numAdoptedPets++] = pet;
            }
        }
        
        //function to enable the adopter to return a pet if they want to 
        void returnPet(Pet *pet) {
            for(int i=0;i<numAdoptedPets;i++) {
                if (adoptedPetRecords[i] == pet) {
                    for (int j=i;j<numAdoptedPets-1;j++) {
                        adoptedPetRecords[j] = adoptedPetRecords[j + 1];
                    }
                    adoptedPetRecords[numAdoptedPets--] = NULL;
                    cout<< /*calling name getter function from its pointer of the object*/ pet->getName() << " has been returned." << endl;
                    return;
                }
            }
        }
    
    //function to display current adopted pets by a adopter
    void displayAdoptedPets() {
        cout<<"Adopted Pets by "<<adopterName<<":"<<endl;
        for(int i=0;i<numAdoptedPets;i++) {
            adoptedPetRecords[i]->displayPetDetails();
        }
    }
};

int main() {
	
	cout<<"CODE BY:\nMuhammad Abbas"<<endl;
	cout<<"23k-0068\n"<<endl;
    //Creating instances or objects of pets and initializing intial values using constructor functions
    Pet pet1("Buddy", "Dog", "Healthy", 5, 5);
    Pet pet2("Whiskers", "Cat", "Healthy", 5, 5);
    Pet pet3("Fluffy", "Rabbit", "Healthy", 5, 5);
    pet1.addSpecialSkill("dancing");
    pet1.addSpecialSkill("somersaults");
    pet1.addSpecialSkill("eating too much");
    pet1.addSpecialSkill("singing");
    
    pet2.addSpecialSkill("fighting");
    pet2.addSpecialSkill("sleeping");
    pet2.addSpecialSkill("eating");
    pet2.addSpecialSkill("whatever");
    
    pet3.addSpecialSkill("jumping");
    pet3.addSpecialSkill("carrots");
    pet3.addSpecialSkill("scratching ears");
    pet3.addSpecialSkill("cant think of a skill so random");
    
    //Creating instances of ouradopters
    Adopter adopter1("Alice", "1234567890");
    Adopter adopter2("Bob", "0987654321");

    //adopting pets by using pointers
    adopter1.adoptPet(&pet1);
    adopter2.adoptPet(&pet2);
    adopter2.adoptPet(&pet3);

    //Simulating some examples of interactions with the pets
    pet1.updateHappiness("feed");
    pet1.updateHealth();
    pet2.updateHunger("play");
    pet2.updateHealth();

    //Displaying adopted pets by each adopter
    adopter1.displayAdoptedPets();
    adopter2.displayAdoptedPets();

    return 0;
}
