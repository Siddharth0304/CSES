#include <bits/stdc++.h>
using namespace std;
 
int mod=1e9+7;
 
int main() {
    int t,N=1e6;
    cin>>t;
    vector<vector<long long>> dp(N+1,vector<long long> (2,0));
    dp[0][0]=1;
    dp[0][1]=1;
    for(int i=1;i<=N;i++){
        dp[i][0]=(2LL*dp[i-1][0]+dp[i-1][1])%mod;
        dp[i][1]=(4LL*dp[i-1][1]+dp[i-1][0])%mod;
    }
    while(t--){
        int n;
        cin>>n;
        cout<<(dp[n-1][0]+dp[n-1][1])%mod<<endl;
    }
    return 0;
}