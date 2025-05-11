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
	cout << min({ (2*b+4*c),(2*a+2*c),(4*a+2*b) });
	return 0;
}