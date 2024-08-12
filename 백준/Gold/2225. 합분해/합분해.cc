#include <bits/stdc++.h>

using namespace std;
#define FASTIO  cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

const ll MOD = 1e9;
ll dp[222][222];

int main()
{
    FASTIO
    int n,k; cin >> n >> k;
    for(int i=1;i<=k;i++) dp[0][i]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j] = (dp[i-1][j]+dp[i][j-1])%MOD;
        }
    }
    cout << dp[n][k];
    return 0;
}