#ifndef TICKETPRINTER_CPP
#define TICKETPRINTER_CPP
#include <iostream>
using namespace std;
class TicketPrinter { public: void print(const Booking& b) const { cout<<"\n================ TICKET ================\n"<<"Booking ID: "<<b.getId()<<"\nMovie: "<<b.getShow().getMovie().getTitle()<<"\nScreen: Screen-"<<b.getShow().getScreen().getNumber()<<"  "<<b.getShow().getStartTime()<<"\nSeats: "; for(size_t i=0;i<b.getSeats().size();++i){if(i)cout<<", ";cout<<b.getSeats()[i]->getSeat().getNumber();} cout<<"\nAmount: Rs."<<b.getAmount()<<"  Status: "<<bookingStatusName(b.getStatus())<<"\n==========================================\n"; } };
#endif
