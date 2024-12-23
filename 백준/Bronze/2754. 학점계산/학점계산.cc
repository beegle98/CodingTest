#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;


int main() {
	//cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	
	string s; cin >> s;
	double ans=0.0;
	if (s[0] == 'F') {
		ans = 0;
	}
	else {
		if (s[0] == 'A') {
			ans = 4.0;
		}
		else if (s[0] == 'B') {
			ans = 3.0;
		}
		else if (s[0] == 'C') {
			ans = 2.0;
		}
		else{
			ans = 1.0;
		}
		if (s[1] == '+') {
			ans += 0.3;
		}
		else if (s[1] == '-') {
			ans += -0.3;
		}
	}
	printf("%0.1lf", ans);
	return 0;
}
