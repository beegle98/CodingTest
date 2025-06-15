#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int ax, ay, az; cin >> ax >> ay >> az;
	int cx, cy, cz; cin >> cx >> cy >> cz;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			for (int k = 1; k <= 100; k++) {
				if (az + i == cx && ay * j == cy && ax + k==cz) {
					cout << i << " " << j << " " << k;
					return 0;
				}
			}
		}
	}

	return 0;
}