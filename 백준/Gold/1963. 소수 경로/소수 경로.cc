#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;
#define FASTIO  cin.tie(0);ios::sync_with_stdio(false)
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
#define all(v) v.begin(), v.end()


queue<pi> q;

bool visited[10001];
bool prime[10001];// false = 소수
int ans = -1;

void bfs(pi p, int ed) {
	int x = p.first;
	int cnt = p.second;
	visited[x] = true;
	if (x == ed) {
		if (ans == -1 || ans > cnt) ans = cnt;
		return;
	}
	string str = to_string(x);

	for (int i = 0; i < 4; i++) {
		string tmp = str;
		for (int j = 0; j <= 9; j++) {
			if (i == 0 && j == 0) continue;	
			tmp[i]= '0' + j;
			int num = stoi(tmp);
			
			if (!prime[num] && !visited[num]) {
				q.push({ num,cnt + 1 });
				//cout << x << " : " <<num << '\n';
			}
		}
	}
}

int main() {
	//FASTIO;

	int n; cin >> n;

	prime[1] = true;
	for (int i = 2; i*i <= 10000; i++) {
		if (prime[i]) continue;
		for (int j = i * i; j <= 10000; j += i) {
			prime[j] = true;
		}
	}
	
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		ans = -1;
		memset(visited, false, sizeof(visited));
		q.push({ a,0 });
		while (!q.empty()) {
			pi tmp = q.front();
			q.pop();
			bfs(tmp,b);
		}
		
		if (ans == -1) cout << "Impossible\n";
		else cout << ans << '\n';
	}

	return 0;
}
