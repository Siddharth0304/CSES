#include <bits/stdc++.h>
using namespace std;
int mod=1e9+7;

long long helper(int n,vector<int> &arr,int prev,int i,vector<vector<long long>> &dp){
    if(i==n)
        return 0;
    if(dp[prev+1][i]!=-1)
        return dp[prev+1][i]%mod;
    int cost=helper(n,arr,prev,i+1,dp)%mod;
    if(prev==-1 || arr[prev]<arr[i])
        cost=(cost+1+helper(n,arr,i,i+1,dp))%mod;
    return dp[prev+1][i]=cost%mod;
}

long long increasingSubsequences2(int n,vector<int> &arr){
    vector<vector<long long>> dp(n+1,vector<long long> (n+1,-1));
    return helper(n,arr,-1,0,dp)%mod;
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
    cout<<increasingSubsequences2(n,arr);
        
    return 0;
}