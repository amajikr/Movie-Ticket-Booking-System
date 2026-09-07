#ifndef BOOKINGSERVICE_CPP
#define BOOKINGSERVICE_CPP
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class BookingService { PriceCalculator calculator; TicketPrinter printer; vector<Booking*> bookings;
public:
    Booking* book(Customer customer, Show& show, const vector<string>& seatNumbers, Payment& payment) { vector<ShowSeat*> selected; for(const auto& n:seatNumbers){ShowSeat* ss=show.findShowSeat(n); if(!ss||!ss->isAvailable()){cout<<"Booking rejected: seat "<<n<<" is invalid or already BOOKED.\n";return nullptr;} selected.push_back(ss);} double total=calculator.calculate(selected); Booking* booking=new Booking(customer,&show,selected,total); if(payment.pay(total)){for(auto ss:selected)ss->book();booking->confirm();bookings.push_back(booking);printer.print(*booking);return booking;} for(auto ss:selected)ss->release();booking->fail();cout<<"Booking failed. Seats released.\n";printer.print(*booking);return booking; }
    bool cancel(const string& id){for(auto b:bookings)if(b->getId()==id&&b->getStatus()==BookingStatus::CONFIRMED){for(auto ss:b->getSeats())ss->release();b->cancel();cout<<"Booking cancelled; seats are AVAILABLE again.\n";return true;}cout<<"Booking not found or cannot be cancelled.\n";return false;}
    void listBookings()const{for(auto b:bookings)cout<<b->getId()<<" | "<<b->getShow().getMovie().getTitle()<<" | "<<bookingStatusName(b->getStatus())<<" | Rs."<<b->getAmount()<<"\n";}
};
#endif
