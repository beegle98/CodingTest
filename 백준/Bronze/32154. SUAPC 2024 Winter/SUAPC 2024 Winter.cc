#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    map<int, pair<int, vi>> m;
    m[1] = { 11,{0,1,2,3,4,5,6,7,9,11,12} };
    m[2] = { 9,{0,2,4,5,6,7,8,11,12} };
    m[3] = { 9,{0,2,4,5,6,7,8,11,12} };
    m[4] = { 9,{0,1,2,4,5,6,7,11,12} };
    m[5] = { 8,{0,2,4,5,6,7,11,12} };
    m[6] = { 8,{0,2,4,5,6,7,11,12} };
    m[7] = { 8,{0,2,4,5,6,7,11,12} };
    m[8] = { 8,{0,2,4,5,6,7,11,12} };
    m[9] = { 8,{0,2,4,5,6,7,11,12} };
    m[10] = { 8,{0,1,2,5,6,7,11,12} };

    int n; cin >> n;
    cout << m[n].first << '\n';
    for (int x : m[n].second) cout << char(x + 'A') << ' ';
    return 0;
}