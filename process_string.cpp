#include<iostream>
using namespace std;
int main(){
    int t;
    string s;
    cin>>t;
    cin.ignore();
    int count=0;
    while(t--){
        s="";
        count=0;
        getline(cin,s);
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])==1){
                count = count + (int)(s[i])-48;
            }
        }
        cout<<count<<endl;
    }
    
    return 0;
}