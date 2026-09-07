#ifndef SCREEN_CPP
#define SCREEN_CPP
#include <vector>
#include <string>
using namespace std;
class Screen {
    int screenNumber; vector<Seat> seats;
public:
    Screen(int number): screenNumber(number) {}
    void addSeat(const Seat& seat) { seats.push_back(seat); }
    int getNumber() const { return screenNumber; } const vector<Seat>& getSeats() const { return seats; }
    const Seat* findSeat(const string& number) const { for(const auto& s:seats) if(s.getNumber()==number) return &s; return nullptr; }
};
#endif
