#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

void solve(int n) {
	if (n % 15 == 0) cout << "FizzBuzz";
	else if (n % 3 == 0) cout << "Fizz";
	else if (n % 5 == 0) cout << "Buzz";
	else cout << n;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	for (int i = 3; i >= 1; i--) {
		string s; cin >> s;
		if (s != "Fizz" && s != "Buzz" && s != "FizzBuzz") n = stoi(s) + i;
	}
	solve(n);
	return 0;
}
