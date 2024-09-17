#include<bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef long long ll;

int n,b;
ll dp[2002][2002][2][2];
const ll MOD = 1e9;

ll f(int idx, int num, int i,int j){
	ll& res = dp[idx][num][i][j];
	if(res!=-1) return res;
	if(idx==n) return res = (i&&j);
	res = 0;
    if(num > 0) res = (res + f(idx+1, num-1, i | (num == 1), j)) % MOD;
    if(num < b-1) res = (res + f(idx+1, num+1, i, j | (num == b-2))) % MOD;
	return res;
}

int main() {
	FASTIO
	cin >> n >> b;
	memset(dp,-1,sizeof(dp));
	ll ans = 0;
	for(int i=1;i<b;i++){
		ans = (ans + f(1,i,0,i==b-1))%MOD;
	}
	cout << ans;
	return 0;
}