#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef struct node{
    struct node* left;
    int data;
    struct node* right;
}nodetype;
nodetype* insert(nodetype *root,int key);
void display(nodetype *root,int key);
int main(){
    vector<int> x;
    nodetype* root=NULL;
    cout<<"Enter total no. of elements"<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        x.push_back(data);
        root = insert(root,data);
    }
    cout<<"Display"<<endl;
    display(root,root->data);
    return 0;
}
nodetype* insert(nodetype *root,int key){
    if(root == NULL){
        nodetype *p = (nodetype *)malloc(sizeof(nodetype));
        (p)->data = key;
        (p)->left = (p)->right = NULL;
        root = p;
        return root;
    }
    else{
        if((root)->data>key){
            (root)->left = insert((root)->left,key);
        }
        else{
            (root)->right = insert((root)->right,key);
        }
    }
    return root;
}
void display(nodetype *root,int key){
    if (root == NULL) 
        return; 
    if(root->data>key){
        cout<<root->data<<" ";
    }
    key=root->data;
    display(root->left,key); 
    display(root->right,key); 
}
