#include<iostream>
using namespace std;
int main(){
    char a,b,c;
    cin>>a>>b>>c;
    int x,y,z;
    x=a-'0';
    y=b-'0';
    z=c-'0';
    cout<<(z+6)%10<<(y+6)%10<<(x+6)%10<<endl;
    return 0;
}