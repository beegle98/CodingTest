#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int k;
vector<pair<char, int>> command;
map<int, int> cnt;

void solution() {
    priority_queue<int, vector<int>, less<int>> up;
    priority_queue<int, vector<int>, greater<int>> lo;

    for (int i = 0; i < command.size(); i++) {
        char c = command[i].first;
        int n = command[i].second;

        if (c == 'I') {
            up.push(n);
            lo.push(n);
            cnt[n]++;
        }
        else {
            if (n == 1) {
                if (!up.empty()) {
                    cnt[up.top()]--;
                    up.pop();
                }
            }
            else {
                if (!lo.empty()) {
                    cnt[lo.top()]--;
                    lo.pop();
                }
            }
            while (!up.empty() && cnt[up.top()] == 0) up.pop();
            while (!lo.empty() && cnt[lo.top()] == 0) lo.pop();
        }
    }

    while (!up.empty() && cnt[up.top()] == 0) up.pop();
    while (!lo.empty() && cnt[lo.top()] == 0) lo.pop();

    if (up.empty() || lo.empty()) cout << "EMPTY" << "\n";
    else cout << up.top() << " " << lo.top() << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        command.clear();
        cnt.clear();

        cin >> k;

        char c;
        int n;
        for (int i = 0; i < k; i++) {
            cin >> c >> n;

            command.push_back({ c,n });
        }

        solution();
    }

    return 0;
}