#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, sum=0; cin >> n;
	for (int i = 0; i < 5; i++) {
		int x; cin >> x;
		if (x % 10 == n) sum++;
	}
	cout << sum;
	return 0;
}