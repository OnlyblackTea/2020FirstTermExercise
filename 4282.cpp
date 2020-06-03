#include<iostream>
using namespace std;
int main(){
    for(char a='A';a<='D';a++){
        if((a!='B'&&a=='D')+(a!='B'&&a=='C')+(a!='A'&&a=='B')+(a!='D')==3){
            if(a=='A'){
                cout<<"甲"<<endl;
            }
            if(a=='B'){
                cout<<"乙"<<endl;
            }
            if(a=='C'){z
                cout<<"丙"<<endl;
            }
            if(a=='D'){
                cout<<"丁"<<endl;
            }
            return 0;
        }
    }
    cout<<"无"<<endl;
    return 0;
}