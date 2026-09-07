#ifndef CUSTOMER_CPP
#define CUSTOMER_CPP
#include <string>
using namespace std;
class Customer { string name, phone; public: Customer(string name, string phone):name(name),phone(phone){} string getName()const{return name;} string getPhone()const{return phone;} };
#endif
