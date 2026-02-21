#include <bits/stdc++.h>
using namespace std;
 
int mod=1e9+7;
int countWays(vector<int> &nums,int n,int m){
    vector<vector<long long>> dp(n+1,vector<long long> (m+1,0));
    for(int i=1;i<=m;i++){
        if(nums[0]==0 || nums[0]==i)
            dp[1][i]=1;
    }
    
    for(int i=2;i<=n;i++){
        for(int k=1;k<=m;k++){
            if(nums[i-1]!=0 && nums[i-1]!=k){
                dp[i][k]=0;
                continue;
            }
            
            for(int prev=k-1;prev<=k+1;prev++){
                if(prev>=1 && prev<=m)
                    dp[i][k]=(dp[i][k]+dp[i-1][prev])%mod;
            }
        }
    }
    long long ans=0;
    for(int i=1;i<=m;i++)
        ans=(ans+dp[n][i])%mod;
    return ans;
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