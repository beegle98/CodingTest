#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
#define FASTIO cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);


int main() {
	int n; cin >> n;
	n %= 3;
	char ans;
	if (n == 0) ans = 'S';
	else if (n == 1) ans = 'U';
	else ans = 'O';
	cout << ans;
	return 0;
} 