#include <bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>> &adj, vector<int> &vis, vector<int> &ans, int src){
    queue<int> q;
    vis[src]=1;
    ans[src]=1;
    q.push(src);
    
    while(!q.empty()){
        int node=q.front();
        q.pop();
        
        for(auto &it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
                if(ans[node]==1)
                    ans[it]=2;
                else
                    ans[it]=1;
            }
            else if(ans[it]==ans[node])
                return false;
        }
    }
    return true;
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> vis(n+1,0);
    vector<int> ans(n+1,0);
    bool flag=true;
    
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(!bfs(adj,vis,ans,i)){
                flag=false;
                break;
            }
        }
    }

    if(flag==false)
        cout<<"IMPOSSIBLE\n";
    else{
        for(int i=1;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<ans[n]<<endl;
    }
    
    return 0;
}