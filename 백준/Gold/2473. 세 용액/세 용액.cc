#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;

int main() {
	int n; cin >> n;
	vector<ll> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	ll ans[3], Min = 1e12;
	for (int i = 0; i < n-2; i++) {
		for (int j = i + 1; j < n-1; j++) {
			ll res;
			int iter = lower_bound(v.begin()+j+1, v.end(), -(v[i]+v[j])) - v.begin();
			if (iter == n) iter--;
			else if (iter - 1 > j
				&& abs(v[i] + v[j] + v[iter]) > abs(v[i] + v[j] + v[iter - 1])) iter--;
			res = abs(v[i] + v[j] + v[iter]);
			if (res < Min) {
				ans[0] = v[i];
				ans[1] = v[j];
				ans[2] = v[iter];
				Min = res;
			}
		}
	}
	for (int i = 0; i < 3; i++) cout << ans[i] << " ";
	return 0;
}

