#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct node{
    int data;
    struct node *left;
    struct node* right;
}nodetype;
nodetype *conversion(vector<int> in,vector<int> pre,int strt,int end);
void display(nodetype* root);
nodetype* newnode(int key);
int search(vector<int> x,int strt,int end,int key);
int main()
{
    nodetype *root=NULL;
    vector<int> in = {8,4,10,9,11,2,5,1,6,3,7}, pre = {1,2,4,8,9,10,11,5,3,6,7};
    root = conversion(in,pre,0,in.size()-1);
    display(root);
    return 0;
}
nodetype *conversion(vector<int> in,vector<int> pre,int strt,int end){
    static int preindex = 0;
    if(strt>end){
        return NULL;
    }
    nodetype* nodex = newnode(pre[preindex++]);
    if(strt==end)
        return nodex;
    int inindex = search(in,strt,end,nodex->data);
    nodex->left = conversion(in,pre,strt,inindex-1);
    nodex->right = conversion(in,pre,inindex+1,end);
    return nodex;
}
nodetype* newnode(int key){
    nodetype *p = (nodetype*)malloc(sizeof(nodetype));
    p->data  = key;
    p->left  = NULL;
    p->right = NULL;
    return p;
}
int search(vector<int> x,int strt,int end,int key){
    for(int i=strt;i<end;i++){
        if(x[i]==key){
            return i;
        }
    }
}
void display(nodetype* root){
    if(root!=NULL){
        display(root->left);
        display(root->right);
        cout<<root->data<<" ";
    }
}