#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int n,m,cnt=0;
struct Point{
    int x,y;
    Point():x(0),y(0){}
    Point(int x,int y):x(x),y(y){}
};
char G[200][200];
bool flg[200][200];
queue<Point> bfs;
using namespace std;
int main(){
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>G[i][j];
            if(G[i][j]=='@'){
                bfs.push(Point(i,j));
                flg[i][j]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        flg[i][0]=1;
        flg[i][m+1]=1;
    }
    for(int i=1;i<=m;i++){
        flg[0][i]=1;
        flg[n+1][i]=1;
    }
    while(!bfs.empty()){
        Point tmp=bfs.front();
        bfs.pop();
        cnt++;
        if(G[tmp.x+1][tmp.y]=='.'&&flg[tmp.x+1][tmp.y]!=1){
            bfs.push(Point(tmp.x+1,tmp.y));
            flg[tmp.x+1][tmp.y]=1;
        }
        if(G[tmp.x-1][tmp.y]=='.'&&flg[tmp.x-1][tmp.y]!=1){
            bfs.push(Point(tmp.x-1,tmp.y));
            flg[tmp.x-1][tmp.y]=1;
        }
        if(G[tmp.x][tmp.y+1]=='.'&&flg[tmp.x][tmp.y+1]!=1){
            bfs.push(Point(tmp.x,tmp.y+1));
            flg[tmp.x][tmp.y+1]=1;
        }
        if(G[tmp.x][tmp.y-1]=='.'&&flg[tmp.x][tmp.y-1]!=1){
            bfs.push(Point(tmp.x,tmp.y-1));
            flg[tmp.x][tmp.y-1]=1;
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<G[i][j];
        }
        cout<<endl;
    }*/
    cout<<cnt<<endl;
    return 0;
}