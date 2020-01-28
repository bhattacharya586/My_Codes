#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void quicksort(vector<int> &x,int left,int right);
int partition(vector<int> &x,int left,int right);
int main()
{
    vector<int> x;
    cout<<"Enter total no. of elements"<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        x.push_back(data);
    }
    quicksort(x,0,(x.size())-1);
    for(int i=0;i<x.size();i++){
        cout<<x[i]<<" ";
    }
    return 0;
}
void quicksort(vector<int> &x,int left,int right){
    if(left<=right){
        int p = partition(x,left,right);
        quicksort(x,left,p-1);
        quicksort(x,p+1,right);
    }
}
int partition(vector<int> &x,int left,int right){
    int i = left-1, j = left, pvt = x[right];
    while(j<=right){
        if(pvt>=x[j]){
            i++;
            swap(x[i],x[j]);
        }
        j++;
    }
    return i;
}