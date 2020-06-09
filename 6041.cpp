#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int a[1000010];
int b[1000010];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    b[1]=0;
    for(int i=2;i<=n;i++){
        b[i]=a[i]-a[i-1];
    }
    /*printf("A[] is \n");
    for(int i=1;i<=n;i++){
        printf("%d ",a[i]);
    }
    printf("\nB[] is \n");
    for(int i=1;i<=n;i++){
        printf("%d ",b[i]);
    }*/
    int cnt,i=n;
    for(cnt=0;cnt<m&&i>=1;i--){
        cnt+=b[i]*(n-i+1);
        //printf("cnt:%d i:%d\n",cnt,i);
    }
    printf("%.0lf\n",a[i]+ceil((cnt-m)/(n-i)));
    return 0;
}