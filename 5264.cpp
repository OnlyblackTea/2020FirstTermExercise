#include<iostream>
using namespace std;
int g[10][10];
int main(){
    int t;
    cin>>t;
    while(t--){
        for(int i=1;i<=5;i++){
            for(int j=1;j<=6;j++){
                cin>>g[i][j];
            }
        }
    }
}