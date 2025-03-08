#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n,m; cin >> n >> m;
    vi arr(m);
    for (int i = 0; i < m; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    int Max = 0, ans=0;
    for(int i=0;i<m;i++){
        int sum = arr[i] * min(n, m - i);
        if (Max < sum) {
            Max = sum;
            ans = arr[i];
        }
    }
    cout << ans << " " << Max;
    return 0;
}
