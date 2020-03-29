#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct node{
    struct node* left;
    char alpha;
    int freq;
    struct node* right;
    struct node* next;
}nodetype;
void insertinlist(nodetype **head,int freq,nodetype* p){
    if(*head == NULL || (*head)->freq >= freq){
		p->next = *head;
		*head = p;
	}
    else{
        nodetype *ptr = *head;
        while (ptr->next != NULL && ptr->next->freq < freq)
            ptr = ptr->next;
        p->next = ptr->next;
        ptr->next = p;
    }
}
void display(nodetype *root,string str){ 
    if(root==NULL) 
        return; 
    if(root->alpha != '$') 
        cout<<root->alpha<<": "<<str<<endl; 
    display(root->left, str + "0"); 
    display(root->right, str + "1"); 
} 
int main(){
    nodetype *head=NULL;
    int n;
    cout<<"Enter total no. of alphabets"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){   
        int freq;
        char ch;
        cout<<"Enter the character and its frequency";
        cin>>ch>>freq;
        nodetype *p = (nodetype*)malloc(sizeof(nodetype));
        p->alpha=ch;
        p->freq=freq;
        p->left=p->next=p->right=NULL;
        insertinlist(&head,freq,p);
    }
    nodetype *temp = head,*x,*y;
    while(temp!=NULL){
        cout<<temp->alpha<<" "<<temp->freq<<endl;
        temp = temp->next;
    }

    temp = head;
    while(temp!=NULL ){
        x = temp;
        if(temp->next!=NULL){
            y = temp->next;
            nodetype *root = (nodetype*)malloc(sizeof(nodetype));
            root->left=root->next=root->right=NULL;
            int sum = x->freq + y->freq;
            root->freq = sum;
            root->alpha = '$';
            root->left = x;
            root->right = y;
            insertinlist(&temp,root->freq,root);
            temp = temp->next->next;
        }
        else{
            temp = temp->next;
        }
    }
    cout<<endl;
    temp = head;
    nodetype *ptr;
    while(temp->next!=NULL){
        ptr=temp->next;
        temp = temp->next;
    }
    string res="";
    display(ptr,res);
    return 0;
}