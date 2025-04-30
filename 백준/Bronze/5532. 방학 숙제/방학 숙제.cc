#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int L, A, B, C, D; cin >> L >> A >> B >> C >> D;
	int a = L - A / C - (A % C ? 1 : 0);
	int b = L - B / D - (B % D ? 1 : 0);
	cout << min(a, b);
	return 0;
}