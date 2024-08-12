#include <bits/stdc++.h>

using namespace std;
#define FASTIO  cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int arr[1001][1001],dp[1001][1001];

int main()
{
    FASTIO
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> arr[i][j];
            dp[i][j]= max(max(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + arr[i][j];
        }
    }
    cout << dp[n][m];
    return 0;
}