#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;



int main(){
    int n,m,c; cin >> n >> m >> c;

    vi mooney(n+1);
    vector<vi> v(n+1);
    vector<vi> dp(n+1,vi(1001,-1));
    for(int i=1;i<=n;i++) cin >> mooney[i];

    for(int i=0;i<m;i++){
        int x,y; cin >> x >> y;
        v[x].push_back(y);
    }
    dp[1][0]=0;
    for(int t=1;t<1000;t++){
        for(int i=1;i<=n;i++){
            for(int j : v[i]){
                if(dp[i][t-1]==-1) continue;
                dp[j][t]=max(dp[j][t],dp[i][t-1]+mooney[j]);    
            }
        }
    }
    int ans = 0;
    for(int t=1;t<=1000;t++){
        ans = max(ans,dp[1][t]-c*t*t);
    }
    cout << ans;
    return 0;
}

