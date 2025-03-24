#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	while (cin >> n) {
		if (n == 0) break;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < i; j++) {
				cout << '*';
			}
			cout << '\n';
		}
	}
	return 0;
}