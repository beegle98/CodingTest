#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a, b, c, d; cin >> a >> b >> c >> d;
	int sum = a + b + c + d;
	cout << sum / 60 << '\n' << sum % 60;
	return 0;
}