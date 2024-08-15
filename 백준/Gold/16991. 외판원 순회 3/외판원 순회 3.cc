#include <bits/stdc++.h>

using namespace std;
#define FASTIO  cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
#define all(v) v.begin(), v.end()

const int MAX=(1<<16);
const int INF = 987654321;

double Dist[20][20];
double dp[20][MAX];
int n, full_bit;


double DFS(int cur, int visited){

    if(visited == full_bit){
        if(Dist[cur][0]){
            return Dist[cur][0];
        }
        else return INF;
        
    }

    if(dp[cur][visited] != 0) return dp[cur][visited];

    dp[cur][visited]=INF;
    for(int i=0;i<n; i++){
        
        if(!Dist[cur][i] || visited & (1<<i)) continue;
        dp[cur][visited] = min(dp[cur][visited], Dist[cur][i]+ DFS(i,visited | (1<<i)));
    }

    return dp[cur][visited];

}


double getDist(pi a, pi b){
    return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}

void solve(){
    cin >> n;
    full_bit=(1<<n)-1;
    memset(dp,0,sizeof(dp));
    vector<pi> input(n);
    for(int i=0;i<n;i++){
        cin >> input[i].first >> input[i].second;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            Dist[i][j] = Dist[j][i] = getDist(input[i],input[j]);
            //cout << Dist[i][j] << ' ';
        }
    }
    
    printf("%.15f\n",DFS(0,1));
    
}


int main()
{
    
    solve();
    return 0;
}
