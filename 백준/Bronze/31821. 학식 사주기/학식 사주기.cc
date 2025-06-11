#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, a[11]; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i+1];
	}
	cin >> m;
	int sum = 0;
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		sum += a[x];
	}
	cout << sum;
	return 0;
}