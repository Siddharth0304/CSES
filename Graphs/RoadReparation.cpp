#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
    vector<int> size,parent;
    DisjointSet(int n){
        for(int i=0;i<=n;i++){
            size.push_back(1);
            parent.push_back(i);
        }
    }
    int findUPar(int node){
        if(node==parent[node])
            return node;
        return parent[node]=findUPar(parent[node]);
    }
    void unionBySize(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);

        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

int main(){
    int n,m;
    vector<vector<int>> edges;
    set<int> nodes;
    long long sum=0;
    int c=0;

    cin>>n>>m;
    DisjointSet ds(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges.push_back({c,a,b});
    }

    sort(edges.begin(),edges.end());
    for(auto &it:edges){
        if(ds.findUPar(it[1])!=ds.findUPar(it[2])){
            ds.unionBySize(it[1],it[2]);
            sum+=it[0];
            nodes.insert(it[1]);
            nodes.insert(it[2]);
        }
    }

    for(int i=1;i<=n;i++){
        if(ds.findUPar(i)==i)
            c++;
    }

    if(nodes.size()==n && c==1)
        cout<<sum<<endl;
    else
        cout<<"IMPOSSIBLE\n";

    return 0;
}