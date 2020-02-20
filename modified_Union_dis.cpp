#include <iostream>
#include <stdlib.h>
#define SZ 100
using namespace std;
typedef struct graph{
    int dest;
    struct graph *next;
}graphtype;
typedef struct node{
    int src;
    int dst;
    int weight;
    struct node *next;
}nodetype;
void insertinlist(nodetype **head,int src,int dst,int weight){
    nodetype *p = (nodetype*)malloc(sizeof(nodetype));
    p->src = src;
    p->dst = dst;
    p->weight = weight;
    p->next = NULL;
    if (*head == NULL || (*head)->weight >= weight)
	{
		p->next = *head;
		*head = p;
	}
    else{
        nodetype *current = *head;
        while (current->next != NULL && current->next->weight < weight)
            current = current->next;
        p->next = current->next;
        current->next = p;
    }
}
int find(int *parent_list,int a){
    int t=a;
    while(parent_list[t]!=t){
        t = parent_list[t];
    }
    return parent_list[t];
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
int main()
{
    nodetype *head=NULL;
    printf("Enter how many Source Nodes and Edges");
    int s,e;
    cin>>s>>e;
    int t=e;
    int *parent_list = new int[s];
    graphtype *source[SZ];
    for(int i=0;i<s;i++){
        parent_list[i]=i;
        source[i] = NULL;
    }
    while(t--){
        printf("\nEnter the Source, Destination Node and Weight");
        int src,dst,weight;
        cin>>src>>dst>>weight;
        insertinlist(&head, src, dst, weight);
    }
    nodetype *temp = head;
    while(temp!=NULL){
        insertgraph(temp->src,temp->dst,source,parent_list);
        temp=temp->next;
    }
    cout<<"Source Nodes\tEdge Nodes"<<endl;
    
    for(int i=0;i<s;i++){
        cout<<"source["<<i<<"]\t";
        display(source[i]);
    }
    for(int i=0;i<s;i++){
        cout<<"i : "<<i<<" Parent at i : "<<parent_list[i]<<endl;
    }
    return 0;
}
