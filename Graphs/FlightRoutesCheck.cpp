#include<bits/stdc++.h>
using namespace std;

vector<int> comp;

void topoSort(int node,vector<int> &vis,vector<vector<int>> &adj,stack<int> &st){
    vis[node]=1;
    for(auto &it:adj[node]){
        if(!vis[it])
            topoSort(it,vis,adj,st);
    }
    st.push(node);
}

void dfs(int node,vector<int> &vis,vector<vector<int>> &revAdj,int c){
    vis[node]=1;
    comp[node]=c;
    for(auto &it:revAdj[node]){
        if(!vis[it])
            dfs(it,vis,revAdj,c);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1),revAdj(n+1);
    vector<int> vis(n+1,0);
    int c=0;
    comp.resize(n+1);
    stack<int> st;

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        revAdj[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i])
            topoSort(i,vis,adj,st);
    }

    vis=vector<int> (n+1,0);
    while(!st.empty()){
        int node=st.top();
        st.pop();

        if(!vis[node]){
            c++;
            dfs(node,vis,revAdj,c);
        }
    }

    if(c==1)
        cout<<"YES\n";
    else{
        cout<<"NO\n";
        int a=-1,b=-1;
        for(int i=1;i<=n;i++){
            if(comp[i]==1)
                a=i;
            if(comp[i]!=1)
                b=i;
            if(a!=-1 && b!=-1){
                cout<<b<<" "<<a;
                return 0;
            }
        }
    }
    

    return 0;
}