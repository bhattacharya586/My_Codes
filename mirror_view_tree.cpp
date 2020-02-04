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
nodetype * mirror(nodetype *root);
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
    cout<<"Display Before Mirror"<<endl;
    display(root);
    cout<<endl;
    root = mirror(root);
    cout<<"Display After Mirror"<<endl;
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
nodetype* mirror(nodetype *root){
    nodetype *temp;
    if (root == NULL) 
        return root; 
    mirror(root->left); 
    mirror(root->right); 
    temp = root->left;
    root->left = root->right;
    root->right = temp;
    return root;
}
void display(nodetype *root){
    if (root == NULL) 
        return; 
    display(root->left); 
    cout << root->data << " "; 
    display(root->right); 
}