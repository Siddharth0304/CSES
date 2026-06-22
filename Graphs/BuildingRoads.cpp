#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &adj, vector<int> &vis, int node){
    queue<int> q;
    vis[node]=1;
    q.push(node);
    
    while(!q.empty()){
        int node=q.front();
        q.pop();
        
        for(auto &it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
}

int main() {
    int n,m,c=0;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> vis(n+1,0);
    vector<int> v;
    
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            c++;
            v.push_back(i);
            bfs(adj,vis,i);
        }
    }
    if(c==1)
        cout<<c-1<<endl;
    else{
        cout<<c-1<<endl;
        for(int i=1;i<v.size();i++){
            cout<<v[i-1]<<" "<<v[i]<<endl;
        }
    }
    
    return 0;
}