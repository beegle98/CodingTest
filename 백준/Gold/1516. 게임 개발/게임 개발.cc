#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

#define MAX 501
int n;
int indegree[MAX], cost[MAX], totalCost[MAX];
vi v[MAX];

void topology() {
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            totalCost[i] = cost[i];
        }
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i];
            totalCost[next] = max(totalCost[next], totalCost[cur] + cost[next]);
            indegree[next]--;
            if (indegree[next] == 0) q.push(next);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int c; cin >> c;
        cost[i] = c;

        while (1) {
            int prev; cin >> prev;
            if (prev == -1) break;

            v[prev].push_back(i);
            indegree[i]++;
        }
    }

    topology();

    for (int i = 1; i <= n; i++) {
        cout << totalCost[i] << "\n";
    }

    return 0;
}