#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
bool compare(pair<int,int> a,pair<int,int> b);
int main(){
    int n;
    cout<<"Enter total number of Jobs"<<endl;
    cin>>n;
    vector<pair<int,int> > vect;
    for(int i=0;i<n;i++){
        int deadline,profit;
        cout<<"Enter the Deadline and Profit of Job "<<i<<endl;
        cin>>deadline>>profit;
        vect.push_back(make_pair(deadline,profit));
    }
    sort(vect.begin(),vect.end(),compare);
    int d,p;
    map<int,int> final_col;
    for(int i=0;i<vect.size();i++){
        d = vect[i].first;
        p = vect[i].second;
        d--;
        while(d>=0){
            if(final_col[d]==0){
                final_col[d]=p;
                break;
            }
            d--;
        }
    }
    int total_profit=0;
    for(map<int,int>::iterator itr=final_col.begin();itr!=final_col.end();itr++){
        total_profit+=itr->second;
    }
    cout<<"Total Profit : "<<total_profit;
    return 0;
}
bool compare(pair<int,int> a,pair<int,int> b){
	return a.second>b.second;
}