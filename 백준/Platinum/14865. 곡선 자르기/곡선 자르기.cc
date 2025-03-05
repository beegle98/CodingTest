#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n; cin >> n;
	vector<pi> s(n);
	for (int i = 0;i < n;i++) {
		cin >> s[i].first >> s[i].second;
	}
	s.push_back(s[0]);
	vi up, down;
	vector<pi> arr;
	deque<pair<pi,int>> dq;
	
	for(int i=1;i<=n;i++){
		if (s[i - 1].second <= 0 && s[i].second > 0) {
			up.push_back(s[i].first);
		}
		else if (s[i - 1].second > 0 && s[i].second <= 0) {
			down.push_back(s[i].first);
			if (!up.empty()) {
				int u = up.back();
				up.pop_back();
				int d = down.back();
				down.pop_back();
				if(u < d) arr.push_back({ u,d });
				else arr.push_back({ d,u });
			}
		}
	}
	while (!up.empty() && !down.empty()) {
		int u = up.back();
		up.pop_back();
		int d = down.back();
		down.pop_back();
		if (u < d) arr.push_back({ u,d });
		else arr.push_back({ d,u });
	}
	sort(arr.begin(), arr.end());
	vector<bool> cnt1(arr.size()); // 포함 되는 여부 (0,1 반대)
	vector<bool> cnt2(arr.size()); // 포함 하는 여부 (0,1 반대)
	if (!arr.empty()) dq.push_back({ arr[0],0 });
	for (int i = 1;i < arr.size();i++) {
		while (!dq.empty() && dq.back().first.second < arr[i].first) dq.pop_back();
		if (!dq.empty() && dq.back().first.second > arr[i].first) { // 포함
			cnt1[i] = true; // 포함 됨
			cnt2[dq.back().second] = true; // 포함 함
		}
		dq.push_back({ arr[i], i });
	}
	int ans1 = 0, ans2 = 0;
	for (int i = 0;i < arr.size();i++) {
		if (!cnt1[i]) ans1++;
		if (!cnt2[i]) ans2++;
	}
	cout << ans1 << " " << ans2;
	return 0;
}