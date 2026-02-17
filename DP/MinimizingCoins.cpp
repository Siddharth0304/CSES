#include <bits/stdc++.h>
using namespace std;
 
int minCoins(vector<int> &coins,int n,int x){
    vector<long long> prev(x+1,1e9);
    vector<long long> curr(x+1,1e9);
 
    prev[0]=0;
    curr[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            curr[j]=min(curr[j],prev[j]);
            if(j>=coins[i-1])
                curr[j]=min(curr[j],1+curr[j-coins[i-1]]);
        }
        prev=curr;
    }
    if(prev[x]>=1e9)
        return -1;
    return prev[x];
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
    cout<<minCoins(coins,n,x);
    return 0;
}
