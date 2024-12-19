#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vi s(n), LIS;
    
    for (int i = 0; i < n; i++) cin >> s[i];
    LIS.push_back(s[0]);
    for (int i = 1; i < n; i++) {
        if (LIS.back() < s[i]) LIS.push_back(s[i]);
        else {
            int itr = lower_bound(LIS.begin(), LIS.end(),s[i])-LIS.begin();
            LIS[itr] = s[i];
        }
    }
    cout << LIS.size();
    return 0;
}