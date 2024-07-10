#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=(1<<16);
const int INF = 987654321;

int w[20][20], n, full_bit;
int dp[20][N+1];

int DFS(int cur, int visited){

    if(visited == full_bit){
        if(w[cur][0]){
            return w[cur][0];
        }
        else return INF;
        
    }

    if(dp[cur][visited] != -1) return dp[cur][visited];

    dp[cur][visited]=INF;
    for(int i=0;i<n; i++){
        
        if(!w[cur][i] || visited & (1<<i)) continue;
        dp[cur][visited] = min(dp[cur][visited], w[cur][i]+ DFS(i,visited | (1<<i)));
    }

    return dp[cur][visited];

}


void solve(){
    cin >> n;
    full_bit=(1<<n)-1;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> w[i][j];
        }
    }
    
    cout << DFS(0,1) << '\n';
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    solve();
    return 0;
}