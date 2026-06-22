#include <bits/stdc++.h>
using namespace std;

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1}; 
char direction[]={'U','D','L','R'};

bool bfs(int n,int m,pair<int,int> &src,pair<int,int> &dst,vector<vector<char>> &rooms,vector<vector<pair<int,int>>> &parent,vector<vector<char>> &dir){
    queue<pair<int,int>> q;
    q.push(src);
    rooms[src.first][src.second]='#';

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(x==dst.first && y==dst.second)
            return true;
        for(int i=0;i<4;i++){
            int r=x+dx[i];
            int c=y+dy[i];

            if(r>=0 && r<n && c>=0 && c<m && (rooms[r][c]=='.' || rooms[r][c]=='B')){
                rooms[r][c]='#';
                q.push({r,c});
                parent[r][c]={x,y};
                dir[r][c]=direction[i];
            }
        }
    }
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<char>> rooms(n,vector<char> (m));
    vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>> (m));
    vector<vector<char>> dir(n,vector<char> (m));
    pair<int,int> src,dst;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char ch;
            cin>>ch;
            rooms[i][j]=ch;
            if(ch=='A') src={i,j};
            else if(ch=='B') dst={i,j};
        }
    }

    if(bfs(n,m,src,dst,rooms,parent,dir)){
        string s="";
        pair<int,int> cur=dst;
        while(cur!=src){
            s.push_back(dir[cur.first][cur.second]);
            cur=parent[cur.first][cur.second];
        }
        reverse(s.begin(),s.end());
        cout<<"YES"<<endl<<s.size()<<endl<<s<<endl;
    }
    else
        cout<<"NO\n";
    return 0;
}