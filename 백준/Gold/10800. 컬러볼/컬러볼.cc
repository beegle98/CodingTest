#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int cnt[200001];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vector<pair<pi,int>> arr(n);
	vi ans(n);
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		arr[i] = { {y,x},i };
	}
	sort(arr.begin(), arr.end());
	int psum = arr[0].first.first, sum = 0;
	cnt[arr[0].first.second] += psum;
	for (int i = 1; i < n; i++) {
		int idx = arr[i].second;
		int ff = arr[i].first.first;
		int fs = arr[i].first.second;
		
		if (ff > arr[i - 1].first.first) {
			sum += psum;
			psum = 0;
		}
		if (ff == arr[i - 1].first.first && fs == arr[i - 1].first.second) {
			ans[idx] = ans[arr[i - 1].second];
		}
		else ans[idx] = sum - cnt[fs];
		psum += ff;
		cnt[fs] += ff;
	}
	for (int i = 0; i < n; i++) cout << ans[i] << '\n';
	return 0;
}