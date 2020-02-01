#include<iostream>
using namespace std;
int main(){
    long long t,t1,t2,t3,t4;
    cin>>t;
    while(t--){
        cin>>t1>>t2>>t3>>t4;
        cout<<(double)((double)t1/(double)(t1+t2))<<endl;
    }
    return 0;
}