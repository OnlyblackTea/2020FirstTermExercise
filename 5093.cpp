#include<iostream>
using namespace std;
int main(){
    int year,month,day,th;
    cin>>year>>month>>day>>th;
    for(int i=1;i<=th;i++){
        day++;
        if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
            if(day==32){
                day=1;
                month++;
            }
        }
        if(month==4||month==6||month==9||month==11){
            if(day==31){
                day=1;
                month++;
            }
        }
        if(month==2){
            if((year%4==0&&year%100!=0)||(year%400==0)){
                if(day==30){
                    day=1;
                    month++;
                }
            }
            else{
                if(day==29){
                    day=1;
                    month++;
                }
            }
        }
        if(month==13){
            month=1;
        }
    }
    cout<<year<<"."<<month<<"."<<day<<endl;
    return 0;
    
}