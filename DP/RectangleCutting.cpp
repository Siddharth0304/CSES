#include <bits/stdc++.h>
using namespace std;

int rectangleCutting(int a,int b){
    vector<vector<int>> dp(501,vector<int> (501,1e7));
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i==j){
                dp[i][j]=0;
                continue;
            }
            int cost=1e7;
            for(int k=1;k<j;k++)
                cost=min(cost,1+dp[i][j-k]+dp[i][k]);
            for(int k=1;k<i;k++)
                cost=min(cost,1+dp[i-k][j]+dp[k][j]);
            dp[i][j]=cost;
        }
    }
    return dp[a][b];
}
 
int main() {
    int a,b;
    cin>>a>>b;
    cout<<rectangleCutting(a,b);
    return 0;
}