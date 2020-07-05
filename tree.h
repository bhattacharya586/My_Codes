#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}nodetype;
class Tree{
    public:
        nodetype* insertion(nodetype *root, int key) {
            if(root == NULL){
                nodetype *p = (nodetype *)malloc(sizeof(nodetype));
                (p)->data = key;
                (p)->left = (p)->right = NULL;
                root = p;
                return root;
            }
            else{
                if((root)->data>key){
                    (root)->left = insertion((root)->left,key);
                }
                else{
                    (root)->right = insertion((root)->right,key);
                }
            }
            return root;
        }
        nodetype* deletion(nodetype *root,int key)  {
            if(root==NULL)
                return root;
            else{
                if((root)->data>key)
                    (root)->left = deletion((root)->left,key);
                else if((root)->data<key){
                    (root)->right = deletion((root)->right,key);
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
                    root->right = deletion(root->right, temp->data); 
                }
            }
            return root;
        }
        void inorderT(nodetype *root)  {
            if(root!=NULL){
                inorderT(root->left);
                cout<<root->data<<" ";
                inorderT(root->right);
            }
        }
        void preorderT(nodetype *root) {
            if(root!=NULL){
                cout<<root->data<<" ";
                preorderT(root->left);
                preorderT(root->right);
            }
        }
        void postorderT(nodetype *root){
            if(root!=NULL){
                postorderT(root->left);
                postorderT(root->right);
                cout<<root->data<<" ";
            }
        }
        void levelordT(nodetype *root) {
            if(root==NULL) return;
            queue<nodetype *> q;
            q.push(root);
            while(q.empty()!=true){
                nodetype *p = q.front();
                cout << p->data << " "; 
                q.pop(); 
                if (p->left != NULL) 
                    q.push(p->left); 

                if (p->right != NULL) 
                    q.push(p->right); 
            }
        }
        void revlevelT(nodetype *root) {
            stack <node *> S; 
            queue <node *> Q; 
            Q.push(root); 
            while (Q.empty() == false) 
            {
                root = Q.front(); 
                Q.pop(); 
                S.push(root); 

                if (root->right) 
                    Q.push(root->right); 

                if (root->left) 
                    Q.push(root->left); 
            } 
        
            while (S.empty() == false) 
            { 
                root = S.top(); 
                cout << root->data << " "; 
                S.pop(); 
            } 
        }
        int searchV(nodetype *root, int key)   {
            if (root == NULL) 
                return false; 
        
            if (root->data == key) 
                return true; 
        
            bool res1 = searchV(root->left, key); 
        
            if(res1) return true;

            bool res2 = searchV(root->right, key); 
        
            return res2; 
        }
        int heightT(nodetype *root)   {
            if (root == NULL)  
                return 0;  
            else
            {  
                int lDepth = heightT(root->left);  
                int rDepth = heightT(root->right);  
            
                if (lDepth > rDepth)  
                    return(lDepth + 1);  
                else return(rDepth + 1);  
            }  
        }
        int diametT(nodetype *root, int *height)  {
            int lh = 0, rh = 0;
            int ldiameter = 0, rdiameter = 0; 
            
            if (root == NULL) 
            { 
                *height = 0; 
                return 0;
            } 
            
            ldiameter = diametT(root->left, &lh); 
            rdiameter = diametT(root->right, &rh); 
            
            *height = max(lh, rh) + 1; 
            
            return max(lh + rh + 1, max(ldiameter, rdiameter)); 
        }
        void mirrorT(nodetype *root)  {
            if (root == NULL)  
                return;  
            else
            { 
                nodetype* temp; 
                
                mirrorT(root->left); 
                mirrorT(root->right); 
            
                temp        = root->left; 
                root->left  = root->right; 
                root->right = temp; 
            } 
        }
        int balanceT(node* root, int* height) {
            int lh = 0, rh = 0;
            int l = 0, r = 0; 
        
            if (root == NULL) { 
                *height = 0; 
                return 1; 
            }
            l = balanceT(root->left, &lh); 
            r = balanceT(root->right, &rh); 
        
            *height = (lh > rh ? lh : rh) + 1; 
        
            if (abs(lh -rh) >= 2) 
                return 0; 
        
            else
                return l && r;
        }
        int minValuT(nodetype *root) {
            if (root == NULL) 
                return INT_MAX;
            int res = root->data; 
            int lres = minValuT(root->left); 
            int rres = minValuT(root->right); 
            if (lres < res) 
                res = lres; 
            if (rres < res) 
                res = rres; 
            return res; 
        }
        int maxValuT(nodetype *root) {
            if (root == NULL) 
                return INT_MIN;
            int res = root->data; 
            int lres = maxValuT(root->left); 
            int rres = maxValuT(root->right); 
            if (lres > res) 
                res = lres; 
            if (rres > res) 
                res = rres; 
            return res; 
        }
    
};
