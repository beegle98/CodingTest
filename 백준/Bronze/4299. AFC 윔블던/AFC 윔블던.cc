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
	int sum = a + b;
	if (a<b || sum & 1) cout << "-1";
	else {
		cout << sum / 2 << " " << a - sum / 2;
	}
	
	return 0;
}