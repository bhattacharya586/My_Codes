#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int compare(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}
int main(){
    int p;
    cin>>p;
    vector<pair<int,int> > data(p);
    for (int i = 0; i < data.size(); i++)
    {
        cin>>data[i].first>>data[i].second;
    }
    sort(data.begin(),data.end(),compare);
    int endtime = 0;
    int counter=1;
    for (int i = 1; i < data.size(); i++)
    {
        if(data[i].first>=endtime){
            counter++;
            endtime = data[i].second;
        }
    }
    cout<<"Counter : "<<counter<<endl;
    return 0;
}