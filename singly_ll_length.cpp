#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct node{
    int data;
    struct node* next;
}nodetype;
nodetype* insert(nodetype* tail,int i);
int length_p(nodetype *head);
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
    cout<<"Before Delete"<<endl;
    display(head);
    int length = length_p(head);
    cout<<length;
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
int length_p(nodetype *head){
    int count=0;
    if (head== NULL) 
      return count;
    count++; 
    return count + length_p(head->next);
}
void display(nodetype *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}