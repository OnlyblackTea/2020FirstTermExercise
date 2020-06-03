#include<iostream>
using namespace std;
int a[20];
inline void move(int* array,int n,int m){
    for(int i=n;i>=1;i--){
        array[i+m]=array[i];
    }
    for(int i=1;i<=m;i++){
        array[i]=array[n+i];
        array[n+i]=0;
    }
}
int main(){
    for(int i=1;i<=10;i++){
        cin>>a[i];
    }
    move(a,10,3);
    for(int i=1;i<=10;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;

}