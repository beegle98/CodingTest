#include <bits/stdc++.h>

using namespace std;
#define FASTIO  cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
#define all(v) v.begin(), v.end()


int main()
{
    FASTIO
    int s[3];
    for(int i=0;i<3;i++) cin >> s[i];
    sort(s,s+3);
    string str; cin >> str;
    for(int i=0;i<3;i++){
        cout << s[str[i]-'A'] << ' ';
    }

    return 0;
}


