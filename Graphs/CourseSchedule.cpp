#include<bits/stdc++.h>
using namespace std;

void courseSchedule(int n,vector<int> &indegree, vector<vector<int>> &adj){
    queue<int> q;
    vector<int> topo;
    int c=0;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0)
            q.push(i);
    }

    while(!q.empty()){
        auto node=q.front();
        q.pop();
        c++;
        topo.push_back(node);

        for(auto &it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0)
                q.push(it);
        }
    }

    if(c!=n){
        cout<<"IMPOSSIBLE\n";
        return;
    }

    for(auto &it:topo){
        cout<<it<<" ";
    }

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


    courseSchedule(n,indegree,adj);

    return 0;
}