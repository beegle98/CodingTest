#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s = "WelcomeToSMUPC"; // 14
    int n; cin >> n;
    n %= 14;
    if (n == 0) n = 14;
    cout << s[n - 1];
    return 0;
}