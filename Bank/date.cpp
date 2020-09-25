#include"date.h"
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<sstream>
#include<cmath>
#include<fstream>
using namespace std;
int Date::cnt = 0;
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
Date::Date():m_cnt(++cnt){}
Date::Date(int year,int month,int day):year(year),month(month),day(day),m_cnt(++cnt){}
Date::Date(const Date& obj){
    year = obj.year;
    month= obj.month;
    day  = obj.day;
    m_cnt= ++cnt;
}
Date Date::read(){
    int year,month,day;
    scanf("%d/%d/%d",&year,&month,&day);
    return Date(year,month,day);
}
Date Date::f_read(ifstream* file){
    int year,month,day;
    char c;
    (*file)>>year>>c>>month>>c>>day;
    return Date(year,month,day);
}
void Date::print(){
    stringstream ss;
    ss << year << '-' << month << '-' << day;
    string tmp;
    tmp = ss.str();
    cout<<setiosflags(ios::left)<<setw(16)<<tmp;
}
bool Date::operator>(const Date& obj) const{
    return ( CountDays(year,month,day)==CountDays(obj.year,obj.month,obj.day) )?( m_cnt>obj.m_cnt ):( CountDays(year,month,day)-CountDays(obj.year,obj.month,obj.day)>0 );
}
bool Date::operator<(const Date& obj) const{
    return ( CountDays(year,month,day)==CountDays(obj.year,obj.month,obj.day) )?( m_cnt<obj.m_cnt ):( CountDays(year,month,day)-CountDays(obj.year,obj.month,obj.day)<0 );
}
bool Date::operator>=(const Date& obj)const{
    return CountDays(year,month,day)-CountDays(obj.year,obj.month,obj.day)>=0 ;
}
bool Date::operator<=(const Date& obj)const{
    return CountDays(year,month,day)-CountDays(obj.year,obj.month,obj.day)<=0 ;
}
int Date::operator-(const Date& obj){
    return abs(CountDays(year,month,day)-CountDays(obj.year,obj.month,obj.day));
}
bool Date::cmpyear(const Date& obj){
    return obj.year<year;
}
void const Date::show(){print();}
int const Date::getDay(){return day;}
int const Date::getMonth(){return month;}
int const Date::getYear(){return year;}
int const Date::getMaxDay(){
    return (month==2)?(((year%4==0 && year%100!=0)||(year%400==0))?29:28):((month==1||month==3||month==5||month==7||month==8||month==10||month==12)?31:30);
}