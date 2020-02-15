#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> arr={15,2,4,8,9,5,10,23};
    int sum=23;
            int nwsum=0;
    for(int i=0;i<arr.size();i++){
        nwsum=arr[i];
        for(int j=i+1;j<arr.size();j++){
            if(nwsum==sum)
            {
                cout<<"I : "<<i<<" J : "<<j-1<<endl;
            }
            if(nwsum>sum)
                break;
            nwsum = nwsum + arr[j];
        }   
    }
    return 0;
}