#include <bits/stdc++.h>
using namespace std;
 
int findLargestDigit(int n){
    int x=0;
    while(n>0){
        int rem=n%10;
        x=max(x,rem);
        n/=10;
    }
    return x;
}
 
int waysPath(vector<vector<char>> &grid,int n){
    vector<vector<long long>> dp(n,vector<long long> (n,0));
    long long m=1e9+7;
    dp[0][0]=grid[0][0]=='*'?0:1;
    for(int i=1;i<n;i++){
        if(grid[i][0]=='*')
            dp[i][0]=0;
        else
            dp[i][0]=dp[i-1][0];
    }
    for(int i=1;i<n;i++){
        if(grid[0][i]=='*')
            dp[0][i]=0;
        else
            dp[0][i]=dp[0][i-1];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(grid[i][j]=='*')
                dp[i][j]=0;
            else
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            if(dp[i][j]>=m) dp[i][j]-=m;
        }
    }
    return dp[n-1][n-1];
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
    cout<<waysPath(grid,n);
 
    return 0;
}
