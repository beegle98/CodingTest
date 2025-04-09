#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int sum[2];
	for (int i = 0; i < 2; i++) {
		sum[i] = 0;
		for(int j=0;j<4;j++){
			int a; cin >> a;
			sum[i] += a;
		}
	}
	cout << max(sum[0], sum[1]);
	return 0;
}