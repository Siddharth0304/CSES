#include <bits/stdc++.h>
using namespace std;
 
class DisjointSet{
    public:
    vector<int> parent,size;
    DisjointSet(int n){
        for(int i=0;i<=n;i++){
            parent.push_back(i);
            size.push_back(1);
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
 
int main() {
    int n,m,maxC;
    cin>>n>>m;
    maxC=1;
    
    DisjointSet ds(n);
    vector<vector<int>> edges;
    
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        edges.push_back({a,b});
    }
    
    for(auto &it:edges){
        if(ds.findUPar(it[0])!=ds.findUPar(it[1])){
            n--;
            ds.unionBySize(it[0],it[1]);
            int ulp_u=ds.findUPar(it[0]);
            maxC=max(maxC,ds.size[ulp_u]);
        }
        cout<<n<<" "<<maxC<<endl;
    }
    
    return 0;
}