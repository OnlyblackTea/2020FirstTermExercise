#ifndef M_ACCOUNT_HEADER
#define M_ACCOUNT_HEADER

#include<vector>
#include<string>
#include<map>
#include"date.h"
using namespace std;

class Accumulator{
private:
    Date lastDate;
    double value;
    double sum;
public:
    Accumulator(Date, double );
    double getSum(Date );
    bool notSettle();
    void change(Date , double );
    void reset(Date ,double );
    Date const getDate();
};
class AccountRecord;
class Account{
private:
    string id;
    double balance;
    static double total;
    static multimap<Date, AccountRecord> recordMap;
protected:
    Account(Date, string);
    void record(Date, double, string);
    void const error(string);
public:
    string getId() const;
    double const getBalance();
    virtual void const show()=0;
    virtual void deposit(Date, double, string)=0;
    virtual void withdraw(Date, double, string)=0;
    virtual void settle(Date)=0;
    static double getTotal();
    static void query(Date, Date);
    void print(Date, string);
    void print(Date, string, double, double, string);
    void print(Date, string, double, double, string)const;
};

class AccountRecord{
private:
    Date date;
    const Account* account;
    double amount;
    double balance;
    std::string desc;
public:
    AccountRecord();
    AccountRecord(Date, Account*, double, double, string);
    void print();
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
    void const show();
};

#endif