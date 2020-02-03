#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct node{
    int data;
    struct node* next;
}nodetype;
nodetype* insert(nodetype* tail,int i);
void deletedbypos(nodetype **head,int data);
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
    int position;
    cout<<"Enter the position"<<endl;
    cin>>position;
    nodetype *temp = head;
    deletedbypos(&head,position);
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
void deletedbypos(nodetype **head_ref,int position){
    if (*head_ref == NULL) 
      return; 
    nodetype *temp = *head_ref; 
    if (position == 0) 
    { 
        *head_ref = temp->next;  
        free(temp);              
        return; 
    }
    for (int i=0; temp!=NULL && i<position-1; i++) 
         temp = temp->next; 
    if (temp == NULL || temp->next == NULL) 
         return;  
    nodetype *next = temp->next->next;  
    free(temp->next);
    temp->next = next;
}
void display(nodetype *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}