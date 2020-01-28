#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int findings(vector<int> x,int k);
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
    res = findings(x,k);
    if(res==0){
        cout<<"Not Found!!!";
    }
    else{
        cout<<"Found!!!";
    }
    return 0;
}
int findings(vector<int> x,int k){
    for(int i=0;i<x.size();i++){
        if(x[i]==k){
            return 1;
        }
    }
    return 0;
}