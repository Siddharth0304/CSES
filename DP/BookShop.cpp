#include <bits/stdc++.h>
using namespace std;

int maxPages(vector<int> &prices,vector<int> &pages,int n,int maxPrice){
    vector<vector<int>> dp(n+1,vector<int>(maxPrice+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=maxPrice;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=prices[i-1])
                dp[i][j]=max(dp[i][j],pages[i-1]+dp[i-1][j-prices[i-1]]);
        }
    }
    return dp[n][maxPrice];
}

int main() {
    int n,maxPrice;
    cin>>n>>maxPrice;
    vector<int> prices(n),pages(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        prices[i]=x;
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        pages[i]=x;
    }
    cout<<maxPages(prices,pages,n,maxPrice);

    return 0;
}
