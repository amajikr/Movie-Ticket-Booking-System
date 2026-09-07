#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

#include "01_Movie.cpp"
#include "02_Seat.cpp"
#include "03_Screen.cpp"
#include "04_Cinema.cpp"
#include "06_ShowSeat.cpp"
#include "05_Show.cpp"
#include "07_Customer.cpp"
#include "08_Booking.cpp"
#include "09_Payment.cpp"
#include "10_PaymentTypes.cpp"
#include "11_PriceCalculator.cpp"
#include "12_TicketPrinter.cpp"
#include "13_BookingService.cpp"

int main() {

    Cinema cinema("PVR Demo Cinema");

    // Movies
    Movie movie1("3 Idiots", "Hindi", 170);
    Movie movie2("Interstellar", "English", 169);

    cinema.addMovie(movie1);
    cinema.addMovie(movie2);

    // Screen 1
    Screen screen1(1);

    screen1.addSeat(Seat("A1", SeatType::SILVER));
    screen1.addSeat(Seat("A2", SeatType::SILVER));
    screen1.addSeat(Seat("A3", SeatType::SILVER));
    screen1.addSeat(Seat("A4", SeatType::SILVER));

    screen1.addSeat(Seat("B1", SeatType::GOLD));
    screen1.addSeat(Seat("B2", SeatType::GOLD));
    screen1.addSeat(Seat("B3", SeatType::GOLD));

    screen1.addSeat(Seat("C1", SeatType::PLATINUM));
    screen1.addSeat(Seat("C2", SeatType::PLATINUM));

    cinema.addScreen(screen1);

    // Screen 2
    Screen screen2(2);

    screen2.addSeat(Seat("A1", SeatType::SILVER));
    screen2.addSeat(Seat("A2", SeatType::SILVER));
    screen2.addSeat(Seat("A3", SeatType::SILVER));
    screen2.addSeat(Seat("A4", SeatType::SILVER));

    screen2.addSeat(Seat("B1", SeatType::GOLD));
    screen2.addSeat(Seat("B2", SeatType::GOLD));
    screen2.addSeat(Seat("B3", SeatType::GOLD));

    screen2.addSeat(Seat("C1", SeatType::PLATINUM));
    screen2.addSeat(Seat("C2", SeatType::PLATINUM));

    cinema.addScreen(screen2);

    // Shows
    vector<Show> shows;

    shows.emplace_back(
        &cinema.getMovies()[0],
        &cinema.getScreens()[0],
        "06:00 PM"
    );

    shows.emplace_back(
        &cinema.getMovies()[0],
        &cinema.getScreens()[1],
        "09:00 PM"
    );

    shows.emplace_back(
        &cinema.getMovies()[1],
        &cinema.getScreens()[0],
        "07:00 PM"
    );

    Customer customer("Abhishek", "9999999999");

    BookingService service;

    while (true) {

        cout << "\n===== MOVIE TICKET BOOKING =====\n";
        cout << "1. Movies  2. Book  3. Cancel  4. My tickets  0. Exit\n";
        cout << "Choose: ";

        int choice;
        cin >> choice;

        if (choice == 0) {
            break;
        }

        // ------------------------------------------------
        // 1. MOVIES
        // ------------------------------------------------
        if (choice == 1) {

            cout << "\n";

            for (size_t i = 0;
                 i < cinema.getMovies().size();
                 i++) {

                cout << "[" << i + 1 << "] "
                     << cinema.getMovies()[i].getTitle()
                     << "\t"
                     << cinema.getMovies()[i].getLanguage()
                     << "\t"
                     << cinema.getMovies()[i].getDuration()
                     << " min\n";
            }

            cout << "\nChoose movie: ";

            int movieChoice;
            cin >> movieChoice;

            if (movieChoice < 1 ||
                movieChoice > (int)cinema.getMovies().size()) {

                cout << "Invalid movie.\n";
                continue;
            }

            // Show list for selected movie
            cout << "\n";

            int count = 0;

            for (size_t i = 0; i < shows.size(); i++) {

                if (&shows[i].getMovie() ==
                    &cinema.getMovies()[movieChoice - 1]) {

                    count++;

                    cout << "[" << count << "] "
                         << "Screen-"
                         << shows[i].getScreen().getNumber()
                         << "\t"
                         << shows[i].getStartTime()
                         << "\n";
                }
            }

            cout << "\nChoose show: ";

            int showChoice;
            cin >> showChoice;

            if (showChoice < 1 || showChoice > count) {
                cout << "Invalid show.\n";
                continue;
            }

            // Find selected show
            int selectedIndex = -1;
            int current = 0;

            for (size_t i = 0; i < shows.size(); i++) {

                if (&shows[i].getMovie() ==
                    &cinema.getMovies()[movieChoice - 1]) {

                    current++;

                    if (current == showChoice) {
                        selectedIndex = i;
                        break;
                    }
                }
            }

            if (selectedIndex == -1) {
                cout << "Invalid show.\n";
                continue;
            }

            // Display seats
            cout << "\n";
            shows[selectedIndex].displaySeats();

            // Seat selection
            cout << "\nSeats (e.g. A1,B2): ";

            string line;
            cin >> line;

            vector<string> seatNames;

            stringstream ss(line);
            string item;

            while (getline(ss, item, ',')) {
                seatNames.push_back(item);
            }

            // Payment
            cout << "\nPay by: 1.UPI  2.Card  3.Cash > ";

            int method;
            cin >> method;

            if (method == 1) {

                UpiPayment payment(true);

                service.book(
                    customer,
                    shows[selectedIndex],
                    seatNames,
                    payment
                );

            }
            else if (method == 2) {

                CardPayment payment;

                service.book(
                    customer,
                    shows[selectedIndex],
                    seatNames,
                    payment
                );

            }
            else if (method == 3) {

                CashPayment payment;

                service.book(
                    customer,
                    shows[selectedIndex],
                    seatNames,
                    payment
                );

            }
            else {
                cout << "Invalid payment method.\n";
            }
        }

        // ------------------------------------------------
        // 2. BOOK
        // ------------------------------------------------
        else if (choice == 2) {

            cout << "\nAvailable Shows:\n";

            for (size_t i = 0; i < shows.size(); i++) {

                cout << "[" << i + 1 << "] "
                     << shows[i].getMovie().getTitle()
                     << " | Screen-"
                     << shows[i].getScreen().getNumber()
                     << " | "
                     << shows[i].getStartTime()
                     << "\n";
            }

            cout << "\nChoose show: ";

            int n;
            cin >> n;

            if (n < 1 || n > (int)shows.size()) {
                cout << "Invalid show.\n";
                continue;
            }

            shows[n - 1].displaySeats();

            cout << "\nSeats (e.g. A1,B2): ";

            string line;
            cin >> line;

            vector<string> names;

            stringstream ss(line);
            string item;

            while (getline(ss, item, ',')) {
                names.push_back(item);
            }

            cout << "\nPay by: 1.UPI  2.Card  3.Cash > ";

            int method;
            cin >> method;

            if (method == 1) {

                UpiPayment payment(true);

                service.book(
                    customer,
                    shows[n - 1],
                    names,
                    payment
                );
            }
            else if (method == 2) {

                CardPayment payment;

                service.book(
                    customer,
                    shows[n - 1],
                    names,
                    payment
                );
            }
            else if (method == 3) {

                CashPayment payment;

                service.book(
                    customer,
                    shows[n - 1],
                    names,
                    payment
                );
            }
            else {
                cout << "Invalid payment method.\n";
            }
        }

        // ------------------------------------------------
        // 3. CANCEL
        // ------------------------------------------------
        else if (choice == 3) {

            string id;

            cout << "Booking ID: ";
            cin >> id;

            service.cancel(id);
        }

        // ------------------------------------------------
        // 4. MY TICKETS
        // ------------------------------------------------
        else if (choice == 4) {

            service.listBookings();
        }

        else {

            cout << "Invalid menu choice.\n";
        }
    }

    cout << "\nThank you.\n";

    return 0;
}
