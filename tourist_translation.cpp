#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    string refstr;
    int t=1;
    cin>>t;
    cin.ignore();
    getline(cin,refstr);
    while(t--){
        string ques;
        getline(cin,ques);
        for(int i=0;i<ques.length();i++){
            if(ques[i]=='_'){
                cout<<" ";
            }
            if(islower(ques[i])){
                cout<<refstr[(int)ques[i]-97];
            }
            else if(isupper(ques[i])){
                char to = (refstr[(int)ques[i]-65]);
                cout<<(char)toupper(to);
            }
            if(ques[i]=='?' || ques[i]=='.' || ques[i]==','||ques[i]=='!'){
                cout<<ques[i];
            }
        }
        cout<<endl;
    }
    return 0;
}