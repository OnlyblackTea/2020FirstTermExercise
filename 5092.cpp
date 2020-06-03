#include<iostream>
using namespace std;
int main(){
    int loseA=0,loseB=0,N;
    cin>>N;
    int a,b,c,d;
    bool flag = 0;
    for(int i=1;i<=N;i++){
        cin>>a>>b>>c>>d;
        if(!flag){
            if(b==d){
                if(b==a+c){
                    loseA++;
                    loseB++;
                }
            }
            else{
                if(b==a+c){
                    loseB++;
                    flag = 1;
                }
                if(d==a+c){
                    loseA++;
                    flag = 1;
                }
            }
        }
    }
    cout<<loseA<<" "<<loseB<<endl;
    return 0;
}