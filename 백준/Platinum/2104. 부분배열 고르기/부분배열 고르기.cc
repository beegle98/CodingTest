#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main() {
	FASTIO
	int n; cin >> n;
	ll ans = 0;
	
	vector<ll> sum(n + 1), arr(n+1);
	deque<pi> dq;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum[i] = sum[i-1] + arr[i];
	}
	dq.push_back({ arr[1],1 });
	for (int i = 2; i <= n; i++) {
		
		if (dq.back().first > arr[i]) {
			int idx = 1;
			while (!dq.empty() && dq.back().first > arr[i]) {
				idx = dq.back().second;
				//cout << (sum[i - 1] - sum[idx - 1])  << ' ' << (sum[i - 1] - sum[idx - 1]) * dq.back().first << '\n';
				ans = max(ans, (sum[i - 1] - sum[idx - 1]) * dq.back().first);
				
				dq.pop_back();
			}
			dq.push_back({ arr[i],idx });
		}
		else if(dq.back().first < arr[i]){
			dq.push_back({ arr[i],i });
		}
		
	}
	while(!dq.empty()) {
		//cout << (sum[n] - sum[dq.back().second - 1])*dq.back().first << '\n';
		ans = max(ans,(sum[n]-sum[dq.back().second-1])*dq.back().first);
		dq.pop_back();
	}
	cout << ans;
	return 0;
}