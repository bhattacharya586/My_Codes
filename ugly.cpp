#include<iostream>
#include<algorithm>
using namespace std;
int generateugly(int n);
int main(){
    int n = 100;
    int ug = generateugly(n);
    cout<<n<<"th Value is "<<ug;
    return 0;
}
int generateugly(int n){
    int ugly[n];
    int i2=0,i3=0,i5=0;
    int nm2=2,nm3=3,nm5=5;
    int nxt=1;
    ugly[0]=1;
    for(int i=1;i<n;i++){
        nxt = min(nm2,min(nm3,nm5));
        ugly[i]=nxt;
        if(nxt==nm2){
            i2=i2+1;
            nm2=ugly[i2]*2;
        } 
        if(nxt==nm3){
            i3=i3+1;
            nm3=ugly[i3]*3;
        } 
        if(nxt==nm5){
            i5=i5+1;
            nm5=ugly[i5]*5;
        } 
    }
    return nxt;
}