#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, a, b, c; cin >> n >> a >> b >> c;
	cout << min(n, a) + min(n, b) + min(n, c);
	return 0;
}