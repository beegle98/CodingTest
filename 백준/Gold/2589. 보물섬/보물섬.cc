#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <string.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

int n,m;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
string s[50];
int ans=0;

struct Node{
    int x;
    int y;
    int len;
};

void bfs(int x,int y){
    queue<Node> q;
    bool visited[100][100];
    memset(visited,0,sizeof(visited));
    q.push({x,y,0});
    visited[x][y]=1;
    while(!q.empty()){
        Node cur = q.front();
        q.pop();
        ans = max(ans, cur.len);
        for(int i=0;i<4;i++){
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=m||
                visited[nx][ny]||s[nx][ny]!='L') continue;
            q.push({nx,ny,cur.len+1});
            visited[nx][ny]=1;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);
	cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='L') bfs(i,j);
        }
    }
    cout << ans;
    return 0;
}