#include<bits/stdc++.h>
using namespace std;
 
int INF=INT_MIN;
 
void longestFlightRoute(int n,vector<int> &indegree,vector<vector<int>> &adj){
    vector<int> dist(n+1,INF),parent(n+1,-1),v;
    queue<int> q;
    dist[1]=1;

    for(int i=1;i<=n;i++){
        if(indegree[i]==0)
            q.push(i);
    }
    
    while(!q.empty()){
        auto node=q.front();
        q.pop();
 
        for(auto &it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0)
                q.push(it);
            if(dist[node]!=INF && dist[node]+1>dist[it]){
                dist[it]=dist[node]+1;
                parent[it]=node;
            }
        }
    }
    
    if(dist[n]>0){
        int cur=n;
        while(parent[cur]!=-1){
            v.push_back(cur);
            cur=parent[cur];
        }
        v.push_back(cur);
        cout<<dist[n]<<endl;   
        for(int i=v.size()-1;i>=0;i--)
            cout<<v[i]<<" ";
    }
    else
        cout<<"IMPOSSIBLE\n";
    
}
 
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1,0);
 
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        indegree[b]++;
    }
 
    longestFlightRoute(n,indegree,adj);
    return 0;
}