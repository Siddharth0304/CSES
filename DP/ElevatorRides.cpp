#include <bits/stdc++.h>
using namespace std;

int elevatorRides(int n,int x,vector<int> &arr){
    long long N=1<<n,INF=1e18;

    vector<pair<long long,long long>> dp(N,{INF,INF});
    dp[0]={1,0};

    for(int mask=0;mask<N;mask++){
        auto [rides,last_wt]=dp[mask];
        if(rides==INF)
            continue;

        for(int i=0;i<n;i++){
            if(mask&(1<<i)) continue;

            int newMask=mask|(1<<i);
            pair<long long,long long> candidate;
            if(arr[i]+last_wt<=x)
                candidate={rides,last_wt+arr[i]};
            else
                candidate={rides+1,arr[i]};

            dp[newMask]=min(dp[newMask],candidate);
        }
    }
    return dp[N-1].first;
}
 
int main() {
    int n,x;
    cin>>n>>x;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr[i]=x;
    }
    cout<<elevatorRides(n,x,arr); 
    return 0;
}