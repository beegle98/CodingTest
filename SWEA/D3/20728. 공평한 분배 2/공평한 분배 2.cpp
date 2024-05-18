#include <bits/stdc++.h>

using namespace std;
#define FASTIO cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

int main(){
    FASTIO

    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        int n,k; cin >> n >> k;
        vll s;
        for(int i=0;i<n;i++){
            ll x; cin >> x;
            s.push_back(x);
        }
        sort(s.begin(),s.end());
        ll Min=s[k-1]-s[0];
        for(int i=1;i<=n-k;i++){
            if(Min > s[i+k-1]-s[i]){
                Min = s[i+k-1]-s[i];
            }
        }
        cout << "#" << t << ' ' << Min << '\n';
    }
    return 0;
}
