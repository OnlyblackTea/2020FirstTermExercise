#ifndef M_ACCOUNT_HEADER
#define M_ACCOUNT_HEADER

#include<vector>
#include<string>
#include"date.h"
using namespace std;

class Accumulator{
private:
    Date lastDate;
    double value;
    double sum;
public:
    Accumulator(Date, double);
    double getSum(Date );
    void change(Date , double );
    void reset(Date ,double );
    Date const getDate();
};

class Account{
private:
    string id;
    double balance;
    static double total;
protected:
    Account(Date, string);
    void record(Date, double, string);
    void const error(string);
public:
    int const getId();
    double const getBalance();
    void const show();
    static double getTotal();
    void print(Date, string);
    void print(Date, string, double, double, string);
};

class CreditAccount  : public Account{
private:
    Accumulator acc;
    double credit, rate, fee;
    double const getDebt();
public:
    CreditAccount(Date, string, double, double, double);
    double const getCredit();
    double const getRate();
    double const getFee();
    double const getAvailableCredit();
    void deposit(Date, double, string);
    void withdraw(Date, double, string);
    void settle(Date);
    void const show();
};

class SavingsAccount : public Account{
private:
    Accumulator acc;
    double rate;
public: 
    SavingsAccount(Date, string, double);
    double const getRate();
    void deposit(Date, double, string);
    void withdraw(Date, double, string);
    void settle(Date);
};

#endif