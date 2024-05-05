/*
 * Name: Muhammad abbas
 * id:23k-0068
 * purpose: program to implement drone functionality with abstract classes and interfaces
 * */

#include <iostream>
#include <cmath>
#include <stdexcept> // Included for exception handling

using namespace std;

//drone abstract base class
class Drone {
protected:
    float latitude;
    float longitude;
    float altitude;
    float speed;

public:
    //constructor
    Drone(float lat, float lon, float alt, float spd)
            : latitude(lat), longitude(lon), altitude(alt), speed(spd) {}

    //virtual function to adjust altitude or height
    virtual void adjustAltitude(float meters) {
        altitude += meters;
    }

    void setSpeed(float spd) {
        speed = spd;
    }
};

//interface for movement in three-dimensional space
class Flyable {
public:
    //all functions are pure virtual functions as this is a interface
    //implementation is done below
    virtual void takeoff() = 0;
    virtual void land() = 0;
    virtual void navigateTo(float latitude, float longitude, float altitude) = 0;
};

//interface for scanning the environment
class Scannable {
public:
    virtual void scanArea(float radius) = 0;
};

//reconnaisance drone class implementing Flyable and Scannable interfaces using inheritance
class ReconDrone : public Drone, public Flyable, public Scannable {
private:
    int cameraResolution;
    int maxFlightTime;

public:
    ReconDrone(float lat, float lon, float alt, float spd, int res, int maxTime)
            : Drone(lat, lon, alt, spd), cameraResolution(res), maxFlightTime(maxTime) {}

    //implementation of the pure virtual functions in the interfaces
    void takeoff() override {
        cout << "ReconDrone taking off." << endl;
    }

    void land() override {
        cout << "ReconDrone landing." << endl;
    }

    void navigateTo(float lat, float lon, float alt) override {
        //try-catch block is used for exceptions
        try {
            //here you would handle potential exceptions such as GPS signal loss or communication errors
            float distance = calculateDistance(latitude, longitude, lat, lon);
            cout<<"the distance is :"<< calculateDistance(latitude, longitude, lat, lon);
            cout<<endl;
            float time = distance / speed;
            cout << "Estimated time to reach destination: " << time << " hours." <<endl;
        } catch (const std::exception& e) {
            std::cerr << "Error during navigation: " << e.what() << std::endl;
        }
    }

    void scanArea(float radius) override {
        try {
            int objectsDetected = rand() % 10; //simulated detecting up to 10 random objects
            cout << "Detected " << objectsDetected << " objects within radius " << radius <<endl;
            // Display the coordinates of detected objects
            for (int i = 0; i < objectsDetected; ++i) {
                float objectLatitude = latitude + (rand() % 10 - 5) / 100.0; // Simulate small changes in latitude
                float objectLongitude = longitude + (rand() % 10 - 5) / 100.0; // Simulate small changes in longitude
                cout << "Object " << i + 1 << " coordinates: (" << objectLatitude << ", " << objectLongitude << ")" <<endl;
            }
        } catch (const std::exception& e) {
            cerr << "Error during scanning: " << e.what() << endl;
        }
    }

    //this function is private as it wll only be used in the function within this class
private:
    float calculateDistance(float lat1, float lon1, float lat2, float lon2) {
        float earthRadius = 6371e3; // Earth radius in meters e is used for exponents
        float phi1 = lat1 * M_PI / 180.0; //converting values from degrees to radians
        float phi2 = lat2 * M_PI / 180.0; //M_PI represents the constant PI from the Cmath library
        //calculates difference in latitude and longitudes and converts it from degrees to radians
        float deltaPhi = (lat2 - lat1) * M_PI / 180.0;
        float deltaLambda = (lon2 - lon1) * M_PI / 180.0;

        //haversine formula used to calculate difference between two points given that you are provided with the latitude and longitude
        float a = sin(deltaPhi / 2) * std::sin(deltaPhi / 2) + cos(phi1) * cos(phi2) * sin(deltaLambda / 2) * std::sin(deltaLambda / 2);
        //calculates angle subtended by the 2 points from the senter of the circle using the arctan function
        float c = 2 * atan2(sqrt(a), sqrt(1 - a));

        return earthRadius * c; //finally returns the distance between the 2 points
    }
};

int main() {
    cout<<"muhammad abbas"<<endl;
    cout<< "23k-0068"<<endl;

    //instantiate a ReconDrone object with random position values
    ReconDrone drone(40.7128, -74.0060, 100, 30, 4, 8);

    //set initial position and altitude
    drone.takeoff();
    cout<<endl;
    drone.navigateTo(37.7749, -122.4194, 150);
    cout<<endl;
    //scan the area
    drone.scanArea(1000);
    cout<<endl;
    // Land the drone
    drone.land();

    return 0;
}
