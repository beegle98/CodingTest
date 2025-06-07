#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a, b, c; cin >> a >> b >> c;
	int sum = a + b + c;
	if (sum >= 100) cout << "OK";
	else {
		int MIN = min({ a,b,c });
		if (MIN == a) cout << "Soongsil";
		else if (MIN == b) cout << "Korea";
		else cout << "Hanyang";
	}
	return 0;
}