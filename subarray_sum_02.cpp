#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> arr={15,2,4,8,9,5,10,23};
    int sum=23,start=0;
    int crsum=arr[0];
    for(int i=1;i<arr.size();i++){
       while(crsum>sum && start<i-1){
           crsum = crsum - arr[start];
           start++;
       }
       if(crsum == sum)
        cout<<"Range from "<<start<<" to "<<i-1<<endl;
       crsum = crsum + arr[i]; 
    }
    return 0;
}