#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define FASTIO  cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
#define all(v) v.begin(), v.end()

priority_queue<int> pq;

int main()
{
	FASTIO
		int N, K; cin >> N >> K;

	vector<pi> arr(N); // 무게, 가격
	vi bp(K); // 가방
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	for (int i = 0; i < K; i++) {
		cin >> bp[i];
	}
	sort(all(arr));
	sort(all(bp));

	ll sum = 0;
	int index = 0;
	for (int i = 0; i < K; i++) {
		while (index < N && arr[index].first <= bp[i]) {
			pq.push(arr[index].second);
			index++;
		}
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}

	}
	cout << sum;
	return 0;
}
