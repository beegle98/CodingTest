#include <bits/stdc++.h>

using namespace std;
#define FASTIO cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

int n,s[11][11],v1[22],v2[22],Max;

void dfs(int x,int y,int sum){
    if(y>=n){
        y = (y+1)%2;
        x++;
        if(x>=n){
            Max = max(Max,sum);
            return;
        }
    }
    int a=10+x-y,b=x+y;
    if(s[x][y] && !v1[a] && !v2[b]){
        v1[a]=v2[b]=1;
        dfs(x,y+2,sum+1);
        v1[a]=v2[b]=0;
    }
    dfs(x,y+2,sum);
    
}

int main(){
    FASTIO
    int ans[2];
    cin >> n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> s[i][j];
    Max=0;
    dfs(0,0,0);
    ans[0]=Max;
    Max=0;
    dfs(0,1,0);
    ans[1]=Max;
    cout << ans[0]+ans[1];
    return 0;
}