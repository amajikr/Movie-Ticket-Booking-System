#ifndef SEAT_CPP
#define SEAT_CPP
#include <string>
using namespace std;
enum class SeatType { SILVER, GOLD, PLATINUM };
string seatTypeName(SeatType type) { if(type==SeatType::SILVER) return "SILVER"; if(type==SeatType::GOLD) return "GOLD"; return "PLATINUM"; }
double seatPrice(SeatType type) { if(type==SeatType::SILVER) return 150; if(type==SeatType::GOLD) return 250; return 400; }
class Seat {
    string number; SeatType type;
public:
    Seat(string number, SeatType type): number(number), type(type) {}
    string getNumber() const { return number; } SeatType getType() const { return type; } double getPrice() const { return seatPrice(type); }
};
#endif
