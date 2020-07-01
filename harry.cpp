#include<iostream>
#include<cstdio>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>
#include<cctype>
#include<iomanip>
using namespace std;

struct Text{
    int page;
    int chapter;
    string bookname;
    string content;
    Text(const Text& obj):page(obj.page),chapter(obj.chapter),bookname(obj.bookname),content(obj.content){}
    Text(){}
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
                        cnt+=line[i]-'0';//计算页码
                    }
                    else{
                        break;//数字不连续不算数
                    }
                }
                if(cnt!=0){
                    tmp.page=cnt+1;
                }
                else{
                    transform(line.begin(),line.end(),line.begin(),::toupper);
                    if(line.substr(0,7)=="CHAPTER"){
                        tmp.chapter++;//无需读取 直接++
                    }
                }
            }
            else{
                tmp.content=line;
                lines.push_back(tmp);
            }
        }
    }
    else{
        cout<<"数据读入失败:"<<book<<endl;
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
    string::size_type siz;
    for(vector<Text>::iterator i=lines.begin();i!=lines.end();i++){
        siz=i->content.find(name);
        if(siz!=string::npos){
            answers.push_back(*i);//将本行作为答案
        }
    }
}

string isearch(int id){
    int cnt=0;
    for(vector<Text>::iterator i=answers.begin();i!=answers.end();i++){
        cnt++;
        if(cnt==id){
            return i->content;
        }
    }
}

void out(string name){
    int cnt=0;
    for(vector<Text>::iterator i=answers.begin();i!=answers.end();i++){
        cnt++;
        cout<<cnt<<setw(7)<<name<<setw(8)<<i->page<<setw(8)<<i->chapter<<setw(8)<<i->bookname<<endl;
    }
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
    system("chcp 65001");//调整控制台编码为UTF-8
    init();
    string name;
    int id;
    cout<<"请输入要查询的人名/地名"<<endl;
    cin>>name;
    isearch(name);
    cout<<"序号"<<setw(7)<<"人名/地名"<<setw(8)<<"页码"<<setw(8)<<"章节"<<setw(8)<<"书名"<<endl;
    out(name);
    cout<<"请输入要查询的序号"<<endl;
    cin>>id;
    while(check(id)){
        cout<<"请求失败，请重新输入"<<endl;
        cin>>id;
    }
    cout<<isearch(id);
    return 0;
}