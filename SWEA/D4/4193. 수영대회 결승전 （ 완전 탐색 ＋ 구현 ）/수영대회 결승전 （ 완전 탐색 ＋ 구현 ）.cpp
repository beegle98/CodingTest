#include <bits/stdc++.h>

using namespace std;
#define FASTIO  cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int Min,n,s[20][20],st[2],en[2];
int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int visited[20][20];


void dfs(int x,int y,int t){
    if(x<0 || x>=n || y<0 || y>=n || s[x][y]==1) return;
    if(x==en[0] && y==en[1]){
        Min = min(Min,t);
        return;
    }
    if(visited[x][y]>0 && visited[x][y]<=t) return;

    if(s[x][y]==2){
        while(t%3!=0) t++;
    }
    visited[x][y]=t;
    for(int i=0;i<4;i++){
        dfs(x+d[i][0],y+d[i][1],t+1);
    }
}

int main()
{
    int tc; cin >> tc;
    for(int t=1;t<=tc;t++){
        cin >> n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> s[i][j];
                memset(visited[i],0,sizeof(int)*n);
            }
        }
        cin >> st[0] >> st[1];
        cin >> en[0] >> en[1];
        Min=1000000000;
        dfs(st[0],st[1],0);
        if(Min == 1000000000) Min = -1;
        cout << "#" << t << ' ' << Min << '\n';
    }
    return 0;
}