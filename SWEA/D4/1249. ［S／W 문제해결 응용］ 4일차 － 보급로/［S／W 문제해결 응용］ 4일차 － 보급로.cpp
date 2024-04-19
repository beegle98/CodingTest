#include <bits/stdc++.h>

using namespace std;
#define FASTIO cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

const int MAX = 101;
int s[MAX][MAX],Min[MAX][MAX],n;
int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
 
queue<pi> q;
 
void bfs(pi v){
    int x=v.first, y=v.second;
    if(x==n-1 && y==n-1) return;
     
    for(int i=0;i<4;i++){
        int wx,wy;
        wx=x+d[i][0];
        wy=y+d[i][1];
        if(wx < 0 || wx >= n || wy < 0 || wy >= n) continue;
        if(Min[wx][wy]==-1 || Min[wx][wy]>Min[x][y]+s[wx][wy]){
            Min[wx][wy]=Min[x][y]+s[wx][wy];
            q.push({wx,wy});
        }
         
    }
     
}
 
int main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
     
    int test_case; cin >> test_case;
    for(int t=1;t<=test_case;t++){
         
        int ans;
        cin >> n;
        for(int i=0;i<n;i++){
            string str;
            cin >> str;  
            for(int j=0;j<n;j++){
                s[i][j]=str[j]-'0';
            }
            memset(Min[i],-1,sizeof(int)*n);
        }
        Min[0][0]=s[0][0];
        q.push({0,0});
        while(!q.empty()){
            pi v=q.front();
            q.pop();
            bfs(v);
        }
        ans=Min[n-1][n-1];
        cout << "#" << t << ' ' << ans << '\n';
    }
    return 0;
}