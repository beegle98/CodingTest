#include <bits/stdc++.h>

using namespace std;
#define FASTIO  cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;



int main()
{

    int n, score, p; cin >> n >> score >> p;
    vi s;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        s.push_back(x);
    }
    for(int i=n;i<p;i++) s.push_back(-1);
    int ans=-1;
    for(int i=0;i<p;i++){
        if(score>=s[i]){
            if(s[p-1]<score) ans = i+1;
            break;
        }
    }
    cout << ans;

    return 0;
}