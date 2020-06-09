#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<cmath>
#include<time.h>
#include<windows.h>
#include<memory>
using namespace std;
const int height=20,width=20,border=1;//设置常量，通过修改常量可以直接改变大小
void HideCursor(){//隐藏光标
    CONSOLE_CURSOR_INFO cursor_info = {1,0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
struct Point{
    int x,y;
    Point(int x,int y):x(x),y(y){}
    Point(const Point& obj):x(obj.x),y(obj.y){}
    Point():x(0),y(0){}
};//定义点
class Object{
protected:
    Point plc;
public:
    Point getplace() const {return plc;}
    Point getplace() {return plc;}
    Object(int x,int y):plc(x,y){}
    Object(const Point& obj):plc(obj){}//拷贝构造函数，用于vector的push_back方法
    Object(){}
};//定义基类，包括坐标和移动

class Bullet : public Object{
private:
    string property;//子弹的属性，对应敌人和玩家
    int k;
public:
    Bullet(){}
    Bullet(int x,int y,string property,int k):Object(x,y),property(property),k(k){}
    Bullet(const Bullet& obj):Object(obj.getplace()),property(obj.property),k(obj.k){}
    void move(){
        if(property=="enemy"){
            if(k==0)plc.x++;
            if(k==1){plc.x++;plc.y--;}
            if(k==2){plc.x++;plc.y++;}
        }
        else if(property=="friend")plc.x--;
    }
};

class FriendlyPlane : public Object{
private:
    string property;
public:
    Bullet shoot(){
        Bullet obj(plc.x-1,plc.y,"friend",65535);
        return obj;
    }//返回一个子弹，用来赋值
    void move(char input){
        if(input=='w')plc.x--;//上下左右移动
        else if(input=='a')plc.y--;
        else if(input=='s')plc.x++;
        else if(input=='d')plc.y++;
        if(plc.x<border)plc.x=height;//边界控制
        if(plc.x>height)plc.x=border;
        if(plc.y<border)plc.y=width;
        if(plc.y>height)plc.y=border;
    }
    FriendlyPlane(int x=height,int y=width/2):Object(x,y),property("friend"){}
};//玩家的飞机，可以移动、射击

class EnemyPlane : public Object{
private:
    string property;
public:
    Bullet shoot(){
        srand(time(0));
        Bullet obj(plc.x+1,plc.y,"enemy",rand()%3);
        return obj;
    }
    void move(){
        srand(time(0));
        int tmp=rand()%3;
        if(tmp==0)plc.x++;//随机三个方向移动
        if(tmp==1){plc.x++;plc.y++;}
        if(tmp==2){plc.x++;plc.y--;}
        if(plc.x<border)plc.x=border;//边界控制
        if(plc.y<border)plc.y=border;
        if(plc.y>width)plc.y=width;
    }
    EnemyPlane(int x=border,int y=width/2):Object(x,y),property("enemy"){}
    EnemyPlane(const EnemyPlane& obj):Object(obj.getplace()),property("enemy"){}
};//敌人的飞机，同样可以移动、射击

class MainProgram{
private:
    vector<EnemyPlane> enms;//保存敌人的容器
    vector<Bullet> enmbs;//保存敌人子弹的容器
    vector<Bullet> plysb;//保存玩家子弹的容器
    FriendlyPlane player;//玩家对象
    int score,speed;//分数和速度变量
    vector< vector<char> > G;//地图 char G[30][30]
public:
    bool flag;//游戏失败时为false
    MainProgram():score(0),speed(10),flag(true){//初始化游戏对象，生成地图和玩家
        G.resize(30);
        for(vector< vector<char> >::iterator i=G.begin();i!=G.end();i++){
            i->resize(30,' ');
        }
        G[player.getplace().x][player.getplace().y]='*';
    }
    bool start(){//开始游戏
        system("cls");
        cout<<"按下回车开始游戏"<<endl;
        if(kbhit()){
            int input=getch();
            if(input==13)return true;
        }
        else{
            return false;
        }
    }
    void show(){//输出画面
        system("cls");
        for(vector< vector<char> >::iterator i=G.begin();i!=G.end();i++){
            for(vector<char>::iterator j=i->begin();j!=i->end();j++){
                cout<<*j;//使用cout输出画面，对性能影响较大
            }
            cout<<endl;
        }
        cout<<"SCORE:"<<score<<endl;
    }
    void gameover(){//游戏结束
        flag=0;
        system("cls");
        cout<<"游戏结束！"<<endl;
        getchar();
    }
    void hitEnemy(Point t){//子弹击中敌人的处理方法
        for(vector<EnemyPlane>::iterator i=enms.begin();i!=enms.end();){//搜索被击中的敌人
            if(i->getplace().x==t.x&&i->getplace().y==t.y){
                G[t.x][t.y]=' ';//更改地图
                i=enms.erase(i);//从容器中移除敌人
                score++;//增加分数
            }
            else{
                i++;
            }
        }
    }
    void hitBullet(Point t){//子弹相互碰撞的处理方法，只消除敌人的子弹，不消除玩家的子弹（会造成野指针错误）
        for(vector<Bullet>::iterator i=enmbs.begin();i!=enmbs.end();){//搜索被击中的敌人的子弹
            if(i->getplace().x==t.x&&i->getplace().y==t.y){
                G[t.x][t.y]=' ';//更改地图
                i=enmbs.erase(i);//从容器中移除子弹
            }
            else{
                i++;
            }
        }
    }
    void hitFriend(){//玩家被击中
        score--;
        if(score<0) gameover();
    }
    void updateWithInput(){//与输入有关的更新
        char input;
        if(kbhit()){
            input=getch();
            if(input=='a'||input=='s'||input=='d'||input=='w'){//玩家的移动
                G[player.getplace().x][player.getplace().y]=' ';
                player.move(input);
                if(G[player.getplace().x][player.getplace().y]!=' '&&G[player.getplace().x][player.getplace().y]!='|')//如果玩家移动到敌人或者敌人的子弹上，则造成伤害（敌人不被消灭）
                    hitFriend();
                G[player.getplace().x][player.getplace().y]='*';
            }
            if(input==32){//按下空格之后发射子弹
                plysb.push_back(player.shoot());//向容器中添加子弹
                if(G[plysb.back().getplace().x][plysb.back().getplace().y]=='0'){//如果正好发射在敌人的子弹上
                    hitBullet(plysb.back().getplace());
                }
                else if(G[plysb.back().getplace().x][plysb.back().getplace().y]=='@'){//如果正好发射在敌人上
                    hitEnemy(plysb.back().getplace());
                }
                G[plysb.back().getplace().x][plysb.back().getplace().y]='|';//改变地图
            }
        }
    }
    void updateWithoutInput(){
        for(vector<Bullet>::iterator i=plysb.begin();i!=plysb.end();){//玩家子弹的移动
            G[i->getplace().x][i->getplace().y]=' ';
            i->move();
            if(i->getplace().x==border||i->getplace().y==border||i->getplace().x==height||i->getplace().y==width){//边界控制
                i=plysb.erase(i);
            }
            else{
                if(G[i->getplace().x][i->getplace().y]=='@'){//子弹与敌人碰撞判定
                    hitEnemy(i->getplace());
                    i=plysb.erase(i);
                }
                else{
                    if(G[i->getplace().x][i->getplace().y]=='0')//子弹与敌人子弹碰撞判定
                        hitBullet(i->getplace());
                    G[i->getplace().x][i->getplace().y]='|';
                    i++;
                }
            }
        }
        if(speed==20){//敌人发射子弹以及子弹的移动
            for(vector<Bullet>::iterator i=enmbs.begin();i!=enmbs.end();){//敌人子弹移动
                G[i->getplace().x][i->getplace().y]=' ';
                i->move();
                if(i->getplace().x<=border||i->getplace().y<=border||i->getplace().x>=height||i->getplace().y>=width){
                    i=enmbs.erase(i);
                }
                else{
                    if(G[i->getplace().x][i->getplace().y]=='*'){//如果子弹与玩家碰撞，消除子弹
                        hitFriend();
                        i=enmbs.erase(i);
                    }
                    else{
                        G[i->getplace().x][i->getplace().y]='0';//否则更改地图
                        i++;
                    }
                }
            }
            for(vector<EnemyPlane>::iterator i=enms.begin();i!=enms.end();i++){//敌人发射子弹
                enmbs.push_back(i->shoot());
                G[enmbs.back().getplace().x][enmbs.back().getplace().y]='0';//没有经过处理，直接发射子弹，可以视作刚发射的子弹无判定体积
            }
        }
        if(speed==30){//敌人的移动
            for(vector<EnemyPlane>::iterator i=enms.begin();i!=enms.end();){
                G[i->getplace().x][i->getplace().y]=' ';
                i->move();
                if(i->getplace().x==border||i->getplace().y==border||i->getplace().x==height||i->getplace().y==width){//边界判定，出边界即抹除
                    i=enms.erase(i);
                }
                else{
                    if(G[i->getplace().x][i->getplace().y]=='*'){//敌人撞上玩家，扣分，敌人消失
                        hitFriend();
                        i=enms.erase(i);
                    }
                    else{
                        G[i->getplace().x][i->getplace().y]='@';
                        i++;
                    }
                }
            }
            speed=0;
            srand(time(0));
            enms.push_back(EnemyPlane(1,rand()%(width/2)+1));//在随机坐标生成敌人
            G[enms.back().getplace().x][enms.back().getplace().y]='@';
        }
        speed++;
    }
};

int main(){
    MainProgram game;//初始化游戏
    ios::sync_with_stdio(false);//让游戏性能翻倍的神秘代码
    system("mode con cols=50 lines=40");//设置控制台窗口
    system("chcp 65001");//调整控制台编码为UTF-8
    HideCursor();//隐藏光标
    while(1){
        if(game.start())//开始画面
            break;
    }
    while(game.flag){//当gameover方法执行时，flag变为false，终止循环并且输出结束画面
        game.show();
        game.updateWithInput();
        game.updateWithoutInput();
    }
    return 0;
}