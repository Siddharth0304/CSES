//This problem is on AtCoder : https://atcoder.jp/contests/dp/tasks/dp_o

#include <bits/stdc++.h>
using namespace std;
 
long long mod=1e9+7;

int matching(vector<vector<int>> &arr,int n){
    long long len=(1<<n);
    vector<long long> dp(len,0);
    dp[0]=1;
    for(int mask=0;mask<(1<<n);mask++){
        int i=__builtin_popcount(mask);
        if(i>=n) continue;
        if(dp[mask]==0) continue;
        
        for(int j=0;j<n;j++){
            if(!(mask&(1<<j)) && arr[i][j]==1){
                int newMask=mask|(1<<j);
                dp[newMask]=(dp[newMask]+dp[mask])%mod;
            }
        }
    }
    return dp.back();
}

int main() {
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            arr[i][j]=x;
        }
    }
    cout<<matching(arr,n);
    return 0;
}
