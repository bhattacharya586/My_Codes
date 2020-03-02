#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef struct graph{
    int dest;
    struct graph *next;
}graphtype;
typedef struct node
{
    int data;
    struct node *next;
}nodetype;
nodetype *front;
nodetype *rear;
void insertgraph(int src,int dst,graphtype **source,int *parent_list);
void display(graphtype *source);
void bfs(graphtype **source,int *visited,int *parent_list,int i);
void shortpath(int *parent_list, int ti); 
void enqueue(int item);
void dequeue();
int main()
{
    int visited[20];
    graphtype *source[20];
    cout<<"Enter how many Source Nodes and Edges"<<endl;
    int s,e;
    cin>>s>>e;
    int t=e;
    int *parent_list = new int[s];
    for(int i=0;i<s;i++){
        source[i]=NULL;
        visited[i] = 0;
        parent_list[i]=i;
    }
    parent_list[0] = 999;
    while(t--){
        cout<<"Enter the Source and Destination Node"<<endl;
        int src,dst;
        cin>>src>>dst;
        insertgraph(src,dst,source,parent_list);
        insertgraph(dst,src,source,parent_list);
    }
    cout<<"Source Nodes\tEdge Nodes"<<endl;
    for(int i=0;i<s;i++){
        cout<<"source["<<i<<"]\t";
        display(source[i]);
    }
    parent_list[0]=0;
    bfs(source,visited,parent_list,0);
    for(int i=0;i<s;i++){
        cout<<parent_list[i]<<" ";
    }
    
    cout<<endl;
    cout<<"Enter dst to evaluate shortest path :"<<endl;
    int ti;
    cin>>ti;
    if(ti>=s){
        cout<<"No node associated with this name"<<endl;
    }
    else{
        cout << "Path is : ";
        shortpath(parent_list, ti);
    }
    return 0;
}
void enqueue(int item){  
    nodetype *p;  
    p = (nodetype *)malloc(sizeof(nodetype));
    p -> data = item;  
    if(front == NULL)  
    {  
        front = p;  
        rear = p;   
        front -> next = NULL;  
        rear -> next = NULL;  
    }  
    else   
    {  
        rear -> next = p;  
        rear = p;  
        rear->next = NULL;  
    }   
}     
void dequeue(){
    nodetype *p;
    if(front == NULL)  
    {  
        printf("\nUNDERFLOW\n");  
        return;  
    }  
    else   
    {  
        p = front;  
        front = front -> next;  
        free(p);  
    }  
}  
int front_l(){
    return front->data;
}
void shortpath(int *parent_list,int ti){
    while (parent_list[ti]!=ti || ti==0)
    {
        cout<<ti<<" ";
        if(ti==0)
            break;
        ti = parent_list[ti];
    }
}
void insertgraph(int src,int dst,graphtype **source,int *parent_list){
    graphtype *p = (graphtype*)malloc(sizeof(graphtype));
    p->dest = dst;
    p->next = NULL;
    if((source[src])==NULL){
        source[src] = p;
    }
    else{
        graphtype *t = (graphtype*)malloc(sizeof(graphtype));
        t = source[src];
        p->next = t;
        source[src] = p;
    }
}
void display(graphtype *source){
    while(source!=NULL){
        cout<<source->dest<<" ";
        source = source->next;
    }
    cout<<endl;
}
void bfs(graphtype **source,int *visited,int *parent_list,int i){
    graphtype *p;
    visited[i] = 1;
    enqueue(i);
    while (front!=NULL && rear!=NULL)
    {
        i = front_l();
        cout<<"Node Processed is : "<<i<<endl;
        dequeue();
        p = source[i];
        while(p!=NULL){
            if(!visited[p->dest]){
                visited[p->dest]=1;
                if (parent_list[p->dest] == p->dest)
                {
                    parent_list[p->dest] = i;
                    enqueue(p->dest);
                }
            }
            p=p->next;
        }
    }
}