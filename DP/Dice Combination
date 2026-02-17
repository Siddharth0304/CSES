#include <bits/stdc++.h>
using namespace std;
int m=1e9+7;

long long helper(int target,vector<long long> &dp){
    if(target==0)
        return 1LL;
    if(target<0)
        return 0;
    if(dp[target]!=-1)
        return dp[target]%m;
    long long ways=0;
    for(int i=1;i<=6;i++){
        if(target>=i)
            ways=(ways%m+helper(target-i,dp)%m)%m;
    }
    return dp[target]=ways%m;
}

int diceComb(int n){
    vector<long long> dp(n+1,-1);
    return helper(n,dp);
}

int main() {
    int n;
    cin>>n;
    cout<<diceComb(n);
    return 0;
}
