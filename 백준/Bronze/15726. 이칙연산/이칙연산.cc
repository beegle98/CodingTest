#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	double a, b, c; cin >> a >> b >> c;
	cout << max((int)(a * b / c), (int)(a / b * c));
	return 0;
}
