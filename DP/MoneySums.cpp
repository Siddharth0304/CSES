#include <bits/stdc++.h>
using namespace std;

void moneySums(int n,int s,vector<int> &arr){
    vector<vector<bool>> dp(n+1,vector<bool> (s+1,false));
    dp[0][0]=true;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=s;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=arr[i-1] && dp[i-1][j-arr[i-1]])
                dp[i][j]=true;
        }
    }
    vector<int> ans;
    for(int j=1;j<=s;j++){
        if(dp[n][j])
            ans.push_back(j);
    }
    cout<<ans.size()<<endl;
    for(auto &it:ans)
        cout<<it<<" ";

}
 
int main() {
    int n,s=0;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr[i]=x;
        s+=x;
    }
    moneySums(n,s,arr); 
    return 0;
}