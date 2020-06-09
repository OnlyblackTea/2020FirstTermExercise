#include<iostream>
#include<cstdio>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>
#include<cctype>
using namespace std;

struct Text{
    int page;
    int chapter;
    string bookname;
    string content;
    Text(const Text& obj):page(obj.page),chapter(obj.chapter),bookname(obj.bookname),content(obj.content){}
};
vector<Text> lines;
vector<Text> answers;
Text tmp;
//定义基础内容
void inBook(string book,int chapter=0){
    string line;
    ifstream in(book);
    tmp.bookname=book;
    tmp.chapter=chapter;
    tmp.page=1;
    int len=0;
    //初始化
    if(in){
        while(getline(in,line)){
            len=line.length();//获取当前行长度
            if(len>=0&&len<=20){//页码或是章节
                int cnt=0;
                for(int i=0;i<len;i++){
                    if(isdigit(line[i])){//如果是页码
                        cnt*=10;
                        cnt+=line[i]-'0';
                    }
                }
                if(cnt!=0){
                    tmp.page=cnt+1;
                }
                else{
                    transform(line.begin(),line.end(),line.begin(),::toupper);
                }
            }
        }
    }
}

void init(){
    inBook("J.K. Rowling - HP 0 - Harry Potter Prequel.txt",-1);
    inBook("HP2--Harry_Potter_and_the_Chamber_of_Secrets_Book_2_.txt");
    inBook("J.K. Rowling - HP 3 - Harry Potter and the Prisoner of Azkaban.txt");
    inBook("J.K. Rowling - HP 4 - Harry Potter and the Goblet of Fire.txt");
    inBook("J.K. Rowling - HP 6 - Harry Potter and the Half-Blood Prince.txt");
    inBook("HP7--Harry_Potter_and_the_Deathly_Hallows_Book_7_.txt");
    inBook("J.K. Rowling - Quidditch Through the Ages.txt");
    inBook("J.K. Rowling - The Tales of Beedle the Bard.txt");
}

void isearch(string name){

}

int isearch(int id){

}

void out(){

}

bool check(int id){
    int cnt=0;
    for(vector<Text>::iterator i=answers.begin();i!=answers.end();i++)
        cnt++;
    if(id>cnt)return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(false);
    init();
    string name;
    int id;
    cout<<"请输入要查询的人名/地名"<<endl;
    cin>>name;
    isearch(name);
    cout<<"序号       人名/地名       页码       章节       书名"<<endl;
    out();
    cout<<"请输入要查询的序号"<<endl;
    cin>>id;
    while(check(id)){
        cout<<"请求失败，请重新输入"<<endl;
        cin>>id;
    }
    cout<<isearch(id);
    return 0;
}