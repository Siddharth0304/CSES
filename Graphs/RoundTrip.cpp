#include <bits/stdc++.h>
using namespace std;
 
int dfs(int node,int par,vector<int> &vis,vector<vector<int>> &adj,vector<int> &v){
    vis[node]=1;
    v.push_back(node);
    
    for(auto &it:adj[node]){
        if(!vis[it]){
            int res=dfs(it,node,vis,adj,v);
            if(res!=-1)
                return res;
        }
        else if(it!=par)
            return it;
    }
    v.pop_back();
    return -1;
}
 
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> vis(n+1,0);
    bool cycle=false;
    
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vector<int> v;
            int cycleStart=dfs(i,-1,vis,adj,v);
            if(cycleStart!=-1){
                int startIdx=0,c=0;
                for(int i=0;i<v.size();i++){
                    if(v[i]==cycleStart){
                        startIdx=i;
                        break;
                    }
                }
                for(int i=startIdx;i<v.size();i++)
                    c++;
                cout<<c+1<<endl;
                for(int i=startIdx;i<v.size();i++)
                    cout<<v[i]<<" ";
                cout<<v[startIdx]<<endl;
                return 0;
            }
        }
    }
    if(cycle==false)
        cout<<"IMPOSSIBLE\n";
    
    return 0;
}