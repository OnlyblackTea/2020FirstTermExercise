#include "account.h"
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

double SavingsAccount::total = 0;

SavingsAccount::SavingsAccount(Date date, string id, double rate):lastDate(date),id(id),rate(rate),balance(0.f),accumulation(0.f){
    this->print(date,id);
}
void SavingsAccount::deposit(Date date,double amount,string commit){
    if(date>lastDate){
        accumulation += balance * (date-lastDate);
    }
    lastDate = date;
    balance+=amount;
    total  +=amount;
    print(date,id,amount,balance,commit);
}
void SavingsAccount::withdraw(Date date,double amount,string commit){
    if(date>lastDate){
        accumulation += balance * (date-lastDate);
    }
    lastDate = date;
    balance-=amount;
    total  -=amount;
    print(date,id,-amount,balance,commit);
}
void SavingsAccount::settle(Date date){
    if(date>lastDate){
        accumulation += balance * (date-lastDate);
    }
    double tmp = floor((accumulation * rate/366) * 100 + 0.5)/100;
    balance += tmp;
    total   += tmp;
    print(date,id,tmp,balance,"interest");
}
void SavingsAccount::show(){
    cout<<setw(16)<<id<<"Balance: "<<balance;
}
void SavingsAccount::print(Date date, string id){
    date.print();cout<<"#"+id+" created"<<endl;
}
void SavingsAccount::print(Date date, string id, double amount, double balance, string commit){
    date.print();cout<<"#"<<setw(15)<<id<<setw(8)<<amount<<setw(8)<<balance<<commit<<endl;
}
double SavingsAccount::getTotal(){return total;}

//new world
double Account::total = 0.f;
Account::Account(Date date, string id):id(id),balance(0.f){print(date, id);}
Accumulator::Accumulator(Date date, double value):lastDate(date),value(value),sum(0){}
SavingsAccount::SavingsAccount(Date date, string id, double rate):Account(date,id),acc(date,0.f),rate(rate){}
CreditAccount::CreditAccount(Date date, string id, double credit, double rate, double fee):Account(date,id),acc(date,0.f),credit(credit),rate(rate),fee(fee){}

//SA
void SavingsAccount::deposit(Date date, double amount, string commit){
    if(date>acc.getDate()){
        acc.change(date, amount);
    }
    record(date, amount, commit);
}
void SavingsAccount::withdraw(Date date, double amount, string commit){
    if(date>acc.getDate()){
        acc.change(date,-amount);
    }
    record(date, -amount, commit);
}
//CA
void CreditAccount::withdraw(Date date, double amount, string commit){
    if(date>acc.getDate()){
        acc.change(date, -amount);
    }
    record(date, -amount, commit);
}
void CreditAccount::deposit(Date date, double amount, string commit){
    if(date>acc.getDate()){
        acc.change(date, amount);
    }
    record(date, amount, commit);
}
void CreditAccount::settle(Date date){
    if(date.cmpyear(acc.getDate())){
        double amount = ceil((acc.getSum(date) * rate/366) * 100 - 0.5)/100;
        record(date, amount-fee, "annual fee");
        acc.reset(date, amount-fee);
    }
    else{
        double amount = ceil((acc.getSum(date) * rate/366) * 100 - 0.5)/100;
        record(date, amount, "interest");
        acc.reset(date, amount);
    }
}


//ACC
void Accumulator::change(Date date, double amount){
    sum += value * (date-lastDate);
    lastDate = date;
    value += amount;
}
double Accumulator::getSum(Date date){
    sum += value * (date-lastDate);
    return sum;
}
void Accumulator::reset(Date date, double amount){
    sum = 0;
    value += amount;
    lastDate = date;
}
//AC
void Account::record(Date date, double amount, string commit){
    balance += amount;
    total += amount;
    print(date, id, amount, balance, commit);
}
void Account::print(Date date, string id){
    date.print();cout<<"#"+id+" created"<<endl;
}
void Account::print(Date date, string id, double amount, double balance, string commit){
    date.print();cout<<"#"<<setw(15)<<id<<setw(8)<<amount<<setw(8)<<balance<<commit<<endl;
}