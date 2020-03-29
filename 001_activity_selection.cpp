#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<int,int> a,pair<int,int> b);
int main(){
	int n;
	cout<<"Enter total Processes"<<endl;
	cin>>n;
	vector<pair<int,int> > vect;
	for(int i=0;i<n;i++){
		cout<<"Enter the start and finish time"<<endl;
		int start,finish;
		cin>>start>>finish;
		vect.push_back(make_pair(start,finish));
	}
	sort(vect.begin(),vect.end(),compare);
	int endtime = vect[0].second,processors=0,processes=1;
    for(int i=1;i<vect.size();i++)
    {
        if(vect[i].first>=endtime){
            processes++;
            endtime = vect[i].second;
        }
    }
	endtime = vect[0].second;
	for(int tracker=1;tracker!=vect.size();){
		for(int i=1;i<vect.size();i++){
			if(vect[i].first!=-1 && vect[i].first>=endtime){
				endtime=vect[i].second;
				vect[i].first=-1;
				tracker++;
			}
		}
		processors++;
		endtime=0;	
	}
	cout<<"Total No. of Processors required : "<<processors<<" to run "<<processes<<" Processes concurrently"<<endl;
	return 0;
}
bool compare(pair<int,int> a,pair<int,int> b){
	return a.second<b.second;
}