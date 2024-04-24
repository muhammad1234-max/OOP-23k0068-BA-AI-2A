/*
Name: Muhammad Abbas
ID:23k-0068
purpose: using friend functions to change private data members in different functions
*/
#include <iostream>
#include <string>

using namespace std;

// class prototyping
class Logo;

// class to represent the social media platform
class Platform
{
private:
    string name;

public:
    // parameterized constructor with initalizer list
    Platform(string platformName) : name(platformName) {}
    void display(const Logo &logo) const;
};

class Server
{
private:
    string ipAddress;

public:
    // parameterized constructor with initalizer list
    Server(string serverIpAddress) : ipAddress(serverIpAddress) {}
    void display(const Logo &logo) const;
};

// class definition of above prototyped class
class Logo
{
private:
    string image;

public:
    // parameterized constructor with initalizer list
    Logo(string logoImage) : image(logoImage) {}
    // friend functions prototyping
    friend void changeLogo(Logo &logo, const string &newImage);
    friend void Platform::display(const Logo &logo) const;
    friend void Server::display(const Logo &logo) const;
};

// friend function definitions
void changeLogo(Logo &logo, const string &newImage)
{
    logo.image = newImage;
}

void Platform::display(const Logo &logo) const
{
    cout << "Platform: " << name << endl;
    cout << "Logo: " << logo.image << endl;
}

void Server::display(const Logo &logo) const
{
    cout << "Server IP Address: " << ipAddress << endl;
    cout << "Logo: " << logo.image << endl;
}

int main()
{
    // original logo
    Logo originalLogo("Blue Bird");

    // Creating instances of Platform and Server
    Platform twitter("Twitter");
    Server server("127.9.8.1");

    // Display original logo
    cout << "Original Logo:" << endl;
    twitter.display(originalLogo);
    server.display(originalLogo);
    cout << endl;

    // Change logo to Doge Coin
    changeLogo(originalLogo, "Doge Coin");

    // Display modified logo
    cout << "Modified Logo:" << endl;
    twitter.display(originalLogo);
    server.display(originalLogo);

    return 0;
}
