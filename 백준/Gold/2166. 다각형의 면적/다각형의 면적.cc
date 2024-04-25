#include <bits/stdc++.h>
  
using namespace std;
#define FASTIO cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef long double ld;




int main(){
    FASTIO
    ld ans=0;
    vector<pair<ld,ld>> s;
    int n; cin >> n;
    for(int i=0;i<n;i++){
        ld x,y; cin >> x >> y;
        s.push_back({x,y});

    }
    s.push_back(s.front());
    for(int i=0;i<n;i++){// 신발끈 공식
        ans += s[i].first * s[i+1].second - s[i+1].first * s[i].second;
    }
    ans = abs(ans)/2;
    cout << fixed;
    cout.precision(1);
    cout << ans;
    return 0;
}