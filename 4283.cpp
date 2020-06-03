#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
node* CreateList();
void PrintList(node*);
node* head = NULL;
node* CreateList(){
    node *s, *p=NULL;
    s = new node;
    //  cout  <<  "请输入一个整数值作为新结点的数据信息,输入0时建立链表结束"  <<  endl;
    //  cout  <<  "第"  <<  n  +  1  <<  "个结点"  <<  endl;
    cin>>s->data;
    head = NULL;
    if(s->data == 0){
        //cout  <<  "您建立的空链表"  <<  endl;
        delete s;
    }
    else{
        while(s->data != 0){
            if(head == NULL)head=s;
            else p->next=s;
            p=s;
            s=new node;
            cin>>s->data;
        }
        p->next=NULL;
        delete s;
    }
    return head;
}
void PrintList(node* head){
    node* p = head;
    int i = 1;
    if(head!=NULL){
        do{
            cout<<p->data<<endl;
            p=p->next;
        }while(p!=NULL);
    }
    else{
        cout<<"空链表！"<<endl;
    }
    //cout<<"链表中共有"<<n<<"个节点"<<endl;
}
node* RGetKthNode(node* pHead,unsigned int k){
    int n=1;
    if(pHead==NULL)return NULL;//空链表
    for(node* p=pHead;p->next!=NULL;n++,p=p->next);//确定链表长度
    node* p=pHead;
    for(int i=1;i<n-k+1;i++,p=p->next);
    return p;
}
int main(){
    node *head = CreateList();
    int k;cin>>k;
    node *find = RGetKthNode(head, k);
    if(find == NULL)cout<<"无效";
    else cout<<find->data;
    return 0;
}