#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a, b, c; cin >> a >> b >> c;
    if (a + b + c <= 21) cout << 1;
    else cout << 0;
    return 0;
}