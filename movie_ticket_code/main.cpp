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

int main(){
    Cinema cinema("PVR Demo Cinema");
    Movie movie1("3 Idiots","Hindi",170), movie2("Interstellar","English",169); cinema.addMovie(movie1); cinema.addMovie(movie2);
    Screen screen1(1); screen1.addSeat(Seat("A1",SeatType::SILVER)); screen1.addSeat(Seat("A2",SeatType::SILVER)); screen1.addSeat(Seat("A3",SeatType::SILVER)); screen1.addSeat(Seat("B1",SeatType::GOLD)); screen1.addSeat(Seat("B2",SeatType::GOLD)); screen1.addSeat(Seat("C1",SeatType::PLATINUM)); cinema.addScreen(screen1);
    vector<Show> shows; shows.emplace_back(&cinema.getMovies()[0],&cinema.getScreens()[0],"06:00 PM"); shows.emplace_back(&cinema.getMovies()[0],&cinema.getScreens()[0],"09:00 PM"); shows.emplace_back(&cinema.getMovies()[1],&cinema.getScreens()[0],"07:00 PM");
    Customer customer("Abhishek","9999999999"); BookingService service;
    while(true){cout<<"\n===== MOVIE TICKET BOOKING =====\n1. Movies  2. Shows  3. Seats  4. Book  5. Cancel  6. My Tickets  0. Exit\nChoose: "; int choice; if(!(cin>>choice)){cin.clear();cin.ignore(10000,'\n');cout<<"Invalid input.\n";continue;} if(choice==0)break;
        if(choice==1){for(size_t i=0;i<cinema.getMovies().size();++i)cout<<i+1<<". "<<cinema.getMovies()[i].getTitle()<<" | "<<cinema.getMovies()[i].getLanguage()<<" | "<<cinema.getMovies()[i].getDuration()<<" min\n";}
        else if(choice==2){for(size_t i=0;i<shows.size();++i)cout<<i+1<<". "<<shows[i].getMovie().getTitle()<<" | Screen-"<<shows[i].getScreen().getNumber()<<" | "<<shows[i].getStartTime()<<"\n";}
        else if(choice==3){cout<<"Show number: ";int n;cin>>n;if(n>=1&&n<=(int)shows.size())shows[n-1].displaySeats();else cout<<"Invalid show.\n";}
        else if(choice==4){int n;cout<<"Show number: ";cin>>n;if(n<1||n>(int)shows.size()){cout<<"Invalid show.\n";continue;}shows[n-1].displaySeats();cout<<"Seats (comma separated, e.g. A1,B1): ";string line;cin>>line;vector<string> names;stringstream ss(line);string item;while(getline(ss,item,','))names.push_back(item);cout<<"Pay by 1.UPI 2.Card 3.Cash: ";int method;cin>>method;bool fail=false;if(method==1){UpiPayment p(!fail);service.book(customer,shows[n-1],names,p);}else if(method==2){CardPayment p;service.book(customer,shows[n-1],names,p);}else if(method==3){CashPayment p;service.book(customer,shows[n-1],names,p);}else cout<<"Invalid payment method.\n";}
        else if(choice==5){string id;cout<<"Booking ID: ";cin>>id;service.cancel(id);}
        else if(choice==6)service.listBookings(); else cout<<"Invalid menu choice.\n";
    }
    cout<<"Thank you.\n"; return 0;
}
