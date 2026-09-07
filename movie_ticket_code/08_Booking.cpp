#ifndef BOOKING_CPP
#define BOOKING_CPP
#include <vector>
#include <string>
using namespace std;
enum class BookingStatus { PENDING, CONFIRMED, FAILED, CANCELLED };
string bookingStatusName(BookingStatus s){if(s==BookingStatus::PENDING)return "PENDING";if(s==BookingStatus::CONFIRMED)return "CONFIRMED";if(s==BookingStatus::FAILED)return "FAILED";return "CANCELLED";}
class Booking { static int nextId; string id; Customer customer; Show* show; vector<ShowSeat*> seats; double amount; BookingStatus status;
public: Booking(Customer customer, Show* show, vector<ShowSeat*> seats, double amount):id("BK"+to_string(nextId++)),customer(customer),show(show),seats(seats),amount(amount),status(BookingStatus::PENDING){}
 string getId()const{return id;} const Customer& getCustomer()const{return customer;} Show& getShow()const{return *show;} const vector<ShowSeat*>& getSeats()const{return seats;} double getAmount()const{return amount;} BookingStatus getStatus()const{return status;}
 void confirm(){status=BookingStatus::CONFIRMED;} void fail(){status=BookingStatus::FAILED;} void cancel(){status=BookingStatus::CANCELLED;}
};
int Booking::nextId=1001;
#endif
