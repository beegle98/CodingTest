#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;


int main() {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<double> arr(n+1);
	for (int i = 0; i < n; i++) cin >> arr[i];
	double ans = 0, sum = 1;
	for (int i = 0; i < n; i++) {
		if (sum * arr[i] > 1) {
			sum *= arr[i];
			ans = max(ans, sum);
		}
		else {
			sum = 1;
			ans = max(ans, arr[i]);
		}
	}
	printf("%.3lf", ans);
	return 0;
}