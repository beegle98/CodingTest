#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s; cin >> s;
    int n = 0, sum = 0, ans;
    for (char a : s) if (a == 'a') n++;
    for (int i = 0; i < n; i++) {
        if(s[i]=='b') sum++;
    }
    ans = sum;
    for (int i = n; i < n + s.size(); i++) {
        if (s[i - n] == 'b') sum--;
        if (s[i%s.size()] == 'b') sum++;
        ans = min(ans, sum);
    }
    cout << ans;
    return 0;
}