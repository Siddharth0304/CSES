#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;

void gameRoutes(int n,vector<long long> &ways,vector<int> &indegree,vector<vector<int>> &adj){
    queue<int> q;
    vector<int> vis(n+1,0);
    ways[1]=1;

    for(int i=1;i<=n;i++){
        if(indegree[i]==0)
            q.push(i);
    }

    while(!q.empty()){
        int node=q.front();
        q.pop();

        for(auto &it:adj[node]){
            ways[it]=(ways[it]%mod+ways[node])%mod;
            indegree[it]--;
            if(indegree[it]==0)
                q.push(it);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1,0);
    vector<long long> ways(n+1,0);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        indegree[b]++;
    }

    gameRoutes(n,ways,indegree,adj);
    cout<<ways[n]%mod<<endl;

    return 0;
}