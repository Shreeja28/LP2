#include <iostream>
#include <string>

using namespace std;

enum ServiceType { FLIGHT_BOOKING, FLIGHT_STATUS, BAGGAGE_INQUIRY, CUSTOMER_FEEDBACK, AIRLINE_SCHEDULE, CARGO_SCHEDULE };

// Handle requests based on service type
void handleRequest(const ServiceType& serviceType) {
    switch (serviceType) {
        case FLIGHT_BOOKING: {
            string source, destination;
            int tickets;
            cout << "Enter source city: ";
            getline(cin, source);
            cout << "Enter destination city: ";
            getline(cin, destination);
            cout << "How many tickets would you like to book? ";
            cin >> tickets;
            cin.ignore(); // To consume the newline character
            cout << "Your flight from " << source << " to " << destination << " has been booked for " << tickets << " ticket(s).\n";
            cout << "Check your email for the booking confirmation.\n";
            break;
        }
        case FLIGHT_STATUS: {
            cout << "Please visit this link to track your flight: [Track Flight](https://www.example.com/track-flight-status)\n";
            break;
        }
        case BAGGAGE_INQUIRY: {
            int baggageClaimNo;
            cout << "Enter your baggage claim number: ";
            cin >> baggageClaimNo;
            cin.ignore();
            cout << "Please go to counter " << (baggageClaimNo % 2 == 0 ? "2" : "3") << " for baggage pickup.\n";
            break;
        }
        case CUSTOMER_FEEDBACK: {
            string feedback;
            cout << "Please enter your feedback: ";
            getline(cin, feedback);
            cout << "Thank you for your feedback! It helps us improve our services.\n";
            break;
        }
        case AIRLINE_SCHEDULE: {
            string flightNumber;
            cout << "Enter the flight number to check the schedule: ";
            getline(cin, flightNumber);
            // In a real system, this could query a database or API to return the schedule.
            cout << "Flight " << flightNumber << " is scheduled for 3 PM today.\n";
            break;
        }
        case CARGO_SCHEDULE: {
            string cargoID;
            cout << "Enter the cargo ID to check the schedule: ";
            getline(cin, cargoID);
            // In a real system, this could query a database or API to return cargo availability.
            cout << "Cargo with ID " << cargoID << " is scheduled for pickup at 5 PM today.\n";
            break;
        }
    }
}

ServiceType getServiceTypeFromUser() {
    int choice;
    cout << "\nSelect a service:\n1. Flight Booking\n2. Flight Status\n3. Baggage Inquiry\n4. Customer Feedback\n5. Airline Schedule\n6. Cargo Schedule\nChoice: ";
    cin >> choice;
    cin.ignore(); // To consume the newline character after input
    switch (choice) {
        case 1: return FLIGHT_BOOKING;
        case 2: return FLIGHT_STATUS;
        case 3: return BAGGAGE_INQUIRY;
        case 4: return CUSTOMER_FEEDBACK;
        case 5: return AIRLINE_SCHEDULE;
        case 6: return CARGO_SCHEDULE;
        default:
            cout << "Invalid choice. Defaulting to Flight Booking.\n";
            return FLIGHT_BOOKING;
    }
}

int main() {
    while (true) {
        cout << "\n-----------------------------------------------------\n";
        cout << "Welcome to the Airline Helpdesk!\n";
        cout << "-----------------------------------------------------\n";

        string name;
        cout << "Enter your name: ";
        getline(cin, name);

        ServiceType serviceType = getServiceTypeFromUser();

        handleRequest(serviceType);

        // Ask the user if they want to continue or quit
        char choice;
        cout << "\nDo you want to continue? (y/n): ";
        cin >> choice;
        cin.ignore(); // To consume the newline character
        if (choice == 'n' || choice == 'N') {
            cout << "Thank you for using the Airline Helpdesk. Goodbye!\n";
            break;  // Exit the loop
        }
    }

    return 0;
}
