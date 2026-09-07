#ifndef SHOW_CPP
#define SHOW_CPP
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
class Show {
    const Movie* movie; const Screen* screen; string startTime; vector<ShowSeat> showSeats;
public:
    Show(const Movie* movie, const Screen* screen, string startTime): movie(movie), screen(screen), startTime(startTime) { for(const auto& seat:screen->getSeats()) showSeats.emplace_back(&seat); }
    const Movie& getMovie() const { return *movie; } const Screen& getScreen() const { return *screen; } const string& getStartTime() const { return startTime; }
    vector<ShowSeat>& getShowSeats() { return showSeats; } const vector<ShowSeat>& getShowSeats() const { return showSeats; }
    ShowSeat* findShowSeat(const string& number) { for(auto& ss:showSeats) if(ss.getSeat().getNumber()==number) return &ss; return nullptr; }
    void displaySeats() const { cout<<"Screen-"<<screen->getNumber()<<"  "<<startTime<<"  "<<movie->getTitle()<<"\n"; for(const auto& ss:showSeats) cout<<ss.getSeat().getNumber()<<"["<<(ss.isAvailable()?" ":"X")<<"] "<<seatTypeName(ss.getSeat().getType())<<"\n"; }
};
#endif
