# C++ Mini Projects


## 1. Time Converter

A simple C++ program that converts time between seconds and the `HH:MM:SS` format.

### How it works

When the program starts, it shows a menu where you can choose what type of conversion you want to perform.

* Convert seconds into `HH:MM:SS`
* Convert `HH:MM:SS` into seconds

The program then asks for the required input and displays the converted time.


### Main Concept Used

The project is built around a `TimeConverter` class, which handles the time conversion operations.

### Output

https://drive.google.com/file/d/1YQVlIWbLvriLSk7tzhFopNg7-xzyMaha/view?usp=sharing


## 2. Railway Reservation System

A basic C++ command-line program for managing train records.

The program allows the user to add new train records, view all available records, and search for a train using its train number.

### How it works

When the program starts, a few train records are already available. A menu is then displayed:

```text
1. Add New Train Record
2. Display All Train Records
3. Search Train by Number
4. Exit
```

Each train record contains:

* Train Number
* Train Name
* Source
* Destination
* Departure Time

### Output
https://drive.google.com/file/d/15C7jUwn7V3anmhd4GMJtDYbnm9NX5zCT/view?usp=sharing

### Main Concept Used

The project uses two classes:

* `Train` – stores the details of a train.
* `RailwaySystem` – handles operations such as adding, displaying, and searching train records.

This keeps the train data and the operations related to it separate.

---
## 3. Vehicle Registry System
A C++ command-line program for managing a registry of different types of vehicles, demonstrating all major types of inheritance.

**How it works**
When the program starts, it shows a menu where you can choose what operation you want to perform.

* Add New Vehicle (of a different type)
* View All Vehicles
* Search Vehicle by ID
* Exit

When adding a vehicle, the user selects the specific vehicle type (Car, Electric Car, Aircraft, Flying Car, Sport Car, Sedan, or SUV) and enters the relevant details for that type.

Each vehicle record contains (depending on type):

* Vehicle ID
* Manufacturer
* Model
* Year
* Fuel Type (for car-based vehicles)
* Battery Capacity (for electric vehicles)
* Flight Range (for aircraft-based vehicles)
* Top Speed (for sport cars)

### Output
https://drive.google.com/drive/folders/1T54UyJlu_uxIeErwu35Eq7ytv7UfWRbF?usp=sharing

### Main Concept Used
The project uses a base class and multiple derived classes:

* `Vehicle` – stores common details shared by every vehicle (ID, manufacturer, model, year).
* `Car`, `ElectricCar`, `Aircraft`, `FlyingCar`, `SportCar`, `Sedan`, `SUV` – derived classes that extend `Vehicle` with their own specific attributes, demonstrating Single, Multilevel, Multiple, and Hierarchical inheritance.
* `VehicleRegistry` – manages the collection of vehicles, handling adding, displaying, and searching operations separately from the vehicle data itself.


## Technologies used

* C++
* Object-Oriented Programming (OOP)
* All Types of Inheritance (Single, Multiple, Multilevel, Hierarchical)
* Virtual Functions & Runtime Polymorphism
* Dynamic Memory Allocation (`new` / `delete`)
* Pointers & Array of Pointer Objects
* Static Members
* Encapsulation (Getters & Setters)


## Purpose

These projects were created to practice basic C++ programming and understand how classes and objects can be used to build small real-world applications.
