#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isSafe(vector<vector<char> > &grid, int row, int col) 
{ 
    int i, j; 
    for (i = 0; i < col; i++) 
        if (grid[row][i]=='Q') 
            return false; 
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (grid[i][j]=='Q') 
            return false; 
    for (i = row, j = col; j >= 0 && i < grid.size(); i++, j--) 
        if (grid[i][j]=='Q') 
            return false; 
    return true; 
} 
bool NQueens(vector<vector<char> > &grid, int cols, int n){
    if(cols>=n){
        return true;
    }
    for(int i=0;i<n;i++){
        if(isSafe(grid,i,cols)){
            grid[i][cols] = 'Q';
            if(NQueens(grid,cols+1,n)==1){
                return true;
            }
            grid[i][cols] = '.';
        }
    }
    return false;
}
int main(){
    int n=4,k=0;
    vector<vector<char> > grid(n ,vector<char> (n, '.'));
    vector<vector<string> > str(n ,vector<string> (n, ""));
    if(NQueens(grid,0,n)==false){
        cout<<"Not Possible to Solve"<<endl;
    }
    else{
        for (int i = 0; i < grid.size(); i++){
            string temp = "";
            k=0;
            for (int j = 0; j < grid[i].size(); j++){
                temp = temp + grid[i][j];
            }
            str[i][k] = temp;
            //cout<<str[i][k]<<endl;
            k++;
        }
        cout<<endl;
        for (int i = 0; i < grid.size(); i++){
            string temp = "";
            k=0;
            for (int j = grid[i].size()-1; j >=0 ; j--){
                temp = temp + grid[i][j];
            }
            str[i][k] = temp;
            //cout<<str[i][k]<<endl;
            k++;
        }
    }

    for(int i=0;i<str.size();i++){
        for (int j = 0; j < str[i].size(); j++){
            cout<<str[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}