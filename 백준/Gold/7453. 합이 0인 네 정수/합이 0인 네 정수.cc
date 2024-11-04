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
	vi v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			v.push_back(arr[0][i] + arr[1][j]);
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int t = -(arr[2][i] + arr[3][j]);
			int low = lower_bound(v.begin(), v.end(), t) - v.begin();
			int up = upper_bound(v.begin(), v.end(), t) - v.begin();
			ans += up - low;
		}
	}
	cout << ans;
	return 0;
}

