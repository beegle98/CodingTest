#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll d, p, q; cin >> d >> p >> q;
    if (p < q) swap(p, q);
    ll ans = (d / p + 1) * p; // 초기값 p만 쓴 경우
    for (int i = 0; i < min(q,d / p + 1); i++) {// d/p개까지만 고려
        ll Qamount = (d - p * i) / q;
        for(int j=max(0ll,Qamount);j<Qamount+2;j++){
            if (p * i + q * j < d) continue;
            ans = min(ans, p * i + q * j);
        }
    }
    cout << ans;
    return 0;
}