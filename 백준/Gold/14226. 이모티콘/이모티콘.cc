#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
int ans,n,dp[3001];
queue<pair<int,pair<int,int>>> q;// n, cnt, clipboard

void f(int x, pair<int,int> p) {
	//cout << x << ' '<<q.size() << '\n';
	if (x > 1500) return;
	dp[x] = p.first;
	if (x == n) {
		ans = p.first;
		dp[n] = ans;
		while (!q.empty()) q.pop();
		return;
	}
	if (dp[x-1]==0 && x > 2) q.push({ x - 1,{p.first + 1,p.second} });
	if (dp[x+p.second]==0 && p.second > 0) {
		q.push({ x+p.second,{p.first+1,p.second} });
	}
	if(p.second!=x) q.push({ x,{p.first + 1,x} });

}

int main() {
	cin >> n;
	dp[1] = 0;
	q.push({ 1,{0, 0} });
	while (!q.empty()) {
		pair<int, pair<int, int>> tmp = q.front();
		q.pop();
		f(tmp.first, tmp.second);
	}
	cout << dp[n];
	return 0;
}
