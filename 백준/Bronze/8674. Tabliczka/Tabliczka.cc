#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll a, b; cin >> a >> b;
	if(a&1 && b&1) cout << min(a, b);
	else cout << "0";
	return 0;
}