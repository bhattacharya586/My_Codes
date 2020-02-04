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
nodetype* deleted(nodetype *root,int key);
void display(nodetype *root);
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
    cout<<"Display Before Delete"<<endl;
    display(root);
    cout<<endl;
    root = deleted(root,20);
    cout<<"Display After Delete"<<endl;
    display(root);
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
}
nodetype* deleted(nodetype *root,int key){
    if(root==NULL)
        return root;
    else{
        if((root)->data>key)
            (root)->left = deleted((root)->left,key);
        else if((root)->data<key){
            (root)->right = deleted((root)->right,key);
        }
        else{
            if (root->left == NULL){ 
                struct node *temp = root->right; 
                free(root); 
                return temp; 
            } 
            else if (root->right == NULL){ 
                struct node *temp = root->left; 
                free(root); 
                return temp; 
            } 
            struct node* temp = root->right;
            while(temp && temp->left!=NULL){
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = deleted(root->right, temp->data); 
        }
    }
    return root;
}
void display(nodetype *root){
    if (root == NULL) 
        return; 
    display(root->left); 
    cout << root->data << " "; 
    display(root->right); 
}