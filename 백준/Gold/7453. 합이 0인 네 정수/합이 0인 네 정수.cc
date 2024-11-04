#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>

using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); 

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int arr[4][4001];

int main() {
	FASTIO
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		arr[0][i] = a;
		arr[1][i] = b;
		arr[2][i] = c;
		arr[3][i] = d;
	}
	
	ll ans = 0;
	vi v1, v2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			v1.push_back(arr[0][i] + arr[1][j]);
			v2.push_back(arr[2][i] + arr[3][j]);
		}
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	int idx = v1.size();
	int l = 0, r = idx - 1;

	while (l < idx && r >= 0) {
		if (v1[l] + v2[r] == 0) {
			ll cnt1 = 1, cnt2 = 1;
			l++, r--;
			while (l < idx && v1[l] == v1[l-1]) {
				cnt1++;
				l++;
			}
			while (r >= 0 && v2[r] == v2[r+1]) {
				cnt2++;
				r--;
			}
			ans += cnt1 * cnt2;
		}
		else if (v1[l] + v2[r] < 0) l++;
		else r--;
	}
	cout << ans;
	return 0;
}

