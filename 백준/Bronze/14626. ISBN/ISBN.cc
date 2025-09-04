#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string str; cin >> str;
	int a, sum = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '*') {
			if (i & 1) a = 3;
			else a = 1;
			continue;
		}
		if (i & 1) sum += 3 * (str[i] - '0');
		else sum += (str[i] - '0');
	}
	for (int i = 0; i < 10; i++) {
		if ((sum + i * a) % 10 == 0) cout << i;
	}
	return 0;
}