#ifndef SHOWSEAT_CPP
#define SHOWSEAT_CPP
#include <string>
using namespace std;
enum class SeatStatus { AVAILABLE, BOOKED };
class ShowSeat {
    const Seat* seat; SeatStatus status;
public:
    ShowSeat(const Seat* seat): seat(seat), status(SeatStatus::AVAILABLE) {}
    const Seat& getSeat() const { return *seat; } bool isAvailable() const { return status==SeatStatus::AVAILABLE; }
    bool book() { if(!isAvailable()) return false; status=SeatStatus::BOOKED; return true; }
    void release() { status=SeatStatus::AVAILABLE; }
};
#endif
