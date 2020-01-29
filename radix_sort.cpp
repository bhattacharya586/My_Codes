#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void radixsort(vector<int> &x,int exp);
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
    int max = *max_element(x.begin(),x.end());
    for(int i=1;max/i>0;i=i*10)
        radixsort(x,i);
    for(int i=0;i<x.size();i++){
        cout<<x[i]<<" ";
    }
    return 0;
}
void radixsort(vector<int> &x,int exp){
    vector<int> count(10),output_arr(x.size());
    for(int i=0;i<x.size();i++){
        count[(x[i]/exp)%10]++;
    }
    for(int i=1;i<count.size();i++){
        count[i] = count[i] + count[i-1];
    }
    for(int i=x.size()-1;i>=0;i--){
        output_arr[count[(x[i]/exp)%10]-1] = x[i];
        count[(x[i]/exp)%10]--;
    }
    for(int i=0;i<x.size();i++){
        x[i] = output_arr[i];
    }
}