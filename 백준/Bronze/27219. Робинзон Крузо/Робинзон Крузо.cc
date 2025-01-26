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
    for (int i = 0; i < n / 5; i++) cout << "V";
    for (int i = 0; i < n % 5; i++) cout << "I";
    return 0;
}