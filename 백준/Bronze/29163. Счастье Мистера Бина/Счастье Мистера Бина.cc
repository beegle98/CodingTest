#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;


int main() {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	
	int sum=0,n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x % 2) sum--;
		else sum++;
	}
	if (sum > 0) cout << "Happy";
	else cout << "Sad";
	return 0;
}
