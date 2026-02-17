#include <bits/stdc++.h>
using namespace std;
 
int m=1e9+7;
int countCoins(vector<int> &coins,int n,int x){
    vector<long long> dp(x+1,0);
    dp[0]=1LL;
    
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i>=coins[j])
                dp[i]+=dp[i-coins[j]];
        }
        dp[i]%=m;
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
