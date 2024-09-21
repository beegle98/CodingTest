#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef long long ll;

const int N = 100001;
ll sum[N], dp[N][2], k, cnt;

int main() {
	FASTIO
	int n; cin >> n;
	for(int i=1;i<=n;i++){
		int x; cin >> x;
		sum[i]=sum[i-1]+x;
		if(sum[i]==0) cnt++;
	}
	ll ans = 0;
	if(sum[n]%4){
		cout << ans;
		return 0;
	}
	if(sum[n]==0){
		ans = cnt * (cnt-1) * (cnt-2) * (cnt-3) / (4*3*2);
		cout << ans;
		return 0;
	}
	k = sum[n]/4;
	for(int i=1;i<=n;i++){
		for(int j=0;j<2;j++) dp[i][j] = dp[i-1][j];
		if(sum[i]==k) dp[i][0]++;
		else if(sum[i]==2*k) dp[i][1] += dp[i-1][0];
		else if(sum[i]==3*k){
			ans += dp[i-1][1];
		}
	}
	cout << ans;
	return 0;
}