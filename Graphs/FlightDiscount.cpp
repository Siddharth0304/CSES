#include <bits/stdc++.h>
using namespace std;
 
long long INF=LLONG_MAX/2;
 
long long dijkstra(int n,int m,vector<vector<pair<int,int>>> &adj){
    vector<vector<long long>> dist(n+1,vector<long long> (2,INF));
    set<pair<pair<long long,int>,int>> se;
    dist[1][0]=0;
    se.insert({{0,1},0});
   
    while(!se.empty()){
        auto [meta,c]=*se.begin();
        auto [d,node]=meta;
        se.erase(se.begin());
       
        if(dist[node][c]<d) continue;
       
        for(auto &it:adj[node]){
            int v=it.first;
            int w=it.second;
            if(d+w<dist[v][c]){
                dist[v][c]=d+w;
                se.insert({{d+w,v},c});
            }
            if(c==0 && d+w/2<dist[v][1]){
                dist[v][1]=d+w/2;
                se.insert({{d+w/2,v},1});
            }
        }
    }
    return min(dist[n][0],dist[n][1]);
}
 
int main() {
    int n,m;
    cin>>n>>m;
    long long INF=LLONG_MAX/2;
    vector<vector<pair<int,int>>> adj(n+1);
   
    for(int i=0;i<m;i++){
        int a,b,x;
        cin>>a>>b>>x;
        adj[a].push_back({b,x});
    }
   
    cout<<dijkstra(n,m,adj)<<endl;
   
    return 0;
}