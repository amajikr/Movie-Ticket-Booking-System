#ifndef PRICECALCULATOR_CPP
#define PRICECALCULATOR_CPP
#include <vector>
using namespace std;
class PriceCalculator { public: double calculate(const vector<ShowSeat*>& seats) const { double total=0; for(auto seat:seats) total+=seat->getSeat().getPrice(); return total; } };
#endif
