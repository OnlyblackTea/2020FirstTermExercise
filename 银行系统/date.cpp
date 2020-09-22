#include"date.h"
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<sstream>
#include<cmath>
using namespace std;

bool checkLeap(int year){
    if((year%4==0 && year%100!=0)||(year%400==0))
        return true;
    else return false;
}

int CountDays(int year,int month,int day){
    if(month<3){
        year--;
        month+=12;
    }
    return 365*year + (year>>2) - year/100 + year/400 + (153*month - 457)/5 + day - 306; 
}

Date::Date(int year,int month,int day):year(year),month(month),day(day){}
Date::Date(const Date& obj){
    year = obj.year;
    month= obj.month;
    day  = obj.day;
}

void Date::print(){
    stringstream ss;
    ss << year << '-' << month << '-' << day;
    string tmp;
    tmp = ss.str();
    cout<<setiosflags(ios::left)<<setw(16)<<tmp;
}
bool Date::operator>(const Date& obj){
    if(year>obj.year){
        return true;
    }
    else if(year == obj.year){
        if(month > obj.month){
            return true;
        }
        else if(month == obj.month){
            if(day > obj.day){
                return true;
            }
            else return false;
        }
        else return false;
    }
    else return false;
}
bool Date::operator<(const Date& obj){
    if(year>obj.year){
        return false;
    }
    else if(year == obj.year){
        if(month > obj.month){
            return false;
        }
        else if(month == obj.month){
            if(day > obj.day){
                return false;
            }
            else return true;
        }
        else return true;
    }
    else return true;
}
int Date::operator-(const Date& obj){
    return abs(CountDays(year,month,day)-CountDays(obj.year,obj.month,obj.day));
}
bool Date::cmpyear(const Date& obj){
    return obj.year<year;
}