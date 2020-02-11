#include<iostream>
#include<algorithm>
using namespace std;
int fibonacci(int n);
int main(){
    int n=9;
    int res = fibonacci(n);
    cout<<n<<"th element of Fibonacci Series is "<<res;
    return 0;
}
int fibonacci(int n){
    int temp[n+2];
    temp[0]=0;
    temp[1]=1;
    for(int i=2;i<=n;i++){
        temp[i] = temp[i-1]+temp[i-2];
    }
    return temp[n];
}