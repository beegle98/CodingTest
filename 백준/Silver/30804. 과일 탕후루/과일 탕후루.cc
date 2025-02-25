#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

vi arr, cnt(200022);
int ans, len, sum;
void Minus(int x) {
	if (--cnt[arr[x]] == 0) sum--;
	len--;
}
void Plus(int x) {
	if (cnt[arr[x]]++ == 0) sum++;
	len++;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	arr = vi(n);
	for (int i = 0;i < n;i++) cin >> arr[i];
	int l=0, r=0;
	while (r < n){
		if (sum > 2) Minus(l++);
		else Plus(r++);
		if (sum <= 2) ans = max(ans, len);
	}
	cout << ans;
	return 0;
}