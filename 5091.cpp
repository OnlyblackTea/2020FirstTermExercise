#include<iostream>
#include<cstring>
using namespace std;

class MyStack{
private:
    int m_array[10];
    int m_size;
public:
    MyStack():m_size(0){memset(m_array,0,sizeof(m_array));};
    void push(int num){m_array[m_size++]=num;}
    int pop(){if(m_size!=0){return m_array[--m_size];}}
    void print(){cout<<"( ";for(int i=0;i<m_size;i++){cout<<m_array[i]<<" ";}cout<<")";}
};

int main(){
    char order;
    int num;
    MyStack* S = new MyStack;
    while(cin>>order){
        if(order=='i'){
            cin>>num;
            S->push(num);
        }
        if(order=='o'){
            S->pop();
        }
        if(order=='s'){
            S->print();
            return 0;
        }
    }
}