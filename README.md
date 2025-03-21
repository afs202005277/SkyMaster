
# Airline Information Management System

## About The Project
SkyMaster Airlines is an innovative Airline Information Management System developed using C++ with an object-oriented programming approach. The project was developed as part of the *Algorithms and Data Structures (AED)* course at the Faculty of Engineering of the University of Porto.

The purpose of this system is to efficiently store and manage data related to airports, airplanes, flights, passengers, baggage, and ground transportation. The system offers a comprehensive interface (Terminal) that allows users to create, list, update, and delete relevant objects associated with the airline company.

---

## Technologies Used
- **C++** - Core programming language used for development.
- **Object-Oriented Programming (OOP)** - Implementation approach for structured data management.
- **File Handling** - Persistent data storage and retrieval using text files.

---

## Features
### General
- Full implementation of *Getters & Setters* and *Creators & Deleters* for all classes.
- Interactive user interface via a Terminal (`Terminal.h`).

### Modules & Functionalities
- **Airport Management**
  - Sort employees and airplanes.
  - Identify nearest and next available ground transport.
  - Access available ground transports by type and distance.
- **Airplane Management**
  - Manage flight schedules and services (cleaning, maintenance).
  - Retrieve past, future, and all services by employee.
  - Unload baggage upon flight arrival.
- **Passenger Management**
  - Ticket purchase (individual and group).
  - Check-in process and boarding.
- **Baggage Management**
  - Automated transport system for baggage handling using a transport cart.
- **Ground Transport Management**
  - Information on various transportation options available to and from airports.

### Terminal Interface
The `Terminal` class provides a robust interface allowing users to interact with all system functionalities. Key functionalities include:
- Object creation, retrieval, modification, and deletion.
- Data navigation via the `handleListDir` and `updateVec` functions.
- Access control through `getObjectID` and `getV`.
