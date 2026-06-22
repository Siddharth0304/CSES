#include <bits/stdc++.h>
using namespace std;

long long helper(int n,vector<int> &arr,int i,int j,int player,vector<vector<long long>> &dp){
    if(i>j)
        return 0;
    if(i==j)
        return arr[i];
    if(dp[i][j]!=-1)
        return dp[i][j];
    long long cost=-1e15;
    if(player==0)
        cost=max(arr[i]+helper(n,arr,i+1,j,!player,dp),arr[j]+helper(n,arr,i,j-1,!player,dp));
    else
        cost=min(helper(n,arr,i+1,j,!player,dp),helper(n,arr,i,j-1,!player,dp));
    return dp[i][j]=cost;
}

long long removalGame(int n,vector<int> &arr){
    vector<vector<long long>> dp(n,vector<long long> (n,-1));
    return helper(n,arr,0,n-1,0,dp);
}
 
int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr[i]=x;
    }
    cout<<removalGame(n,arr); 
    return 0;
}