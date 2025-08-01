#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to hold flight details
struct Flight {
    int flightID;          // Unique identifier for the flight
    string destination;    // Destination of the flight
    string departure;      // Departure location of the flight
    float price;           // Price of the flight
};

// Structure to hold passenger details
struct Passenger {
    int passengerID;       // Unique identifier for the passenger
    string name;           // Name of the passenger
    string email;          // Email of the passenger
};

// Structure to hold booking details
struct Booking {
    int bookingID;         // Unique identifier for the booking
    int flightID;          // ID of the booked flight
    int passengerID;       // ID of the passenger who booked the flight
};

// Class to manage the Flight Booking System
class FlightBookingSystem {
private:
    vector<Flight> flights;       // Vector to store flights
    vector<Passenger> passengers; // Vector to store passengers
    vector<Booking> bookings;     // Vector to store bookings
    int flightCounter = 1;        // Counter for flight IDs
    int passengerCounter = 1;     // Counter for passenger IDs
    int bookingCounter = 1;       // Counter for booking IDs

public:
    // Function to add a flight
    void addFlight(string destination, string departure, float price) {
        Flight flight = {flightCounter++, destination, departure, price};
        flights.push_back(flight);
        cout << "Flight added successfully!" << endl;
    }

    // Function to display all flights
    void displayFlights() {
        cout << "Available Flights:" << endl;
        for (const auto & flight : flights) {
            cout << "Flight ID: " << flight.flightID 
                 << ", Destination: " << flight.destination 
                 << ", Departure: " << flight.departure 
                 << ", Price: $" << flight.price << endl;
        }
    }

    // Function to add a passenger
    void addPassenger(string name, string email) {
        Passenger passenger = {passengerCounter++, name, email};
        passengers.push_back(passenger);
        cout << "Passenger added successfully!" << endl;
    }

    // Function to display all passengers
    void displayPassengers() {
        cout << "Registered Passengers:" << endl;
        for (const auto& passenger : passengers) {
            cout << "Passenger ID: " << passenger.passengerID 
                 << ", Name: " << passenger.name 
                 << ", Email: " << passenger.email << endl;
        }
    }

    // Function to create a booking
    void createBooking(int flightID, int passengerID) {
        Booking booking = {bookingCounter++, flightID, passengerID};
        bookings.push_back(booking);
        cout << "Booking created successfully!" << endl;
    }

    // Function to display all bookings
    void displayBookings() {
        cout << "Current Bookings:" << endl;
        for (const auto& booking : bookings) {
            cout << "Booking ID: " << booking.bookingID 
                 << ", Flight ID: " << booking.flightID 
                 << ", Passenger ID: " << booking.passengerID << endl;
        }
    }
};

int main() {
    FlightBookingSystem system; // Create an instance of the FlightBookingSystem
    int choice;                // Variable to store user choice

    do {
        // Display menu options
        cout << "\nFlight Booking System Menu:" << endl;
        cout << "1. Add Flight" << endl;
        cout << "2. Display Flights" << endl;
        cout << "3. Add Passenger" << endl;
        cout << "4. Display Passengers" << endl;
        cout << "5. Create Booking" << endl;
        cout << "6. Display Bookings" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: { // Add Flight
                string destination, departure;
                float price;
                cout << "Enter destination: ";
                cin >> destination;
                cout << "Enter departure: ";
                cin >> departure;
                cout << "Enter price: ";
                cin >> price;
                system.addFlight(destination, departure, price);
                break;
            }
            case 2: // Display Flights
                system.displayFlights();
                break;
            case 3: { // Add Passenger
                string name, email;
                cout << "Enter passenger name: ";
                cin >> name;
                cout << "Enter passenger email: ";
                cin >> email;
                system.addPassenger(name, email);
                break;
            }
            case 4: // Display Passengers
                system.displayPassengers();
                break;
            case 5: { // Create Booking
                int flightID, passengerID;
                cout << "Enter flight ID: ";
                cin >> flightID;
                cout << "Enter passenger ID: ";
                cin >> passengerID;
                system.createBooking(flightID, passengerID);
                break;
            }
            case 6: // Display Bookings
                system.displayBookings();
                break;
            case 0: // Exit
                cout << "Exiting the system." << endl;
                break;
            default: // Invalid choice
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0); // Loop until the user chooses to exit

    return 0; // End of the program
}
