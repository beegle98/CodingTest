#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n; cin >> n;
    vector<pi> ans(12);
    ans[1] = { 12,1600 };
    ans[2] = { 11,894 };
    ans[3] = { 11,1327 };
    ans[4] = { 10,1311 };
    ans[5] = { 9,1004 };
    ans[6] = { 9,1178 };
    ans[7] = { 9,1357 };
    ans[8] = { 8,837 };
    ans[9] = { 7,1055 };
    ans[10] = { 6,556 };
    ans[11] = { 6,773 };
    cout << ans[n].first << " " <<ans[n].second;
    return 0;
}