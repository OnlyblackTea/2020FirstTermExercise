#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    double deg,min,sec,rad;
    const double pi=3.14159;
    cin>>deg>>min>>sec;
    deg+=min/60+sec/3600;
    rad=deg*pi/180;
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<rad<<endl;
    return 0;
}