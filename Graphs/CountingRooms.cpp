#include <bits/stdc++.h>
using namespace std;

void bfs(int n,int m,int a,int b,vector<vector<char>> &rooms){
    int dx[]={-1,1,0,0};
    int dy[]={0,0,-1,1};
    queue<pair<int,int>> q;
    q.push({a,b});
    rooms[a][b]='#';

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int r=x+dx[i];
            int c=y+dy[i];

            if(r>=0 && r<n && c>=0 && c<m && rooms[r][c]=='.'){
                rooms[r][c]='#';
                q.push({r,c});
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> rooms(n,vector<char> (m));
    int c=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char ch;
            cin>>ch;
            rooms[i][j]=ch;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(rooms[i][j]=='.'){
                c++;
                bfs(n,m,i,j,rooms);
            }
        }
    }
    cout<<c<<endl;
    return 0;
}