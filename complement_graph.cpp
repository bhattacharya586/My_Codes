#include<iostream>
#define MAX 100
using namespace std;
typedef struct graph{
    int dest;
    struct graph *next;
}graphtype;
void getlinks(graphtype *source,int *maker);
void insertgraph(int src, int dst, graphtype **source);
void display(graphtype *source);
int main()
{
    cout<<"Enter how many Source Nodes and Edges (Start from 0)"<<endl;
    int s,e;
    cin>>s>>e;
    graphtype *source[20] = {NULL};
    int maker[100];
    int t=e;
    while(t--){
        cout<<"Enter the Source and Destination Node"<<endl;
        int src,dst;
        cin>>src>>dst;
        insertgraph(src,dst, source);
        insertgraph(dst,src, source);
    }
    cout<<"Source Nodes\tEdge Nodes"<<endl;
    for(int i=0;i<s;i++){
        cout<<"source["<<i<<"]\t";
        display(source[i]);
    }

    for(int i=0;i<s;i++){
        for (int j = 0; j < s; j++)
            maker[j] = j;
        getlinks(source[i],maker);
        source[i]=NULL;
        for (int j = 0; j < s; j++)
            if(maker[j]!=-1 && i!=maker[j])
                insertgraph(i, maker[j], source);
    }
    
    cout<<"Complemented Graph"<<endl;
    cout<<"Source Nodes\tEdge Nodes"<<endl;
    for(int i=0;i<s;i++){
        cout<<"source["<<i<<"]\t";
        display(source[i]);
    }
    return 0;
}

void getlinks(graphtype *source,int *maker){
    while(source!=NULL){
        maker[source->dest] = -1;
        source = source->next;
    }
}
void insertgraph(int src, int dst, graphtype **source)
{
    graphtype *p = (graphtype *)malloc(sizeof(graphtype));
    p->dest = dst;
    p->next = NULL;
    if ((source[src]) == NULL)
    {
        source[src] = p;
    }
    else
    {
        graphtype *t = (graphtype *)malloc(sizeof(graphtype));
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