#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

int n, k;
int dp[100001];

int main() {
	cin >> n >> k;
	int ans = 0, sum[2] = { 0,0 };
	vector<int> cost, money;
	for (int i = 0; i < n; i++) {
		int t1, t2, m1, m2; cin >> t1 >> m1 >> t2 >> m2;
		if (m1 < m2) {
			int tmp = m2; m2 = m1; m1 = tmp;
			tmp = t1; t1 = t2; t2 = tmp;
		}
		if (t1 <= t2) {
			k -= t1;
			sum[1] += m1;
			continue;
		}
		cost.push_back(t1 - t2);
		money.push_back(m1 - m2);
		sum[0] += t2;
		sum[1] += m2;
	}
	
	k -= sum[0]; // 문제에서 k는 sum[0](cost 합의 최솟값)보다 무조건 크다는 것을 알려줌
	int N = money.size();
	for (int i = 0; i < N; i++) {
		for (int j = k; j >= cost[i]; j--) {
			dp[j] = max(dp[j], money[i] + dp[j - cost[i]]);
		}
	}
	
	cout << sum[1]+dp[k];
	return 0;
}

