/*
name:Muhammad
id:23k-0068
purpose: A program with the class template of a phone and some methods to show fuctionality
*/

#include<iostream>

using namespace std;

class smartphone {
	//private data attributes of the phone
	private:
	    string brand;
	    string model;
	    int display_res;
	    int ram;
	    int rom;
	    int storage;
	    
	public:
		//setter methods
		void set_brand(string abrand) {
			brand=abrand;
		}
		void set_model(string amodel) {
			model=amodel;
		}
		void set_res(int ares) {
			display_res=ares;
		}
		void set_ram(int aram) {
			ram=aram;
		}
		void set_rom(int arom) {
			rom=arom;
		}
		void set_storage(int astorage) {
			storage=astorage;
		}
		
		//getter methods
		string get_brand() {
			return brand;
		}
		string get_model() {
			return model;
		}
		int get_res() {
			return display_res;
		}
		int get_ram() {
			return ram;
		}
		int get_rom() {
			return rom;
		}
		int get_storage() {
			return storage;
		}
		
		//additional functionalty methods
		void call(string cname) {
			cout<<"dialing call to "<<cname<<endl;
		}
		
		void message(string crecp) {
			cout<<"sendig message to "<<crecp<<endl;
		}
		
		void WIFI(string wname) {
			cout<<"connecting to wifi "<<wname<<endl;
		}
		
		void internet(string search) {
			cout<<"browsing the internet for the webpage "<<search<<endl;
		}
		
};

int main() {
	//instance 1 of the class
	smartphone iphone;
	iphone.set_brand("iphone");
	iphone.set_model("13pro");
	iphone.set_res(1024);
	iphone.set_ram(8);
	iphone.set_rom(1000);
	iphone.set_storage(10000);
	cout<<"the data for the phone is the following:\n "<<endl;
	cout<<"the brand of the phone is:"<<endl;
	cout<<iphone.get_brand()<<endl;
	cout<<"the model of the phone is:"<<endl;
	cout<<iphone.get_model()<<endl;
	cout<<"the screen resolution of the phone is:"<<endl;
	cout<<iphone.get_res()<<endl;
	cout<<"the RAM of the phone is:"<<endl;
	cout<<iphone.get_ram()<<endl;
	cout<<"the ROM of the phone is:"<<endl;
	cout<<iphone.get_rom()<<endl;
	cout<<"the storage of the phone is:"<<endl;
	cout<<iphone.get_storage()<<endl;
	iphone.call("muhammad");
	iphone.message("john");
	iphone.WIFI("WITRIBE");
	iphone.internet("youtube");
	
	//instance 2 of the class
	smartphone redmi;
	iphone.set_brand("redmi");
	iphone.set_model("13C");
	iphone.set_res(2048);
	iphone.set_ram(8);
	iphone.set_rom(1200);
	iphone.set_storage(12000);
	cout<<"the data for the phone is the following:\n "<<endl;
	cout<<"the brand of the phone is:"<<endl;
	cout<<iphone.get_brand()<<endl;
	cout<<"the model of the phone is:"<<endl;
	cout<<iphone.get_model()<<endl;
	cout<<"the screen resolution of the phone is:"<<endl;
	cout<<iphone.get_res()<<endl;
	cout<<"the RAM of the phone is:"<<endl;
	cout<<iphone.get_ram()<<endl;
	cout<<"the ROM of the phone is:"<<endl;
	cout<<iphone.get_rom()<<endl;
	cout<<"the storage of the phone is:"<<endl;
	cout<<iphone.get_storage()<<endl;
	iphone.call("ahmed");
	iphone.message("tom");
	iphone.WIFI("PTCL");
	iphone.internet("facebook");
	
}
