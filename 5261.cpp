#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n%3==0||n>=4){
        cout<<"B"<<endl;
    }
    else{
        cout<<"A"<<endl;
    }
    return 0;
}