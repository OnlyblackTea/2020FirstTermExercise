#ifndef M_DATE_HEADER
#define M_DATE_HEADER

bool checkLeap(int year);
int CountDays(int ,int ,int );
class Date{
private:
    int year,month,day;
public:
    Date(int,int,int);
    Date(const Date&);
    void print();
    int operator-(const Date&);
    bool operator>(const Date&);
    bool operator<(const Date&);
    bool cmpyear(const Date&);
};

#endif