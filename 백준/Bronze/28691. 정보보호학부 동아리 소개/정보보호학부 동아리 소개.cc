#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
#define FASTIO cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);


int main() {
	FASTIO
	char c; cin >> c;
	string s;
	if (c == 'M') s = "MatKor";
	else if (c == 'W') s = "WiCys";
	else if (c == 'C') s = "CyKor";
	else if (c == 'A') s = "AlKor";
	else s = "$clear";
	cout << s;
	return 0;
}