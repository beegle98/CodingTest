#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<pll> arr(n);
	for (int i = 0;i < n;i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr.begin(), arr.end());
	ll s=arr[0].first, e=arr[0].second, ans=0;
	for (int i = 1;i < n;i++) {
		if (e <= arr[i].first) {
			ans += e - s;
			s = arr[i].first;
			e = arr[i].second;
		}
		else {
			e = max(e,arr[i].second);
		}
	}
	ans += e - s;
	cout << ans;
	return 0;
}