#include <bits/stdc++.h>
using namespace std;
 
long long INF=LLONG_MAX/2;

void bellmanFord(int &n,vector<vector<int>> &edges){
    vector<long long> dist(n+1,0);
    vector<int> parent(n+1,-1);
    int x=-1;

    for(int i=0;i<n;i++){
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            long long d=it[2];
            if(dist[u]!=INF && dist[u]+d<dist[v]){
                dist[v]=dist[u]+d;
                parent[v]=u;
                if(i==n-1) // condition only to track in nth loop and not before it
                    x=v;
            }
        }
    }

    if(x==-1){
        cout<<"NO\n";
        return;
    }

    for(int i=0;i<n;i++)
        x=parent[x];

    vector<int> cycle;
    for(int curr=x;;curr=parent[curr]){
        cycle.push_back(curr);
        if(curr==x && cycle.size()>1)
            break;
    }
    reverse(cycle.begin(),cycle.end());

    cout<<"YES\n";
    for(auto &it:cycle)
        cout<<it<<" ";
    return;
    
}
 
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
   
    for(int i=0;i<m;i++){
        int a,b,x;
        cin>>a>>b>>x;
        edges.push_back({a,b,x});
    }
   
    bellmanFord(n,edges);
    return 0;
}