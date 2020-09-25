#include "account.h"
#include<iostream>
#include<iomanip>
#include<cmath>
#include<map>
using namespace std;

//double SavingsAccount::total = 0;
/*
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
*/
//new world
double Account::total = 0.f;
multimap<Date, AccountRecord> Account::recordMap;
Account::Account(Date date, string id):id(id),balance(0.f){print(date, id);}
Accumulator::Accumulator(Date date, double value):lastDate(date),value(value),sum(0){}
SavingsAccount::SavingsAccount(Date date, string id, double rate):Account(date,id),acc(date,0.f),rate(rate){}
CreditAccount::CreditAccount(Date date, string id, double credit, double rate, double fee):Account(date,id),acc(date,0.f),credit(credit),rate(rate),fee(fee){}
AccountRecord::AccountRecord(){}
AccountRecord::AccountRecord(Date date,Account* p, double amount, double balance, string desc):date(date),account(p),amount(amount),balance(balance),desc(desc){}

//SA
void SavingsAccount::deposit(Date date, double amount, string commit){
    if(date>=acc.getDate()){
        acc.change(date, amount);
    }
    record(date, amount, commit);
}
void SavingsAccount::withdraw(Date date, double amount, string commit){
    if(date>=acc.getDate()){
        acc.change(date,-amount);
    }
    record(date, -amount, commit);
}
void SavingsAccount::settle(Date date){
    if(acc.notSettle()) return;
    if(date.getMonth()==1){
        double amount = floor((acc.getSum(date) * rate/366) * 100 + 0.5)/100;
        record(date, amount, " interest");
        acc.reset(date, amount);
    }
}
void   const SavingsAccount::show(){cout<<setw(16)<<getId()<<"Balance: "<<getBalance();}
double const SavingsAccount::getRate(){return rate;}

//CA
void CreditAccount::withdraw(Date date, double amount, string commit){
    if(date>=acc.getDate()){
        acc.change(date, -amount);
    }
    record(date, -amount, commit);
}
void CreditAccount::deposit(Date date, double amount, string commit){
    if(date>=acc.getDate()){
        acc.change(date, amount);
    }
    record(date, amount, commit);
}
void CreditAccount::settle(Date date){
    double amount = ceil((acc.getSum(date) * rate) * 100 - 0.5)/100;
    if(amount != 0){
        record(date, amount, " interest");
        acc.reset(date, amount);
    }
    if(date.getMonth() == 1){
        record(date, -fee, " annual fee");
        acc.reset(date, -fee);
    }
}
void   const CreditAccount::show(){cout<<setw(16)<<getId()<<"Balance: "<<setw(7)<<getBalance()<<"Available credit:"<<getCredit()+getBalance();}
double const CreditAccount::getCredit(){return credit;}
double const CreditAccount::getRate(){return rate;}
double const CreditAccount::getFee(){return fee;}
double const CreditAccount::getAvailableCredit(){return credit-getBalance();}

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
bool Accumulator::notSettle(){return (sum==0 && value==0)?true:false;}
Date const Accumulator::getDate(){return lastDate;}

//AC
void Account::record(Date date, double amount, string commit){
    balance += amount;
    total += amount;
    recordMap.insert(pair<Date, AccountRecord>(date,AccountRecord(date,this,amount,balance,commit)));
    print(date, id, amount, balance, commit);
}
void Account::print(Date date, string id){
    date.print();cout<<"#"+id+" created"<<endl;
}
void Account::print(Date date, string id, double amount, double balance, string commit){
    date.print();cout<<"#"<<setw(15)<<id<<setw(8)<<amount<<setw(8)<<balance<<commit<<endl;
}
void Account::print(Date date, string id, double amount, double balance, string commit)const{
    date.print();cout<<"#"<<setw(15)<<id<<setw(8)<<amount<<setw(8)<<balance<<commit<<endl;
}
void AccountRecord::print(){
    account->print(date, account->getId(), amount, balance, desc);
}
void Account::query(Date date1, Date date2){
    for(multimap<Date, AccountRecord>::iterator iter=recordMap.begin();iter!=recordMap.end();iter++){
        if((iter->first)>=date1 && (iter->first)<=date2){
            iter->second.print();
        }
    }
}
double const Account::getBalance(){return balance;}
string Account::getId() const{return id;}
double Account::getTotal(){return total;}