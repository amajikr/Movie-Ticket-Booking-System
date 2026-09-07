MOVIE TICKET BOOKING SYSTEM
============================

A simple console-based Movie Ticket Booking System in C++, developed as part of the TCS-504 System Design Assignment - 1.

This project demonstrates Object-Oriented Programming, UML-based system design, SOLID principles, class relationships, booking management, payment processing, input validation, and modular C++ development in a small, single-cinema environment.

FEATURES
--------
- View currently playing movies
- View shows for a selected movie
- Display seat layout and availability
- Book one or more seats
- Prevent booking of already-booked seats
- Calculate ticket prices according to seat type
- Pay using UPI, Card, or Cash
- Generate and print tickets
- Cancel bookings and release seats
- Handle invalid inputs safely
- Release selected seats when payment fails

SEAT PRICING
------------
Silver: INR 150
Gold: INR 250
Platinum: INR 400

SYSTEM ARCHITECTURE
-------------------

Customer
   |
BookingService
   |
Movie -> Show -> Screen -> Seat
                       |
                    ShowSeat
                       |
                PriceCalculator
                       |
                    Payment
                 /      |      \
               UPI     Card     Cash
                       |
                    Booking
                       |
                 TicketPrinter

BookingService coordinates the overall booking process. Individual classes handle movie management, seat management, pricing, payment, booking, and ticket printing.

UML AND DESIGN DIAGRAMS
-----------------------

FUNCTIONAL REQUIREMENTS
- View currently playing movies
- View shows for a selected movie
- View seat availability
- Book one or more seats
- Calculate ticket price
- Make payment
- Print ticket
- Cancel booking

NON-FUNCTIONAL REQUIREMENTS
- Modularity: Separate classes with clear responsibilities
- Extensibility: New payment methods can be added easily
- Input Validation: Invalid inputs are handled safely
- Maintainability: Meaningful names and organized responsibilities
- Usability: Simple menu-driven console interface

NOUN-VERB ANALYSIS
------------------

Nouns / Classes:
Movie, Show, Seat, Screen, Cinema, ShowSeat, Customer, Booking, Payment, PriceCalculator, TicketPrinter, BookingService

Verbs / Methods or Operations:
Book, Pay, Cancel, Calculate, Print, Display, Select, Release

CLASS DIAGRAM
-------------

Major relationships:
- Composition: Cinema -> Screen
- Composition: Screen -> Seat
- Composition: Show -> ShowSeat
- Aggregation: Show -> Movie
- Association: Show -> Screen
- Association: Booking -> Customer
- Aggregation: Booking -> ShowSeat
- Association: Booking -> Payment
- Inheritance: Payment -> UPI / Card / Cash

The class diagram represents classes, attributes, methods, visibility, multiplicities, and relationships. Payment is an abstract class with UPI, Card, and Cash implementations.

SEQUENCE DIAGRAM
----------------

Customer -> BookingService -> Show -> ShowSeat -> PriceCalculator -> Payment -> Booking -> TicketPrinter

BOOKING SEQUENCE
1. Customer selects a show.
2. BookingService checks available seats.
3. Customer selects one or more seats.
4. ShowSeat availability is validated.
5. PriceCalculator calculates the total price.
6. A booking is created.
7. A payment object is created.
8. Payment is processed.
9. Seats are booked.
10. Booking is confirmed.
11. Ticket is printed.

If payment fails, the selected seats are released and the booking is not confirmed.

RELATIONSHIP ANALYSIS
---------------------

Composition:
- Cinema owns its screens.
- Physical seats belong to a screen.
- ShowSeat exists specifically for a particular show.

Aggregation:
- A movie can exist independently of a particular show.
- A booking references selected show seats but does not own their lifetime.

Association:
- A booking is associated with a customer.
- A booking uses a payment object to complete payment.

Inheritance:
UPIPayment, CardPayment, and CashPayment inherit from the abstract Payment class.

OOP CONCEPTS USED
-----------------

- Encapsulation: Data members are private and accessed through public methods.
- Abstraction: The abstract Payment class defines a common payment contract.
- Inheritance: Payment types inherit from the Payment class.
- Runtime Polymorphism: Payment types are processed through a common interface using virtual functions.
- Compile-Time Polymorphism: Constructor overloading demonstrates compile-time polymorphism.
- Static Members: A static booking counter generates unique booking IDs.
- this Keyword: The this pointer refers to the current object.
- Composition: Cinema -> Screen -> Seat and Show -> ShowSeat.
- Aggregation: Show -> Movie and Booking -> ShowSeat.
- Association: Classes interact without owning one another's lifetime.

PROJECT STRUCTURE
-----------------

Movie-Ticket-Booking/
|
|-- 01_Movie.cpp
|-- 02_Seat.cpp
|-- 03_Screen.cpp
|-- 04_Cinema.cpp
|-- 05_Show.cpp
|-- 06_ShowSeat.cpp
|-- 07_Customer.cpp
|-- 08_Booking.cpp
|-- 09_Payment.cpp
|-- 10_PaymentTypes.cpp
|-- 11_PriceCalculator.cpp
|-- 12_TicketPrinter.cpp
|-- 13_BookingService.cpp
|-- main.cpp
|
|-- README.md

The project uses .cpp files according to its current file-inclusion structure instead of the traditional .h and .cpp header-file structure.

BOOKING FLOW
------------

Select Movie
     |
Select Show
     |
Select Seat(s)
     |
Validate Seats
     |
Calculate Price
     |
Select Payment Method
     |
Make Payment
     |
Confirm Booking
     |
Print Ticket

EDGE CASES
----------

Already-Booked Seat:
Seat is already BOOKED.
Booking rejected.

Invalid Seat:
Invalid seat.
Please enter a valid seat number.

Failed Payment:
Payment failed.
Selected seats are released.

Booking Cancellation:
Booking cancelled successfully.
Seats are AVAILABLE again.

HOW TO RUN
----------

Prerequisites:
- C++ compiler
- GCC, MinGW, or Visual Studio C++
- C++17 or later
- Terminal or Command Prompt

Check GCC installation:
g++ --version

Compile:
g++ -std=c++17 main.cpp -o moviebooking

Compile with warnings:
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o moviebooking

Run on Windows:
.\moviebooking.exe

Run on Linux or macOS:
./moviebooking

DELIBERATELY NOT IMPLEMENTED
----------------------------

This project is intentionally designed as a small, single-cinema educational console application.

- Database or persistent storage
- User login and authentication
- Real online payment gateway
- Email or SMS ticket delivery
- Multi-cinema support
- Graphical User Interface
- Online ticket synchronization

The main focus remains on movies, shows, seats, bookings, payments, ticket printing, and cancellation.

LEARNING OUTCOMES
-----------------

This project demonstrates practical understanding of:
- System design
- Requirement analysis
- UML modeling
- Object-Oriented Programming
- SOLID principles
- C++ modular design
- Class relationships
- Composition and aggregation
- Inheritance and polymorphism
- Booking and payment workflows
- Input validation

TEST CASES
----------

- Book an available seat: Booking confirmed
- Book an already-booked seat: Booking rejected
- Enter an invalid seat: Error message displayed
- Successful UPI payment: Ticket generated
- Successful Card payment: Ticket generated
- Successful Cash payment: Ticket generated
- Failed payment: Selected seats released
- Cancel a confirmed booking: Seats become available
- Enter an invalid menu option: Program continues safely

ASSIGNMENT SUBMISSION CHECKLIST
-------------------------------

[X] Functional requirements
[X] Non-functional requirements
[X] Noun-verb analysis
[X] Class responsibility analysis
[X] Relationship analysis
[X] Class diagram
[X] Sequence diagram
[X] Modular C++ source files
[X] Successful booking flow
[X] Already-booked seat handling
[X] Failed payment handling
[X] Booking cancellation flow
[X] SOLID principles
[X] OOP concepts
[X] README documentation

AUTHOR
------

Aman Kumar
B.Tech CSE - Semester 5
TCS-504 System Design Assignment - 1

PROJECT SUMMARY
---------------

The Movie Ticket Booking System is a C++ console application designed to demonstrate how real-world movie booking requirements can be transformed into a structured object-oriented system design.

The project combines requirements analysis, UML modeling, Object-Oriented Programming, SOLID principles, payment abstraction, seat management, booking workflows, class relationships, input validation, and practical modular C++ implementation.

It provides a complete educational example of a small movie booking system with movie selection, show selection, seat booking, payment processing, ticket printing, and booking cancellation.
