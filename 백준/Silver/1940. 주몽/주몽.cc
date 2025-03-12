#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m; cin >> n >> m;
	vi arr(n);
	for (int i = 0;i < n;i++) cin >> arr[i];
	sort(arr.begin(), arr.end());
	int st = 0, ed = n - 1, ans=0;
	while (st < ed) {
		int sum = arr[st] + arr[ed];
		if (sum == m) {
			st++;
			ans++;
		}
		else if (sum > m) ed--;
		else st++;
	}
	cout << ans;
	return 0;
}