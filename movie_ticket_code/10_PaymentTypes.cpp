#ifndef PAYMENTTYPES_CPP
#define PAYMENTTYPES_CPP
#include <iostream>
using namespace std;
class UpiPayment: public Payment { bool success; public: UpiPayment(bool success=true):success(success){} bool pay(double amount) override { cout<<"[UPI] Rs."<<amount<<(success?" paid successfully\n":" payment failed\n"); return success; } const char* method()const override{return "UPI";} };
class CardPayment: public Payment { bool success; public: CardPayment(bool success=true):success(success){} bool pay(double amount) override { cout<<"[CARD] Rs."<<amount<<(success?" paid successfully\n":" payment failed\n"); return success; } const char* method()const override{return "CARD";} };
class CashPayment: public Payment { bool success; public: CashPayment(bool success=true):success(success){} bool pay(double amount) override { cout<<"[CASH] Rs."<<amount<<(success?" received successfully\n":" payment failed\n"); return success; } const char* method()const override{return "CASH";} };
#endif
