#include <bits/stdc++.h>
using namespace std;
 
string minimalGridPath(int n,vector<vector<char>> &grid){
    vector<vector<int>> dp(n,vector<int> (n));
    dp[0][0]=(int)(grid[0][0]);
    for(int i=1;i<n;i++)
        dp[0][i]=dp[0][i-1]+(int)(grid[0][i]);
    for(int i=1;i<n;i++)
        dp[i][0]=dp[i-1][0]+(int)(grid[i][0]);
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=min(dp[i-1][j],dp[i][j-1])+(int)grid[i][j];
        }
    }
    
    return "";
}
 
int main() {
    int n;
    cin>>n;
    vector<vector<char>> grid(n,vector<char> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char x;
            cin>>x;
            grid[i][j]=x;
        }
    }
    cout<<minimalGridPath(n,grid);
        
    return 0;
}