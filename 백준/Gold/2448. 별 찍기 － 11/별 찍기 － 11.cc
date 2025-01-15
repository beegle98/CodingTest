#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

char s[3500][7000];
int n;
int star(int n, int x, int y) {
	if (n == 1) {
		s[y][x] = '*';
		s[y + 1][x - 1] = '*';
		s[y + 1][x + 1] = '*';
		s[y + 2][x - 2] = '*';
		s[y + 2][x - 1] = '*';
		s[y + 2][x] = '*';
		s[y + 2][x + 1] = '*';
		s[y + 2][x + 2] = '*';
	}
	else {
		star(n / 2, x, y);
		star(n / 2, x + 3 * n / 2, y + 3 * n / 2);
		star(n / 2, x - 3 * n / 2, y + 3 * n / 2);
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	
	star(n / 3, n, 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < 2*n; j++) {
			if (s[i][j] == '*') cout << s[i][j];
			else cout << " ";
			
		}
		if(i!=n) cout <<" \n";
	}
	return 0;

}
