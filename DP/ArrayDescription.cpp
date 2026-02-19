#include <bits/stdc++.h>
using namespace std;
 
int mod=1e9+7;

int helper(vector<int> &nums, int n, int m, int idx, int prev, vector<vector<long long>> &dp){
    if(idx==n)
        return 1;
    if(dp[idx][prev]!=-1)
        return dp[idx][prev];
    long long ans=0;
    if(nums[idx]==0){
        for(int i=1;i<=m;i++){
            if(idx==0 || (abs(i-prev)<=1))
                ans=(ans+helper(nums,n,m,idx+1,i,dp))%mod;
        }
    }
    else if(idx==0 || (abs(nums[idx]-prev)<=1))
        ans=(ans+helper(nums,n,m,idx+1,nums[idx],dp))%mod;
    return dp[idx][prev]=ans;
}

int countWays(vector<int> &nums,int n,int m){
    vector<vector<long long>> dp(n+1,vector<long long> (m+1,-1));
    return helper(nums,n,m,0,0,dp);
}
 
int main() {
    int n,m;
    cin>>n>>m;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        nums[i]=c;
    }
    cout<<countWays(nums,n,m);
    return 0;
}
