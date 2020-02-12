#include<iostream>
#define MAX 100
using namespace std;
typedef struct graph{
    int dest;
    struct graph *next;
}graphtype;
graphtype *insertgraph(int dst, graphtype *source);
void display(graphtype *source);
int main()
{
    graphtype *source[20] = {NULL};
    cout<<"Enter how many Source Nodes and Edges (Start from 1)"<<endl;
    int s,e;
    cin>>s>>e;

    int t=e;
    while(t--){
        cout<<"Enter the Source and Destination Node"<<endl;
        int src,dst;
        cin>>src>>dst;
        source[src] = insertgraph(dst, source[src]);
    }
    cout<<"Source Nodes\tEdge Nodes"<<endl;
    for(int i=1;i<=s;i++){
        cout<<"source["<<i<<"]\t";
        display(source[i]);
    }
    return 0;
}
graphtype* insertgraph(int dst,graphtype *source){
    graphtype *p = (graphtype*)malloc(sizeof(graphtype));
    p->dest = dst;
    p->next = NULL;
    if((source)==NULL){
        source = p;
    }
    else{
        graphtype *t = (graphtype*)malloc(sizeof(graphtype));
        t = source;
        p->next = t;
        source = p;
    }
    return source;
}
void display(graphtype *source){
    while(source!=NULL){
        cout<<source->dest<<" ";
        source = source->next;
    }
    cout<<endl;
}