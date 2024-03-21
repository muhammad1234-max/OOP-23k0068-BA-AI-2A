/*
Name: Muhammad Abbas
ID:23K-0068
Purpose: code to show hierarchical inheritance between game characters
*/

#include <iostream>
#include <string>

using namespace std;

//Base class 
class Character {
	protected:
    	int health;
    	int damage;

	public:
    	// Constructor with intializer list
    	Character(int ahealth, int adamage) : health(ahealth), damage(adamage) {}

    //display function
    void display() const {
        cout<<"Health: "<<health<<endl;
        cout<<"Damage: "<<damage<<endl;
    }
};

//sub-class 1
class Enemy : public Character {
	public:
    	//constructor with initializer list
    	Enemy(int ahealth, int adamage) : Character(ahealth, adamage) {}

    //function overloading
    void display() const {
        //calling existing implementatiom
        Character::display();
        //adding extra implementation
        cout<<"Type: Enemy"<<endl;
    }
};

//sub-class 2
class Player : public Character {
	public:
    	//constructor with initializer list
    	Player(int ahealth, int adamage) : Character(ahealth, adamage) {}

    	//function overriding
    	void display() const {
        	Character::display();
        	//extra implementation
        	cout<<"Type: Player"<<endl;
    	}
};

//sub class of player
class Wizard : public Player {
	private:
    	int magicPower;
    	string spells;

	public:
    	//constructor with intializer list
    	Wizard(int ahealth, int adamage, int amagicPower, string aspells) : Player(ahealth, adamage), magicPower(amagicPower), spells(aspells) {}

    
    	void display() const {
        	Player::display();
        	cout<< "Magic Power: "<<magicPower<<endl;
        	cout<<"Spells: "<<spells<<endl;
    	}
};

int main() {
	cout<<"Muhammad Abbas\n23k-0068\n"<<endl;
    //instance of an object of Wizard class
    Wizard wizard(100, 20, 50, "lightning strike, healing spell;");

    //display details of the wizard
    cout<<"Wizard Details:"<<endl;
    wizard.display();

    return 0;
}
