#include<iostream>
using namespace std;

class Fract {
    int num,den;
public:
    Fract(int a=0,int b=1):num(a),den(b){};
    int gcd(int m,int n){
        if(m<n){
            int t=m;
            m=n;
            n=t;
        }
        if(n==0){
            return m;
        }
        else{
            return gcd(n,m%n);
        }        
    }
    int ged(int m,int n){
        return m*n/gcd(m,n);
    }
    Fract add (Fract f){
        int lcm=ged(den,f.den);
        num*=lcm/den;
        f.num*=lcm/f.den;
        num+=f.num;
        den=lcm;
        num/=gcd(num,den);
        den/=gcd(num,den);
        return *this;
    }
    void show(){
        cout<<num<<"/"<<den<<endl;
    }
};

int main(){
    int a1,b1,a2,b2;
    cin>>a1>>b1>>a2>>b2;
    Fract *fl1,*fl2;
    fl1 = new Fract(a1,b1);
    fl2 = new Fract(a2,b2);
    fl1->add(*fl2).show();
    return 0;
}