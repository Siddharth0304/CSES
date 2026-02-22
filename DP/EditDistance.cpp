#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string a,b;
    cin>>a;
    cin>>b;
    int n=a.size(),m=b.size();
    vector<vector<int>> dp(n+1,vector<int> (m+1,1e7));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0)
                dp[i][j]=j;
            else if(j==0)
                dp[i][j]=i;
            else if(a[i-1]==b[j-1])
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
            else    
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}