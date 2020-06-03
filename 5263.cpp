#include<iostream>
using namespace std;
int a[200];
int b[200];
int main(){
    int T;
    cin>>T;
    while(T--){
        int n,m,cnt=0,maxn=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        if(m>=n){
            cout<<"100"<<endl;
            continue;
        }
        b[1]=a[1]-1;
        for(int i=2;i<=n;i++){
            b[i]=a[i]-a[i-1]-1;
        }
        b[n+1]=100-a[n];
        for(int i=1;i<=n-m+1;i++){
            cnt=0;
            for(int j=i;j<=i+m;j++){
                cnt+=b[j]+1;
            }
            maxn=max(maxn,cnt-1);
        }
        cout<<maxn<<endl;
    }
    return 0;
}