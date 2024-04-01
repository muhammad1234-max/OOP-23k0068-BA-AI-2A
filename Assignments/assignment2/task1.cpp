/*
Name: Muhammad Abbas
ID:23k-0068
purpose: program that simulates a antivirus securty system tools with inheritance
*/

#include <iostream>
#include <string>

using namespace std;

// Class representing a generic cybersecurity tool
class SecurityTool {
	protected:
    	string securityLevel;
    	double cost;
    	int numDevices;

	public:
    	//parameterized constructor with intializer list
    	SecurityTool(string alevel, double acost, int adevices) : securityLevel(alevel), cost(acost), numDevices(adevices) {
        	//security level validation 
        	if (securityLevel != "High" && securityLevel != "Medium" && securityLevel != "Low") {
            	cout<<"Invalid security level! Setting security level to error."<<endl;
            	securityLevel ="error";
        	}
        	//validating the cost is not zero or negative
        	if (cost<=0) {
            	cout<<"invalid cost! Setting cost to 1"<<endl;
            	cost=1;
        	}
    	}

    	void performScan() {
        	cout<<"initiating security scan..."<<endl;
    	}
};

//public inheritance with base class Security
class FirewallTool : public SecurityTool {
	private:
		//array of integers storing allowed internet ports
    	int* ports;
    	//array of strings holding allowed commnication protocols
    	string* protocols;

	public:
    	//parameterized constructor which is also invoking base class constructor
    	FirewallTool(string alevel, double acost, int devices, int* aports, string* aprotocols) : SecurityTool(alevel, acost, devices) {
        	//DMA for ports array
        	ports = new int[24];
        	for (int i = 0; i < 24; i++) {
            	ports[i] = aports[i];
        	}
        	//DMA for protocols array
        	protocols = new string[6];
        	for (int i = 0; i < 6; i++) {
            	protocols[i] = aprotocols[i];
        	}
        	//checking the number of devices is not greater than 10
        	if (numDevices>10) {
            	cout<<"number of devices exceeds maximum limit! only allowing 10 devices."<<endl;
            	numDevices=10;
        	}
    	}	

    //destructor
    ~FirewallTool() {
        delete[] ports;
        delete[] protocols;
    }

    //function to generate port list based on student ID
    void generateList(int startPort) {
        //storing ports in the array based on startPort
        for (int i = 0; i <24;i++) {
            ports[i] = startPort + i;
        }
    }

    // Function to perform a firewall scan
    void performScan(int startPort) {
        cout<<"initiating a firewall scan..."<<endl;
        cout<<"Security Level: "<<securityLevel<<endl;
        cout<<"Cost: " <<cost<<endl;
        cout<<"Number of Devices: "<<numDevices<<endl;

        //checking security level and allowing traffic accordingly
        if (securityLevel == "High") {
            cout<<"Allowing traffic from port list and protocol list only."<<endl;
        } else if (securityLevel == "Medium") {
            cout<<"Allowing traffic from port list, protocol list, and next two ports in sequence."<<endl;
            //printing all the extra allowed ports
            for (int i = 0; i<2;i++) {
                cout<<ports[startPort]+i+1<<" ";
            }
            cout<<endl;
        } else { //low security level
            cout << "Allowing traffic from port list, protocol list, and next five ports in sequence, TCP, and DNS protocol." << endl;
            for (int i = 0; i < 5; ++i) {
                cout<<ports[startPort]+i+1<<" ";
            }
            cout<<"TCP, DNS"<<endl;
        }
        cout<<"\n\n"<<endl;
    }
};

int main() {
	cout<<"Muhammad Abbas\n23k-0068\n\n"<<endl;
    //initializing all allowed ports and protocols
    int allowedPorts[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
    string allowedProtocols[] = {"HTTPS", "FTP", "UDP", "ICMP", "SSH", "SNMP"};

    //create a firewall tool objects with all possible scenarios
    FirewallTool firewall1("High", 100.0, 5, allowedPorts, allowedProtocols);
	FirewallTool firewall2("medium", 100.0, 9, allowedPorts, allowedProtocols);
	FirewallTool firewall3("low", 100.0, 6, allowedPorts, allowedProtocols);
	FirewallTool firewall4("low", 100.0, 14, allowedPorts, allowedProtocols);
	cout<<"\n\n"<<endl;
	
	//testing all firewalls
    firewall1.generateList(1);
    firewall1.performScan(1);
    
    firewall2.generateList(2);
    firewall2.performScan(2);
    
    firewall3.generateList(3);
    firewall3.performScan(3);
    
    firewall4.generateList(4);
    firewall4.performScan(4);

    return 0;
}

