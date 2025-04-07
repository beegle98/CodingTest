#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int n, t=0;
	while (cin >> n) {
		if (n == 0) break;
		t++;
		vector<double> s(n);
		for (int i = 0; i < n; i++) cin >> s[i];
		printf("Case %d: ",t);
		if (n & 1) {
			printf("%.1lf\n", s[n / 2]);
		}
		else {
			printf("%.1lf\n", (s[n / 2] + s[n / 2 - 1]) / 2);
		}
	}
	return 0;
}