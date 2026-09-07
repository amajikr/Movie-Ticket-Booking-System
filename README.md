# Movie Ticket Booking System

A menu-driven C++ console application for a single cinema, created for the **TCS-504 System Design Assignment 1**.

The project demonstrates object-oriented design with movies, screens, seats, shows, show-specific seat availability, customers, bookings, pricing, payments, ticket printing, and cancellation.

## Features

- List currently playing movies
- List shows for a selected movie
- Display seat layout with `AVAILABLE` and `BOOKED` status
- Book one or more seats
- Reject invalid or already-booked seats
- Calculate prices by seat type:
  - Silver: â‚¹150
  - Gold: â‚¹250
  - Platinum: â‚¹400
- Pay by UPI, Card, or Cash
- Print a ticket with booking details
- Cancel a booking and release its seats
- Handle invalid menu choices and seat numbers without crashing

## Project Structure

The assignment requires one class per file and no header files. The source files are included directly in `main.cpp`.

```text
01_Movie.cpp
02_Seat.cpp
03_Screen.cpp
04_Cinema.cpp
05_Show.cpp
06_ShowSeat.cpp
07_Customer.cpp
08_Booking.cpp
09_Payment.cpp
10_PaymentTypes.cpp
11_PriceCalculator.cpp
12_TicketPrinter.cpp
13_BookingService.cpp
main.cpp
```

## Requirements

- C++ compiler with C++17 support
- `g++`, MinGW, or Visual Studio C++
- Terminal or command prompt

Check your compiler:

```bash
g++ --version
```

## Build Instructions

Open a terminal in the folder containing all `.cpp` files and run:

```bash
g++ -std=c++17 main.cpp -o movie_booking
```

If you want compiler warnings enabled:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o movie_booking
```

## Run Instructions

### Linux or macOS

```bash
./movie_booking
```

### Windows

```bash
movie_booking.exe
```

## Example Flow

1. Select `1` to list movies.
2. Select `2` to list shows.
3. Select `3` to view the seat layout.
4. Select `4` to book seats, for example `A1,B1`.
5. Select a payment method.
6. View the generated ticket.
7. Select `5` to cancel a booking using its booking ID.
8. Select `6` to view existing bookings.
9. Select `0` to exit.

## Test Cases for Demonstration

### Successful booking

- Select an available seat such as `A1`.
- Choose UPI, Card, or Cash.
- Confirm that a ticket is printed with status `CONFIRMED`.

### Already-booked seat

- Book `A1` successfully.
- Try booking `A1` again for the same show.
- Confirm that the system rejects the request and does not change other seats.

### Invalid seat

- Enter a seat that does not exist, such as `Z99`.
- Confirm that the program displays a clear rejection message and continues running.

### Cancellation

- Note a confirmed booking ID such as `BK1001`.
- Select `5` and enter the booking ID.
- Display the seats again and confirm they are `AVAILABLE`.

## OOP Concepts Demonstrated

- **Encapsulation:** private data members and controlled methods
- **Abstraction:** abstract `Payment` class with `pay()` contract
- **Inheritance:** `UpiPayment`, `CardPayment`, and `CashPayment` inherit from `Payment`
- **Runtime polymorphism:** payment is processed through a `Payment` reference
- **Static member:** booking IDs are generated using a shared counter
- **Composition:** `Cinema` owns `Screen` objects, and `Screen` owns physical seats
- **Aggregation:** `Show` references an existing `Movie` and `Screen`
- **Association:** `BookingService` coordinates domain objects without owning their identities

## Design Scope

This is an in-memory educational console application. It intentionally does not include database storage, user login, online payment gateway integration, email delivery, multi-cinema support, or a graphical user interface.

## Upload Instructions

### Upload to GitHub

1. Create a new GitHub repository, for example `movie-ticket-booking-system`.
2. Add all `.cpp` files and this `README.md`.
3. Commit the files with a message such as:

```bash
git init
git add .
git commit -m "Add movie ticket booking system"
git branch -M main
git remote add origin https://github.com/YOUR-USERNAME/movie-ticket-booking-system.git
git push -u origin main
```

Replace `YOUR-USERNAME` with your GitHub username and use your actual repository URL.

### Upload to LinkedIn

1. Open LinkedIn and start a new post.
2. Attach the prepared one-page PDF summary.
3. Use the project caption prepared for the assignment.
4. Add relevant hashtags such as:

```text
#SystemDesign #Cpp #OOP #SOLID #SoftwareEngineering #UML #BTech #StudentProject
```

5. Add the GitHub repository URL to the post or first comment.
6. Check that the PDF, caption, repository link, and visibility are correct before publishing.

## Assignment Submission Checklist

- [ ] Requirement analysis with FR and NFR
- [ ] Noun-verb analysis table
- [ ] Class responsibility table
- [ ] Relationship table with lifetime justifications
- [ ] Class diagram
- [ ] Sequence diagram for booking and UPI payment
- [ ] Modular C++ source files
- [ ] Successful booking demo
- [ ] Already-booked seat demo
- [ ] Failed payment or failure-handling explanation
- [ ] Cancellation demo
- [ ] SOLID mapping
- [ ] PDF report and repository link
