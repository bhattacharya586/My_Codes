#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    map<int,vector<int> > m;
    map<int, vector<int> > :: iterator it;
    vector<int> n;
    for (auto i = 0; i < 10; i++)
    {   
        n.push_back(i);
    }
    m[-2] = n;
    for(auto i = m.begin();i!=m.end();i++){
        cout<<"Key : "<<i->first<<endl<<"Vector : ";
        for (auto j = 0; j < i->second.size(); j++)
        {
            cout<<i->second[j]<<" ";
        }
    }
    cout<<"Vector"<<endl;
    vector<int> kt = m[-2];
    kt.insert(kt.begin,90);
    for(int i=0;i<kt.size();i++){
        cout<<kt[i]<<" ";
    }
    return 0;
}