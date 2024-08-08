#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

priority_queue<int, vector<int>, less<int>> max_heap;
priority_queue<int, vector<int>, greater<int>> min_heap;

int main() {
	int a, b, n, x;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		
		if (max_heap.size() == min_heap.size()) {
			max_heap.push(x);
		}
		else {
			min_heap.push(x);
		}
		
		if (!max_heap.empty() && !min_heap.empty() && max_heap.top() > min_heap.top()) {
			int a = max_heap.top();
			int b = min_heap.top();

			max_heap.pop();
			min_heap.pop();
			
			max_heap.push(b);
			min_heap.push(a);
		}
		printf("%d\n", max_heap.top());
	}
	return 0;
}