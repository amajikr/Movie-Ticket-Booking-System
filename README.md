Movie Ticket Booking System

A simple console-based Movie Ticket Booking System in C++, developed as part of the TCS-504 System Design Assignment – 1.

The project demonstrates Object-Oriented Programming, UML-based system design, SOLID principles, class relationships, booking management, payment processing, and input validation in a small single-cinema environment.

📌 Features
🎥 View currently playing movies
🕐 View shows for a selected movie
💺 Display seat layout and availability
🎟️ Book one or more seats
🚫 Prevent booking of already-booked seats
💰 Calculate ticket price according to seat type
💳 Pay using UPI, Card, or Cash
🧾 Generate and print tickets
❌ Cancel bookings and release seats
⚠️ Handle invalid inputs safely
🔄 Release selected seats when payment fails
💰 Seat Pricing
Seat Type	Price
Silver	₹150
Gold	₹250
Platinum	₹400
🏗️ System Architecture

The main booking workflow is:

Customer
   ↓
BookingService
   ↓
Movie → Show → Screen → Seat
                ↓
             ShowSeat
                ↓
        PriceCalculator
                ↓
             Payment
           ↙    ↓    ↘
         UPI   Card   Cash
                ↓
             Booking
                ↓
          TicketPrinter

BookingService coordinates the overall booking process, while individual classes handle specific responsibilities such as movie management, seat management, pricing, payment, booking, and ticket printing.

📊 UML & Design Diagrams

The project includes UML and design diagrams that explain the system from requirements to implementation.

1. Functional Requirements

The functional requirements describe the main operations provided by the system:

View currently playing movies
View shows for a selected movie
View seat availability
Book one or more seats
Calculate ticket price
Make payment
Print ticket
Cancel booking
2. Non-Functional Requirements

The system focuses on the following quality requirements:

Modularity – Separate classes with clear responsibilities
Extensibility – New payment methods can be added easily
Input Validation – Invalid inputs are handled safely
Maintainability – Meaningful names and organized responsibilities
Usability – Simple menu-driven console interface
3. Noun–Verb Analysis

Noun–verb analysis is used to identify important classes and operations from the problem statement.

Nouns → Classes
Movie
Show
Seat
Screen
Cinema
ShowSeat
Customer
Booking
Payment
PriceCalculator
TicketPrinter
BookingService
Verbs → Methods / Operations
Book
Pay
Cancel
Calculate
Print
Display
Select
Release

This analysis helps determine what the system objects represent and what responsibilities should be assigned to each class.

🧩 Class Diagram

The class diagram represents the overall static structure of the system.

It contains:

Classes and their attributes
Methods and visibility
Multiplicities
Class relationships
Abstract Payment class
Payment inheritance hierarchy
Major Relationships
Relationship	Classes
Composition	Cinema → Screen
Composition	Screen → Seat
Composition	Show → ShowSeat
Aggregation	Show → Movie
Association	Show → Screen
Association	Booking → Customer
Aggregation	Booking → ShowSeat
Association	Booking → Payment
Inheritance	Payment → UPI / Card / Cash

The class diagram provides a structural view of how the different objects interact with each other.

🔄 Sequence Diagram

The sequence diagram represents the interaction when a customer books a seat and pays using UPI.

Customer
   ↓
BookingService
   ↓
Show
   ↓
ShowSeat
   ↓
PriceCalculator
   ↓
Payment
   ↓
Booking
   ↓
TicketPrinter
Booking Sequence
1. Customer selects a show
2. BookingService checks available seats
3. Customer selects seat(s)
4. ShowSeat availability is validated
5. PriceCalculator calculates total price
6. Booking is created
7. UPI payment is created
8. Payment is processed
9. Seats are booked
10. Booking is confirmed
11. Ticket is printed

If payment fails, the selected seats are released and the booking is not confirmed.

🔗 Relationship Table

The system uses different UML relationships based on ownership and object lifetime.

Composition

Cinema → Screen

A cinema owns its screens.

Screen → Seat

Physical seats belong to a screen.

Show → ShowSeat

ShowSeat exists specifically for a particular show.

Aggregation

Show → Movie

A movie can exist independently of a particular show.

Booking → ShowSeat

A booking references selected show seats but does not own their lifetime.

Association

Booking → Customer

A booking is associated with a customer.

Booking → Payment

A booking uses a payment object to complete payment.

Inheritance
              Payment
             /   |   \
           UPI  Card  Cash

UpiPayment, CardPayment, and CashPayment are specialized payment implementations.

🧠 OOP Concepts Used
Encapsulation

Data members are kept private and accessed through public methods.

Abstraction

The abstract Payment class defines the common payment contract.

Inheritance

UpiPayment, CardPayment, and CashPayment inherit from Payment.

Runtime Polymorphism

Different payment types can be processed through the common Payment interface using virtual functions.

Compile-Time Polymorphism

Constructor overloading is used to demonstrate compile-time polymorphism.

Static Members

A static booking counter is used to generate unique booking IDs.

this Keyword

The this pointer is used to refer to the current object.

Composition

Strong ownership relationships are demonstrated through:

Cinema → Screen → Seat
Show → ShowSeat
Aggregation

Independent objects are connected using aggregation, such as:

Show → Movie
Booking → ShowSeat
Association

Classes interact without owning each other's lifetime.

📂 Project Structure

The project follows the assignment requirement of one class per file and no header files.

Movie-Ticket-Booking/
│
├── 01_Movie.cpp
├── 02_Seat.cpp
├── 03_Screen.cpp
├── 04_Cinema.cpp
├── 05_Show.cpp
├── 06_ShowSeat.cpp
├── 07_Customer.cpp
├── 08_Booking.cpp
├── 09_Payment.cpp
├── 10_PaymentTypes.cpp
├── 11_PriceCalculator.cpp
├── 12_TicketPrinter.cpp
├── 13_BookingService.cpp
├── main.cpp
│
└── README.md
🎟️ Booking Flow
Select Movie
     ↓
Select Show
     ↓
Select Seat(s)
     ↓
Validate Seats
     ↓
Calculate Price
     ↓
Select Payment
     ↓
Make Payment
     ↓
Confirm Booking
     ↓
Print Ticket
⚠️ Edge Cases
1. Already Booked Seat

If a selected seat is already booked:

Seat is already BOOKED.
Booking rejected.

The system does not change the availability of other seats.

2. Invalid Seat

If an invalid seat number is entered:

Invalid seat.
Please enter a valid seat number.

The program continues running without crashing.

3. Failed Payment

If payment fails:

Payment failed.
Selected seats are released.

The booking is not confirmed.

4. Cancellation

When a confirmed booking is cancelled:

Booking cancelled successfully.
Seats are AVAILABLE again.
⚙️ How to Run
Prerequisites
C++ compiler
GCC / MinGW / Visual Studio C++
C++17 or later
Terminal or Command Prompt

Check GCC installation:

g++ --version
Compile

From the project folder, run:

g++ -std=c++17 main.cpp -o moviebooking

For compiler warnings:

g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o moviebooking
Run on Windows
.\moviebooking.exe
Run on Linux/macOS
./moviebooking

Note: The project uses .cpp files according to its current file-inclusion structure instead of a traditional .h/.cpp header structure.

🚫 Deliberately Not Implemented

The project is intentionally designed as a small, single-cinema educational console application.

The following features are outside the project scope:

Database / persistent storage
User login and authentication
Real online payment gateway
Email or SMS delivery
Multi-cinema support
Graphical User Interface
Online ticket synchronization

The focus remains on:

Movies
Shows
Seats
Booking
Payment
Ticket Printing
Cancellation
🎯 Learning Outcomes

This project demonstrates practical understanding of:

System Design
Requirement Analysis
UML Diagrams
Object-Oriented Programming
SOLID Principles
C++ Modular Design
Class Relationships
Composition & Aggregation
Inheritance & Polymorphism
Booking and Payment Workflow
Input Validation
🧪 Test Cases
Test Case	Expected Result
Book available seat	Booking confirmed
Book already-booked seat	Booking rejected
Enter invalid seat	Error message displayed
Successful UPI payment	Ticket generated
Successful Card payment	Ticket generated
Successful Cash payment	Ticket generated
Failed payment	Seats released
Cancel confirmed booking	Seats become available
Invalid menu option	Program continues safely
📋 Assignment Submission Checklist
 Functional Requirements
 Non-Functional Requirements
 Noun–Verb Analysis
 Class Responsibility Analysis
 Relationship Analysis
 Class Diagram
 Sequence Diagram
 Modular C++ Source Files
 Successful Booking Flow
 Already-Booked Seat Handling
 Failed Payment Handling
 Cancellation Flow
 SOLID Principles
 OOP Concepts
 README Documentation
👨‍💻 Author

Aman Kumar

B.Tech CSE — Semester 5

System Design Assignment — 1

📌 Project Summary

The Movie Ticket Booking System is a C++ console application designed to demonstrate how real-world movie booking requirements can be transformed into a structured object-oriented system design.

The project combines requirements analysis, UML modeling, class relationships, OOP principles, SOLID principles, payment abstraction, seat management, booking workflows, and practical C++ implementation in a single educational system.
