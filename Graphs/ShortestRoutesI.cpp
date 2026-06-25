#include <bits/stdc++.h>
using namespace std;
 
vector<long long> dijkstras(int n,vector<vector<pair<int,int>>> &adj){
    vector<long long> dist(n,LLONG_MAX/2);
    set<pair<long long,long long>> se;
    dist[1]=0;
    se.insert({0,1});
    while(!se.empty()){
        pair<long long,long long> p=*se.begin();
        se.erase(se.begin());
        long long d=p.first,node=p.second;
        if(d>dist[node])
            continue;
        for(auto &it:adj[node]){
            if(d*1LL+it.second*1LL<dist[it.first]){
                dist[it.first]=d+it.second;
                se.insert({d+it.second,it.first});
            }
        }
    }
    return dist;
}
 
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
 
    vector<long long> dist=dijkstras(n+1,adj);
    for(int i=1;i<n+1;i++)
        cout<<dist[i]<<" ";
    cout<<endl;
    
    return 0;
}