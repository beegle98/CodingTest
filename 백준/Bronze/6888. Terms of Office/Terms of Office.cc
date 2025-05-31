#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a, b; cin >> a >> b;
	while (a <= b) {
		cout << "All positions change in year " << a << '\n';
		a += 60;
	}
	return 0;
}