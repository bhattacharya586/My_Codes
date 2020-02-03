#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct node{
    int data;
    struct node* next;
}nodetype;
nodetype* insert(nodetype* tail,int i);
void display(nodetype *tail);
int main(){
    // g++ singly_ll_insert.cpp -std=c++11
    vector<int> x = {1,2,3,4,5};
    nodetype *head=NULL,*tail=NULL;
    for(auto i:x){
        tail = insert(tail,i);
        if(head==NULL)
            head=tail;   
    }
    cout<<"Final"<<endl;
    display(head);
    return 0;
}
nodetype* insert(nodetype* tail,int i){
    nodetype *p = (nodetype*)malloc(sizeof(nodetype));
    p->data = i;
    p->next = NULL;
    if(tail==NULL){
        tail = p;
    }
    else{
        tail->next = p;
        tail = tail->next;
    }
    return tail;
}
void display(nodetype *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}