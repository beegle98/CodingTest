#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string check[7] = {
        "Never gonna give you up",
        "Never gonna let you down",
        "Never gonna run around and desert you",
        "Never gonna make you cry",
        "Never gonna say goodbye",
        "Never gonna tell a lie and hurt you",
        "Never gonna stop"
    };
    int n, ans=1; cin >> n;
    string s; getline(cin, s);
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        int key = 1;
        for (int j = 0; j < 7; j++) {
            if (s == check[j]) key = 0;
        }
        if (key) ans = 0;
    }
    if (ans) cout << "No";
    else cout << "Yes";
    return 0;
}