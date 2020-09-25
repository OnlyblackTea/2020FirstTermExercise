#ifndef M_DATE_HEADER
#define M_DATE_HEADER

#include<fstream>
using namespace std;

bool checkLeap(int year);
int CountDays(int ,int ,int );
class Date{
private:
    int year,month,day;
    static int cnt;
    int m_cnt;
public:
    Date();
    Date(int,int,int);
    Date(const Date&);
    static Date read();
    static Date f_read(ifstream*);
    int const getDay();
    int const getMonth();
    int const getYear();
    int const getMaxDay();
    void const show();
    void print();
    int operator-(const Date&);
    bool operator>(const Date&) const;
    bool operator<(const Date&) const;
    bool operator>=(const Date&)const;
    bool operator<=(const Date&)const;
    bool cmpyear(const Date&);
};

#endif