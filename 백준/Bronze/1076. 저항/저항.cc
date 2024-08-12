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
    FASTIO
    string color[10]={"black", "brown", "red", "orange", "yellow","green", "blue", "violet", "grey", "white"};
    int m[3];
    for(int i=0;i<3;i++){
        string s; cin >> s;
        for(int j=0;j<10;j++){
            if(!s.compare(color[j])){
                m[i]=j;
            }
        }
    }
    ll ans;
    ans= m[0]*10 + m[1];
    for(int i=0;i<m[2];i++) ans*=10;
    cout << ans;
    return 0;
}