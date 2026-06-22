#include <bits/stdc++.h>
using namespace std;
 
int bfs(vector<vector<int>> &adj, vector<int> &vis, vector<int> &parent, int src, int dst){
    queue<pair<int,int>> q;
    vis[src]=1;
    q.push({src,1});
    
    while(!q.empty()){
        int node=q.front().first;
        int steps=q.front().second;
        q.pop();
 
        if(node==dst)
            return steps;
        
        for(auto &it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                parent[it]=node;
                q.push({it,steps+1});
            }
        }
    }
    return -1;
}
 
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> vis(n+1,0);
    vector<int> parent(n+1,-1);
    
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    int steps=bfs(adj,vis,parent,1,n);
    
    if(steps>-1){
        int cur=n;
        vector<int> v;
        while(parent[cur]!=-1){
            v.push_back(cur);
            cur=parent[cur];
        }
        v.push_back(1);
        cout<<steps<<endl;
        for(int i=v.size()-1;i>0;i--)
            cout<<v[i]<<" ";
        cout<<n<<endl;
    }
    else
        cout<<"IMPOSSIBLE\n";
    
    return 0;
}