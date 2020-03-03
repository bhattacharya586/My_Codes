/*
    BFS
    Name    : Aniruddha Bhattacharya
    Section : D
    Roll No : 06
*/
#include<iostream>
using namespace std;
void swap(int &a,int&b);
void min_heap(int *heap,int now);
int main(){
    int n;
    cout<<"Enter total number of elements"<<endl;
    cin>>n;
    int *heap=new int[n+1];
    for(int i=1;i<=n;i++){
        cout<<"Enter the value at index : "<<i<<endl;
        cin>>heap[i];
    }
    heap[0]=-999;
    for(int i=1;i<=n;i++){
        min_heap(heap,i);
    }

    for(int i=1;i<=n;i++)
        cout<<heap[i]<<" ";
    return 0;
}
void swap(int &a,int&b){
    int temp = a;
    a=b;
    b=temp;
}
void min_heap(int *heap,int now){
    int elem = heap[now];
    cout<<endl<<"Element : "<<elem<<endl;
    while(heap[now/2]>heap[now]){
        swap(heap[now],heap[now/2]);
        now = now/2;
    }
}
