# ✈️ Airplane Ticketing System

A C++ desktop ticketing application built with **FLTK** and **Visual Studio**, created to demonstrate practical C++ programming, ticket management, passenger records, seat handling, validation, and graphical user interface development.

## Overview

The Airplane Ticketing System is a desktop application for managing passenger bookings and seat availability. It combines C++ application logic with an FLTK graphical interface to provide an interactive ticketing workflow.

## Features

- 🎫 Ticket booking and cancellation
- 👤 Passenger information management
- 💺 Seat assignment and availability tracking
- 🔎 Ticket search
- 💰 Seat-class based ticket pricing
- 📊 Booking, revenue, and occupancy information
- 🖥️ Graphical desktop interface using FLTK
- ✅ Input validation and user-friendly error handling

## Technologies

- **C++**
- **FLTK 1.4.2**
- **Visual Studio**
- **C++ Standard Library**

## Project Structure

```text
Airplane-Ticketing-System/
├── Airplane Ticketing System.sln
├── Airplane Ticketing System/
│   ├── Source.cpp
│   ├── Airplane Ticketing System.vcxproj
│   └── Airplane Ticketing System.vcxproj.filters
├── fltk-1.4.2/
└── README.md
```

## Key C++ Concepts

### Programming
- Structures and user-defined data types
- Arrays and collections
- Functions and modular design
- References
- String handling
- Formatted output
- Input validation

### Application Logic
- Seat availability management
- Ticket ID generation
- Passenger record handling
- Booking and cancellation workflows
- Ticket pricing
- Revenue and occupancy calculations

### GUI Development
FLTK is used to create the desktop graphical interface and event-driven interaction.

## Getting Started

### Requirements

- Windows
- Visual Studio with **Desktop development with C++**
- FLTK 1.4.2
- A C++17-compatible compiler/toolchain

### Run the Project

1. Clone or download the repository.
2. Open `Airplane Ticketing System.sln` in Visual Studio.
3. Ensure the FLTK include and library paths are configured correctly.
4. Select the required build configuration, such as **x64 / Debug**.
5. Build the solution.
6. Run the application.

### Repository Hygiene

Generated Visual Studio files should not be committed to GitHub, including:

```text
.vs/
x64/
Debug/
Release/
*.exe
*.obj
*.pdb
*.ilk
*.suo
```

These files are build artifacts and can be regenerated locally.

## Future Improvements

- Support for multiple flights and routes
- Persistent database storage
- Configurable aircraft and seat maps
- Flight scheduling
- Passenger authentication
- Administrative dashboard
- Receipt/ticket printing
- More advanced reporting and analytics
- Online payment integration

## Author

**Muneeb Ur Rehman**

GitHub: https://github.com/MuneebCode21

## License

Educational and portfolio project.
