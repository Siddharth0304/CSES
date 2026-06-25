#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n,m,q;
    cin>>n>>m>>q;
    long long M=LLONG_MAX/2;
    vector<pair<int,int>> arr;
    vector<vector<long long>> dist(n+1,vector<long long> (n+1,M)); 
    
    for(int i=1;i<=m;i++){
        int u,v;
        long long w;
        cin>>u>>v>>w;
        dist[u][v]=min(w,dist[u][v]);
        dist[v][u]=min(w,dist[v][u]);
    }

    for(int i=1;i<=n;i++)
        dist[i][i]=0;
 
    for(int via=1;via<=n;via++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==via || j==via) continue;
                if(dist[i][via]!=M && dist[via][j]!=M){
                    dist[i][j]=min(dist[i][via]+dist[via][j],dist[i][j]);
                }
            }
        }
    }

    for(int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        arr.push_back({u,v});
        
    }

    for(auto &it:arr){
        int u=it.first,v=it.second;
        long long t=min(dist[u][v],dist[v][u]);
        if(t==M)
            cout<<-1<<endl;
        else
            cout<<t<<endl;
    }
    
    return 0;
}