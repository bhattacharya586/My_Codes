#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct graph{
    int dest;
    struct graph *next;
}graphtype;
void insertgraph(int src,int dst,graphtype **source);
void display(graphtype *source);
void dfa(graphtype **source,int *visited,int i);
int main(){
    int visited[20];
    graphtype *source[20];
    cout<<"Enter how many Source Nodes and Edges (Start from 1)"<<endl;
    int s,e;
    cin>>s>>e;
    int t=e;
    for(int i=0;i<s;i++){
        source[i]=NULL;
        visited[i]=0;
    }
    while(t--){
        cout<<"Enter the Source and Destination Node"<<endl;
        int src,dst;
        cin>>src>>dst;
        insertgraph(src,dst,source);
    }
    cout<<"Source Nodes\tEdge Nodes"<<endl;
    for(int i=0;i<s;i++){
        cout<<"source["<<i<<"]\t";
        display(source[i]);
    }
    cout<<endl;
    int i=0;
    dfa(source,visited,i);
    return 0;
}
void insertgraph(int src,int dst,graphtype **source){
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
void dfa(graphtype **source,int *visited,int i){
    graphtype *p;
    if(!visited[i]){
        visited[i]=1;
        cout<<"Node Processed is "<<i<<endl;
    }
    int j;
    p=source[i];
    while(p!=NULL){
        j = p->dest;
        if (!visited[j])
        {
            dfa(source,visited,j);
        }
        p=p->next;
    }
}