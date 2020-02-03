#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct node{
    int data;
    struct node* next;
}nodetype;
nodetype* insert(nodetype* tail,int i);
void deletedbyvalue(nodetype **head,int data);
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
    cout<<"Enter the data"<<endl;
    cin>>data;
    nodetype *temp = head;
    deletedbyvalue(&temp,data);
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
void deletedbyvalue(nodetype **head,int data){
    if(*head==NULL){
        return;
    }
    while((*head)->next->data!=data){
        (*head) = (*head)->next;
    }
    nodetype *temp = (*head)->next->next;
    free((*head)->next);
    (*head)->next = temp;
}
void display(nodetype *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}