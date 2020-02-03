#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct node{
    int data;
    struct node* next;
}nodetype;
nodetype* insert(nodetype* tail,int i);
void search(nodetype *head,int data);
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
    int data;
    cout<<"Enter the Key"<<endl;
    cin>>data;
    search(head,data);
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
void search(nodetype *head,int data){
    int count=1;
    if (head== NULL) 
      return; 
    while(head!=NULL){
        if(head->data == data){
            cout<<"Element Found at position: "<<count<<endl;
            return;
        }
        count++;
        head = head->next;
    }
    cout<<"Element not found in the linked list"<<endl;
}
void display(nodetype *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}