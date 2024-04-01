/*
Name: Muhammad Abbas
id:23k-0068
purpose: code to represent a gaming hierarchy using inheritance between multiple classes
*/

#include <iostream>

using namespace std;

//base class 1
class Player {
	public:
		int playerID;
		string playerName;
		int health;
		
	public:
		Player(int id, string name) {
			playerID=id;
			playerName=name;
			health=100;
		}
		//extra function created to reduce the health each time the character or the enemy attacks and this will be inherited by both
		void cause_damage() {
			health=health-5;
		}
	
};

//base class 2
class Weapon {
	public:
		string* weaponsList;
		int count;
	
	public:
		
		Weapon(string weapons[], int acount) : count(acount) {
        	//DMA for the array based on the count
        	weaponsList = new string[count];
			if (count<5) {
				cout<<"number of weapons less then the allowed limit add more"<<endl;
			} else {
				for (int i = 0; i < count;i++) {
            		weaponsList[i] = weapons[i];
        		}	
			}
    	}
    	
        //function is const as it is a type of getter function and no data needs to be changed
        void use() const {
        	//displaying all available weapon options
        	cout<<"Available arsenal:"<<endl;
        	for(int i = 0;i<7;i++) {
            	cout<<i + 1<<". "<<weaponsList[i]<<endl;
        	}
        	
        	int choice;
        	cout<<"Choose a weapon (1-7): ";
        	cin>>choice;
        	
        	if (choice >= 1 && choice <= 7) {
            	cout<<"Using weapon: "<<weaponsList[choice - 1]<<endl;
        	} else {
            	cout<<"Invalid choice!"<<endl;
        	}
    	}
    	
    
};

//derived class 1 with multiple inheritance
class Character:public Player, public Weapon {
	private:
		int level;
		string experience;
		int points;
		
	public:
		//default constructor
//		Character() {
//			level=0;
//			experience="begginer";
//			points=0;
//		}
		
		//parameterized constructor with base class constructors invoked as well
		Character(int ID,string aname,string* weapons,int acount,int alevel, string aexp, int apoints) : Player(ID,aname), Weapon(weapons,acount){
			level=alevel;
			experience=aexp;
			points=apoints;
		}
	    
	    //method that will level up the character based on points
		void levelUp() {
    		points += 10;
    		if (points >= 10) {
        		level++;
        		// Update experience based on the current level
        		if (level == 1) {
            		experience = "Intermediate";
        		} else if (level == 2) {
            		experience = "Advanced";
        		} else if (level == 3) {
            		experience = "Expert";
        		}
        		// Reset points for the next level
        		points = 0;
    		}
		}

    	
    	void playGame() {
    		use();
        	cout << "player is attacking the enemy!" << endl;
        	cout << "Enemy's health decreases by 5." << endl;
        	points += 10; 
        	cause_damage();
    	}
    	
    	
    	//display function is a getter so it is set to const
    	void display() const {
    		cout<<"Player ID: "<<playerID<<endl;
        	cout<<"Player Name: "<<playerName<<endl;
        	cout<<"Health: "<<health<<endl;
        	cout<<"Level: "<<level<<endl;
        	cout<<"Experience: "<<experience<<endl;
        	cout<< "Points: "<<points<<endl;
    	}
};

//derived class 2 with multiple inheritance
class Enemy: public Player, public Weapon {
	private:
		int damage;
		
	public:
		//parameterized constructor with base class constructors invoked as well
		Enemy(int ID,string aname,string* weapons,int acount,int adamage) : Player(ID,aname), Weapon(weapons, acount){
			//validation and then value allocation
			if (adamage>=1 && adamage<=10) {
				damage=adamage;
			}
		}
		
		//method to simulate enemy attack
		void attack() {
			use();
			cause_damage();
        	cout<<"enemy is attacking the character!"<<endl;
        	cout << "Character's health decreases by: "<<damage<<endl;
    	}
    	//display function for enemy stats
    	void display() const {
    		cout<<"enemy ID: "<<playerID<<endl;
        	cout<<"enemy Name: "<<playerName<<endl;
        	cout<<"Health: "<<health<<endl;
    	}
		
};

int main() {
	cout<<"Muhammad Abbas\n23k-0068\n\n"<<endl;
	
	string weapons[7] = {"Sword", "Axe", "Bow", "Dagger", "Staff", "Hammer", "Crossbow"};
    int size;
    size= sizeof(weapons)/sizeof(weapons[0]);
    // Create a character
    Character character(407,"James Bond", weapons,size,0,"begginer",0);

    // Create an enemy
    Enemy enemy(408,"Moriarity", weapons,size,5);

    // Simulate gaming environment
       
    cout<<"Character details:"<<endl;
    character.display();
    cout<<"Enemy details:"<<endl;
    cout<<"Damage: "<<5<<endl;
    cout<<endl;

    //character plays the game and levels up all the 3 levels
    character.playGame();
    cout<<"\n\n";
    enemy.display();
    cout<<"\n\n";
    
    //enemy attacks
    enemy.attack();
    cout<<endl;
    
    //levellng up character from begginer to intermediate
    character.levelUp();
    character.display();
    cout<<endl;
    //levellng up character from intermediate to advanced
    character.levelUp();
    character.display();
    cout<<endl;
    //levellng up character from advanced to expert
    character.levelUp();
    character.display();
	cout<<endl;
	
	//displaying enemy stats after it took damage from the character
	enemy.display();

    return 0;
}
