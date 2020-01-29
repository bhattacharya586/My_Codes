#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void countsort(vector<int> x);
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
    countsort(x);
    return 0;
}
void countsort(vector<int> x){
    int max_v = *max_element(x.begin(),x.end());
    int min_v = *min_element(x.begin(),x.end());
    int range = max_v-min_v+1;
    vector<int> count(range),output_arr(x.size());
    for(int i=0;i<x.size();i++){
        count[x[i]-min_v]++;
    }
    for(int i=1;i<count.size();i++){
        count[i] = count[i] + count[i-1];
    }
    for(int i=x.size()-1;i>=0;i--){
        output_arr[count[x[i]-min_v]-1] = x[i];
        count[x[i]-min_v]--;
    }
    for(int i=0;i<x.size();i++){
        cout<<output_arr[i]<<" ";
    }
}