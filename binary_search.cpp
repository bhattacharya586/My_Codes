#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int binarysearch(vector<int> x,int left,int right,int key);
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
    int k,res;
    cout<<"Enter the nos. to find in the list"<<endl;
    cin>>k;
    res = binarysearch(x,0,n-1,k);
    if(res==1){
        cout<<"Found!!!";
    }
    else{
        cout<<"Not Found!!!";
    }
    return 0;
}
int binarysearch(vector<int> x,int left,int right,int key){
    if(left<=right){
        // Question arrised why we have done less than equal to
        int mid = (left+right)/2;
        if(x[mid]==key)
            return 1;
        // Why we have done mid-1 and mid+1
        else if(x[mid]>key)
            return binarysearch(x,left,mid-1,key);
        else
            return binarysearch(x,mid+1,right,key);
    }
    return 0;
}