#include <bits/stdc++.h>
using namespace std;

int INF=INT_MAX;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int dd[]={'L','R','U','D'};
vector<vector<pair<int,int>>> par;
 
pair<int,int> monsters(pair<int,int> p,vector<vector<char>> &grid,vector<vector<int>> &dist,vector<vector<char>> &dir){
    queue<tuple<int,int,int>> q;
    dist[p.first][p.second]=0;
    q.push({0,p.first,p.second});
    while(!q.empty()){
        auto [d,x,y]=q.front();
        q.pop();
        
        if(x==grid.size()-1 || y==grid[0].size()-1 || x==0 || y==0) return {x,y};
        if(d>dist[x][y]) continue;
        
        for(int i=0;i<4;i++){
            int r=x+dx[i],c=y+dy[i];
            if(r>=0 && r<grid.size() && c>=0 && c<grid[0].size() && grid[r][c]!='#'){
                if(d+1<dist[r][c]){
                    dist[r][c]=d+1;
                    q.push({d+1,r,c});
                    dir[r][c]=dd[i];
                    par[r][c]={x,y};
                }
            }
        }
    }
    return {-1,-1};
}
 
void updateDist(queue<tuple<int,int,int>> &q,vector<vector<char>> &grid,vector<vector<int>> &dist){
    while(!q.empty()){
        auto [d,x,y]=q.front();
        q.pop();
        if(d>dist[x][y]) continue;
        
        for(int i=0;i<4;i++){
            int r=x+dx[i],c=y+dy[i];
            if(r>=0 && r<grid.size() && c>=0 && c<grid[0].size() && grid[r][c]!='#'){
                if(d+1<dist[r][c]){
                    dist[r][c]=d+1;
                    q.push({d+1,r,c});
                }
            }
        }
    }
}
 
int main() {
    int n,m;
    cin>>n>>m;
    
    par.resize(n,vector<pair<int,int>> (m,{-1,-1}));
    vector<vector<char>> grid(n,vector<char> (m));
    vector<vector<char>> dir(n,vector<char> (m,' '));
    vector<vector<int>> dist(n,vector<int> (m,INF));
    pair<int,int> p;
    queue<tuple<int,int,int>> q;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char ch;
            cin>>ch;
            grid[i][j]=ch;
            if(ch=='A'){
                p={i,j};
            }
            if(ch=='M'){
                q.push({0,i,j});
                dist[i][j]=0;
            }
        }
    }
    
    updateDist(q,grid,dist);
    pair<int,int> cur=monsters(p,grid,dist,dir);
    
    if(cur.first!=-1){
        string s="";
        while(cur.first!=-1 && cur.second!=-1){
            s.push_back(dir[cur.first][cur.second]);
            cur=par[cur.first][cur.second];
        }
        s.pop_back();
        reverse(s.begin(),s.end());
        cout<<"YES\n"<<s.size()<<endl<<s<<endl;
        
    }
    else
        cout<<"NO\n";
    
 
    return 0;
}