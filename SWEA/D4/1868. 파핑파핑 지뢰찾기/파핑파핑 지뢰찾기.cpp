#include <bits/stdc++.h>

using namespace std;
#define FASTIO  cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;


int n,cnt[333][333];
int d[10][2]={
    {-1,-1},{-1,0},{-1,1},
    {0,-1},{0,1},
    {1,-1},{1,0},{1,1}};
char s[333][333];

void dfs(int x,int y){
    if(x<0 || x>=n || y<0 || y>=n || cnt[x][y]==-1) return;
    if(cnt[x][y]!=0){
        cnt[x][y]=-1;
        return;
    }
    cnt[x][y]=-1;
    for(int i=0;i<8;i++){
        dfs(x+d[i][0],y+d[i][1]);
    }
}
int count(int x,int y){
    int sum=0;
    for(int i=0;i<8;i++){
        int dx=x+d[i][0];
        int dy=y+d[i][1];
        if(dx>=0 && dx<n && dy>=0 && dy<n && s[dx][dy]=='*') sum++;
    }
    return sum;
}
int main()
{
    int tc; cin >> tc;
    for(int t=1;t<=tc;t++){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> s[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(s[i][j]=='*') cnt[i][j]=-1;
                else cnt[i][j]=count(i,j);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(cnt[i][j]==0){
                    dfs(i,j);
                    ans++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(cnt[i][j]!=-1) ans++;
            }
        }
        cout << "#" << t << ' ' << ans << '\n';
    }
    return 0;
}