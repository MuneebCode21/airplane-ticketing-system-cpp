#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cctype>

using namespace std;

const int MAX_SEATS = 10;

struct Passenger
{
    int ticketId = 0;
    string name;
    int age = 0;
    string seatClass;
    double price = 0.0;
    bool isBooked = false;
};

// Global passenger data
Passenger passengers[MAX_SEATS];

int nextTicketId = 1001;

// --------------------------------------------------
// Utility functions
// --------------------------------------------------

void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void pauseScreen()
{
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void printLine(char character = '-', int length = 70)
{
    cout << string(length, character) << '\n';
}

void printHeader(const string& title)
{
    cout << "\n";
    printLine('=');
    cout << setw(45) << title << '\n';
    printLine('=');
}

// --------------------------------------------------
// Validation
// --------------------------------------------------

int getValidAge()
{
    int age;

    while (true)
    {
        cout << "Enter passenger age: ";

        if (cin >> age && age >= 1 && age <= 120)
        {
            clearInput();
            return age;
        }

        cout << "Invalid age. Please enter a number between 1 and 120.\n";
        clearInput();
    }
}

string getValidSeatClass()
{
    int choice;

    while (true)
    {
        cout << "\nSelect Seat Class:\n";
        cout << "1. Economy  - $150\n";
        cout << "2. Business - $300\n";
        cout << "3. First    - $500\n";
        cout << "Choice: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input. Please enter 1, 2, or 3.\n";
            clearInput();
            continue;
        }

        clearInput();

        switch (choice)
        {
        case 1:
            return "Economy";

        case 2:
            return "Business";

        case 3:
            return "First";

        default:
            cout << "Please select a valid class.\n";
        }
    }
}

double getSeatPrice(const string& seatClass)
{
    if (seatClass == "Economy")
        return 150.0;

    if (seatClass == "Business")
        return 300.0;

    if (seatClass == "First")
        return 500.0;

    return 0.0;
}

// --------------------------------------------------
// Seat management
// --------------------------------------------------

int findAvailableSeat()
{
    for (int i = 0; i < MAX_SEATS; ++i)
    {
        if (!passengers[i].isBooked)
            return i;
    }

    return -1;
}

void displaySeatMap()
{
    printHeader("AIRCRAFT SEAT MAP");

    for (int i = 0; i < MAX_SEATS; ++i)
    {
        cout << "Seat " << setw(2) << i + 1 << " : ";

        if (passengers[i].isBooked)
            cout << "[BOOKED]  " << passengers[i].name;
        else
            cout << "[AVAILABLE]";

        cout << '\n';
    }
}

// --------------------------------------------------
// Booking
// --------------------------------------------------

void bookTicket()
{
    printHeader("BOOK A TICKET");

    int seatIndex = findAvailableSeat();

    if (seatIndex == -1)
    {
        cout << "Sorry, all seats are currently booked.\n";
        return;
    }

    Passenger& passenger = passengers[seatIndex];

    cout << "Seat assigned: #" << seatIndex + 1 << "\n\n";

    cout << "Enter passenger full name: ";
    getline(cin, passenger.name);

    while (passenger.name.empty())
    {
        cout << "Name cannot be empty.\n";
        cout << "Enter passenger full name: ";
        getline(cin, passenger.name);
    }

    passenger.age = getValidAge();
    passenger.seatClass = getValidSeatClass();
    passenger.price = getSeatPrice(passenger.seatClass);

    passenger.ticketId = nextTicketId++;
    passenger.isBooked = true;

    printLine();

    cout << "\nTICKET BOOKED SUCCESSFULLY!\n\n";
    cout << "Ticket ID   : " << passenger.ticketId << '\n';
    cout << "Passenger   : " << passenger.name << '\n';
    cout << "Age         : " << passenger.age << '\n';
    cout << "Seat Number : " << seatIndex + 1 << '\n';
    cout << "Class       : " << passenger.seatClass << '\n';
    cout << fixed << setprecision(2);
    cout << "Price       : $" << passenger.price << '\n';
}

// --------------------------------------------------
// Display tickets
// --------------------------------------------------

void displayTickets()
{
    printHeader("BOOKED TICKETS");

    bool found = false;
    double totalRevenue = 0.0;

    for (int i = 0; i < MAX_SEATS; ++i)
    {
        if (!passengers[i].isBooked)
            continue;

        found = true;
        totalRevenue += passengers[i].price;

        cout << "Ticket ID   : " << passengers[i].ticketId << '\n';
        cout << "Passenger   : " << passengers[i].name << '\n';
        cout << "Age         : " << passengers[i].age << '\n';
        cout << "Seat        : " << i + 1 << '\n';
        cout << "Class       : " << passengers[i].seatClass << '\n';
        cout << fixed << setprecision(2);
        cout << "Price       : $" << passengers[i].price << '\n';

        printLine();
    }

    if (!found)
    {
        cout << "No tickets have been booked yet.\n";
    }
    else
    {
        cout << "\nTotal Revenue: $"
             << fixed << setprecision(2)
             << totalRevenue << '\n';
    }
}

// --------------------------------------------------
// Search ticket
// --------------------------------------------------

void searchTicket()
{
    printHeader("SEARCH TICKET");

    int ticketId;

    cout << "Enter ticket ID: ";

    if (!(cin >> ticketId))
    {
        cout << "Invalid ticket ID.\n";
        clearInput();
        return;
    }

    clearInput();

    for (int i = 0; i < MAX_SEATS; ++i)
    {
        if (passengers[i].isBooked &&
            passengers[i].ticketId == ticketId)
        {
            cout << "\nTicket found!\n\n";

            cout << "Ticket ID   : " << passengers[i].ticketId << '\n';
            cout << "Passenger   : " << passengers[i].name << '\n';
            cout << "Age         : " << passengers[i].age << '\n';
            cout << "Seat        : " << i + 1 << '\n';
            cout << "Class       : " << passengers[i].seatClass << '\n';
            cout << fixed << setprecision(2);
            cout << "Price       : $" << passengers[i].price << '\n';

            return;
        }
    }

    cout << "No ticket found with ID " << ticketId << ".\n";
}

// --------------------------------------------------
// Cancel ticket
// --------------------------------------------------

void cancelTicket()
{
    printHeader("CANCEL TICKET");

    int seatNumber;

    cout << "Enter seat number to cancel (1-"
         << MAX_SEATS << "): ";

    if (!(cin >> seatNumber))
    {
        cout << "Invalid input.\n";
        clearInput();
        return;
    }

    clearInput();

    if (seatNumber < 1 || seatNumber > MAX_SEATS)
    {
        cout << "Invalid seat number.\n";
        return;
    }

    Passenger& passenger = passengers[seatNumber - 1];

    if (!passenger.isBooked)
    {
        cout << "That seat is not currently booked.\n";
        return;
    }

    cout << "\nPassenger : " << passenger.name << '\n';
    cout << "Ticket ID : " << passenger.ticketId << '\n';

    char confirmation;

    cout << "\nAre you sure you want to cancel this ticket? (Y/N): ";
    cin >> confirmation;
    clearInput();

    if (toupper(static_cast<unsigned char>(confirmation)) != 'Y')
    {
        cout << "Cancellation aborted.\n";
        return;
    }

    passenger = Passenger();

    cout << "\nTicket cancelled successfully.\n";
}

// --------------------------------------------------
// Statistics
// --------------------------------------------------

void displayStatistics()
{
    printHeader("FLIGHT STATISTICS");

    int bookedSeats = 0;
    int availableSeats = 0;
    double revenue = 0.0;

    for (int i = 0; i < MAX_SEATS; ++i)
    {
        if (passengers[i].isBooked)
        {
            ++bookedSeats;
            revenue += passengers[i].price;
        }
        else
        {
            ++availableSeats;
        }
    }

    cout << "Total Seats     : " << MAX_SEATS << '\n';
    cout << "Booked Seats    : " << bookedSeats << '\n';
    cout << "Available Seats : " << availableSeats << '\n';
    cout << fixed << setprecision(2);
    cout << "Total Revenue   : $" << revenue << '\n';

    double occupancyRate =
        (static_cast<double>(bookedSeats) / MAX_SEATS) * 100.0;

    cout << "Occupancy Rate  : "
         << occupancyRate << "%\n";
}

// --------------------------------------------------
// Main menu
// --------------------------------------------------

void displayMenu()
{
    printHeader("AIRPLANE TICKETING SYSTEM");

    cout << "1. Book a Ticket\n";
    cout << "2. Display Booked Tickets\n";
    cout << "3. Search Ticket\n";
    cout << "4. Cancel a Ticket\n";
    cout << "5. Display Seat Map\n";
    cout << "6. Flight Statistics\n";
    cout << "7. Exit\n";

    printLine();
    cout << "Enter your choice: ";
}

int main()
{
    int choice;

    while (true)
    {
        displayMenu();

        if (!(cin >> choice))
        {
            cout << "\nInvalid input. Please enter a number from 1 to 7.\n";
            clearInput();
            pauseScreen();
            continue;
        }

        clearInput();

        switch (choice)
        {
        case 1:
            bookTicket();
            break;

        case 2:
            displayTickets();
            break;

        case 3:
            searchTicket();
            break;

        case 4:
            cancelTicket();
            break;

        case 5:
            displaySeatMap();
            break;

        case 6:
            displayStatistics();
            break;

        case 7:
            cout << "\nThank you for using the Airplane Ticketing System!\n";
            return 0;

        default:
            cout << "\nInvalid choice. Please select 1-7.\n";
        }

        pauseScreen();
    }

    return 0;
}