#include <bits/stdc++.h>
using namespace std;
 
int m=1e9+7;
int countCoins(vector<int> &coins,int n,int x){
    vector<long long> dp(x+1,0);
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=1;j<=x;j++){
            if(j>=coins[i])
                dp[j]=dp[j]+dp[j-coins[i]];
            if(dp[j]>=m) dp[j]-=m;
        }
    }
    return dp[x];
}
 
int main() {
    int n,x;
    cin>>n>>x;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        coins[i]=c;
    }
    cout<<countCoins(coins,n,x);
    return 0;
}
