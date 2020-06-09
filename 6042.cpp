#include<iostream>
using namespace std;
int pd(int year){
    if((year%4==0&&year%100!=0)||(year%400==0)){
        return 1;
    }
    else return 0;
}
int getdays(int month,int year){
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
        return 31;
    }
    else if(month==4||month==6||month==9||month==11){
        return 30;
    }
    else return 28+pd(year);
}

int main(){
    int a,b,c,y1,y2;
    cin>>a>>b>>c>>y1>>y2;
    int cntweek;
    if(y1>1850){
        cntweek=2;
        for(int i=1850;i<y1;i++){
            for(int j=1;j<=12;j++){
                for(int k=1;k<=getdays(j,i);k++){
                    cntweek++;
                    cntweek%=7;
                }
            }
        }
    }
    if(y1<1850){
        cntweek=3;
        for(int i=1850;i>=y1;i--){
            for(int j=12;j>=1;j--){
                for(int k=getdays(j,i);k>=1;k--){
                    cntweek=(cntweek+6)%7;
                }
            }
        }
    }
    for(int i=y1;i<=y2;i++){
        for(int j=1;j<=12;j++){
            
        }
    }
}