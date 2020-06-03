#include<iostream>
using namespace std;
int main(){
    double x1,x2,y1,y2,x3,x4,y3,y4;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    double a=y2-y1;
    double b=x1-x2;
    double c=x1*y2-y1*x2;
    int flag1,flag2;
    if(a*x3+b*y3>c){
        flag1=1;
    }
    else{
        if(a*x3+b*y3==c){
            flag1=2;
        }
        else{
            flag1=0;
        }
    }
    if(a*x4+b*y4>c){
        flag2=1;
    }
    else{
        if(a*x4+b*y4==c){
            flag2=2;
        }
        else{
            flag2=0;
        }
    }
    if(flag1==flag2){
        if(flag1==2){
            cout<<"P1 and P2 are both in the straight line!"<<endl;
        }
        else{
            cout<<"P1 and P2 are on the same side of the straight line!"<<endl;
        }
    }
    else{
        if(flag1==2){
            cout<<"P1 is in the straight line!"<<endl;
        }
        else if(flag2==2){
            cout<<"P2 is in the straight line!"<<endl;
        }
        else{
            cout<<"P1 and P2 are not on the same side of the straight line!"<<endl;

        }
    }
    return 0;
}