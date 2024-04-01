/*
Name: Muhammad Abbas
id: 23k-0068
purpose: program to simulate a social media app using inheritance
*/

#include<iostream>
#include <cstdlib>

//#include <bcrypt/BCrypt.hpp>

using namespace std;

//base class 1
class User {
	private:
		string username;
		string email;
		string password;
	
	public:
		//parameterized constructor
		User(string auser, string aemail, string pass ) {
			username=auser;
			email=aemail;
			password=pass;
		}
		
		//function to encrypt the password
		string encrypt(string apass) {
			string encryptedPassword = password;
			//perform ASCII value manipulation for encryption
    		for (char& c : encryptedPassword) {
        		abs((c+10)/2);
    		}
			return encryptedPassword;
		}	
		
		bool verify(string auser, string apass) {
			if(username==auser) {
				if(password==apass) {
					return true;
				} else {
					cout<<"wrong password entered"<<endl;
					return false;
				}
			} else {
				cout<<"wrong username entered"<<endl;
				return false;
			}
		}
		
};

class Post {
	private:
		int postid;
		string content;
		string comments[5];
		int comcount;
		int likes;
		int views;
		
	public:
		//parameterzd constructor with initial values
		Post(int id, string cont) {
			postid=id;
			content=cont;
			likes=0;
			views=0;
			comcount=0;
		}
		
		void viewPost() {
			views++;
		}
		
		void likePost() {
			likes++;
		}
		
		void addComments(string comment) {
			if(comcount<5) {
				comments[comcount+1]=comment;
			} else {
				cout<<"No more comments can be added"<<endl;
			}
		}
		
		int getLikes() const {
        	return likes;
    	}
    	
    	int getNumComments() const {
        	return comcount;
    	}
    	
    	int getViews() const {
        	return views;
    	}
    	
    	void setlikes(int alikes) {
    		likes=alikes;
		}
		
		void setViews(int aviews) {
			views=aviews;
		}
		
		void display() {
        	cout<<"Post ID: "<<postid<<endl;
        	cout<<"Content: "<<content<<endl;
        	cout<<"Likes: "<<likes<<endl;
        	cout<<"Views: "<<views<<endl;
        	cout<<"Comments: "<<endl;
        	for (int i = 0; i < comcount; i++) {
            	cout<<"comment#: "<<i+1<<" - "<<comments[i]<<endl;
        	}
    	}
};


class RegularUser: public User {
	public:
		//max number of posts a regular user can see
		static const int max_feed_size=5;
		//array to store whole posts feed
		Post* posts[max_feed_size];
		//number of posts currently on the feed
		int feed_count;
		
	public:
		//parameterized constructor which is also invoking the base class constructor as well
		RegularUser(string auser, string em, string apass): User(auser,em,apass) {
			//initial posts on the users feed will be zero
			feed_count=0;
		}
		
		//method to add new posts
		void addToFeed(Post* post) {
        	if (feed_count < max_feed_size) {
            	posts[feed_count+1] = post;
        	} else {
            	cout<<"Post limit reached cant add any more."<<endl;
        	}
    	}
        
        //viewing the whole feed method
    	void viewFeed() {
        	cout<<"----- User Feed -----" <<endl;
        	for (int i = 0; i < feed_count;i++) {
            	posts[i]->display();
            	cout<<"---------------------"<<endl;
        	}
    	}

    	//method to interact (like or comment) with the post
    	void interact(Post* post, string comment) {
        	post->likePost();
        	post->addComments(comment);
    	}
    	
//    	int accessLikes() const {
//        	return getLikes();
//    	}
//    	
//    	int accessComments() const {
//        	return getNumComments();
//    	}
//    	
//    	int accessViews() const {
//        	return getViews();
//    	}
    	
//    	void doublesetlikes(int alikes) {
//    		setlikes(alikes);
//		}
//		
//		void doublesetViews(int aviews) {
//			setViews(aviews);
//		}
    			
};

class BusinessUser: public RegularUser {
	private:
		//max number of posts that can recieved a promotion boost
		static const int max_promoted_posts=5;
		//number of posts that have already been promoted
		int prom_count;
		
	public:
		//parameterized constructor which is also invoking the baseclass constructor
		BusinessUser(string user, string em, string apass) : RegularUser(user,em,apass) {
			prom_count=0;
		}
		
		//since this method is in this class only business user objects can use it
		void promotePost(Post* post) {
        	if (prom_count <max_promoted_posts) {
            	//doubled the num of likes
            	post->setlikes(post->getLikes()*2);
            	//tripled the number of views
            	post->setViews(post->getViews()*3);
            	prom_count++;
            	cout<<"Post promoted successfully."<<endl;
        	} else {
            	cout <<"Maximum promoted posts limit reached. Cannot promote more posts." <<endl;
        	}
    	}
    	
    	void analytics() {
    		for(int i =0; i<feed_count;i++) {
    			cout<<"Post#:"<<i+1<<endl;
    			posts[i]->display();
			}
		}
			
};

int main() {
    // Create regular user and business user objects
    RegularUser regularUser("Muhammad", "abbasmohammad812@gmail.com", "password123");
    BusinessUser businessUser("MyBusiness", "business@example.com", "businesspass");

    // Create some posts
    Post post1(1, "Hello, world!");
    Post post2(2, "This is a great day!");
    Post post3(3, "Check out our new product!");

    // Add posts to regular user's feed
    regularUser.addToFeed(&post1);
    regularUser.addToFeed(&post2);

    // View regular user's feed
    cout << "----- Regular User Feed -----" << endl;
    regularUser.viewFeed();

    // Interact with posts in regular user's feed
    regularUser.interact(&post1, "Great post!");
    regularUser.interact(&post2, "Nice pic!");

    // View regular user's feed after interaction
    cout << "----- Regular User Feed After Interaction -----" << endl;
    regularUser.viewFeed();

    // Promote a post for business user
    businessUser.promotePost(&post3);

    // Display analytics for business user
    cout << "----- Business User Analytics -----" << endl;
    businessUser.analytics();

    return 0;
}
