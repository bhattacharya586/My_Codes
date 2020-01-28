#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void mergesort(vector<int> &x,int left,int right);
void merge(vector<int> &x,int left,int right,int mid);
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
    mergesort(x,0,n-1);
    for(int i=0;i<n;i++){
        cout<<x[i]<<" ";
    }
    return 0;
}
void mergesort(vector<int> &x,int left,int right){
    if(left<right){
        int mid = left+(right-left)/2;
        mergesort(x,left,mid);
        mergesort(x,mid+1,right);
        merge(x,left,right,mid);
    }
}
void merge(vector<int> &x,int left,int right,int mid){
    int s1= mid-left+1;
    int s2= right-mid;
    int Left[s1],Right[s2];

    for(int i=0;i<s1;i++){
        Left[i]=x[left+i];
    }
    for(int j=0;j<s2;j++){
        Right[j]=x[mid+1+j];
    }

    int i=0,k=left;
    int j=0;
    while(i<s1 && j<s2){
        if(Left[i]<=Right[j]){
            x[k]=Left[i++];
        }
        else{
            x[k]=Right[j++];
        }
        k++;
    }
    while(i<s1){
        x[k++]=Left[i++];
    }
    while(j<s2){
        x[k++]=Right[j++];
    }
}