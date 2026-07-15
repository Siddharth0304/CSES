// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
long long INF=LLONG_MAX/2;

bool bfs(queue<int> &q,int n,vector<vector<int>> &adj,vector<int> &vis){
    while(!q.empty()){
        auto node=q.front();
        if(node==n) return true;
        q.pop();

        for(auto &it:adj[node]){
            if(!vis[it]){
                q.push(it);
                vis[it]=1;
            }
        }
    }
    return false;
}
 
vector<int> highScore(vector<vector<int>> &rev,int n,vector<long long> &dist){
    dist[1]=0;
    vector<int> arr;
    
    for(int i=1;i<=n;i++){
        for(auto &it:rev){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            
            if(dist[u]!=INF && dist[u]*1LL+w*1LL<dist[v]){
                if(i==n)
                    arr.push_back(v);
                else 
                    dist[v]=dist[u]*1LL+w*1LL;
            }
                
        }
    }
    return arr;
}
 
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
    vector<vector<int>> adj(n+1); 
    vector<long long> dist(n+1,INF);
    dist[1]=0;
    
    for(int i=0;i<m;i++){
        int a,b,x;
        cin>>a>>b>>x;
        adj[a].push_back(b);
        edges.push_back({a,b,-1*x});
    }
    
    vector<int> v=highScore(edges,n,dist);
    long long ans=-1*dist[n];
   
    queue<int> q;
    vector<int> vis(n+1,0);
    for(auto &it:v){
        q.push(it);
        vis[it]=1;
    }
    
    if(bfs(q,n,adj,vis))
        cout<<-1<<endl;
    else
        cout<<ans<<endl;
 
    return 0;
}