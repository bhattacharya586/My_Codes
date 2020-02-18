#include<iostream>
#include<stdlib.h>
#define SZ 100
using namespace std;
typedef struct graph{
    int dest;
    struct graph *next;
}graphtype;
int unionadd(int parent,int child,int *parent_list);
void insertgraph(int src,int dst,graphtype **source,int *parent_list);
void display(graphtype *source);
int find(int *parent_list,int a);
int main(){
    int nodes,edges,a,b;
    cout<<"Enter total no. of nodes and edges"<<endl;
    cin>>nodes>>edges;
    int *parent_list = new int[nodes];
    graphtype *source[SZ];
    for(int i=0;i<nodes;i++){
        parent_list[i]=i;
        source[i] = NULL;
    }
    int t=edges;
    while(t--){
        cout<<"Enter tobeparent and target nodes"<<endl;
        int src,dst;
        cin>>src>>dst;
        insertgraph(src,dst,source,parent_list);
    }
    cout<<"Source Nodes\tEdge Nodes"<<endl;
    
    for(int i=0;i<nodes;i++){
        cout<<"source["<<i<<"]\t";
        display(source[i]);
    }
    for(int i=0;i<nodes;i++){
        cout<<"i : "<<i<<" Parent at i : "<<parent_list[i]<<endl;
    }
    return 0;
}

int unionadd(int parent,int child,int *parent_list){
    int pp = find(parent_list,parent);
    int pc = find(parent_list,child);
    if(pp==pc){
        return -1;
    }
    else{
        parent_list[child]=parent;
        return 1;
    }
}
void insertgraph(int src,int dst,graphtype **source,int *parent_list){
    graphtype *p = (graphtype*)malloc(sizeof(graphtype));
    p->dest = dst;
    p->next = NULL;
    int res = unionadd(src, dst, parent_list);
    if(res==-1){
        cout<<"Impossible Move"<<endl;
        return;
    }
    else{
        
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
    
}
void display(graphtype *source){
    while(source!=NULL){
        printf("%d ",source->dest);
        source = source->next;
    }
    printf("\n");
}
int find(int *parent_list,int a){
    int t=a;
    while(parent_list[t]!=t){
        t = parent_list[t];
    }
    return parent_list[t];
}