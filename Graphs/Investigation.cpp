#include<bits/stdc++.h>
using namespace std;
long long INF=LLONG_MAX/2;
int mod=1e9+7;

void investigation(int n,vector<vector<pair<int,int>>> &adj){
    vector<long long> dist(n+1,INF);
    vector<long long> ways(n+1,0);
    vector<int> minFlights(n+1,INF);
    vector<int> maxFlights(n+1,-1);
    set<pair<long long,int>> se;

    se.insert({0,1});
    dist[1]=0;ways[1]=1;minFlights[1]=0;maxFlights[1]=0;

    while(!se.empty()){
        auto f=*se.begin();
        se.erase(se.begin());
        auto d=f.first;
        auto node=f.second;
        if(dist[node]<d) continue;

        for(auto &it:adj[node]){
            int v=it.first;
            long long w=1LL*it.second;

            if(d+w<dist[v]){
                se.insert({d+w,v});
                dist[v]=d+w;
                ways[v]=ways[node]%mod;
                minFlights[v]=minFlights[node]+1;
                maxFlights[v]=maxFlights[node]+1;
            }
            else if(d+w==dist[v]){
                ways[v]=(ways[node]%mod+ways[v]%mod)%mod;
                minFlights[v]=min(minFlights[v],minFlights[node]+1);
                maxFlights[v]=max(maxFlights[v],maxFlights[node]+1);
            }
        }
    }

    cout<<dist[n]<<" "<<ways[n]<<" "<<minFlights[n]<<" "<<maxFlights[n]<<endl;

}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);

    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }

    investigation(n,adj);
    return 0;  
}