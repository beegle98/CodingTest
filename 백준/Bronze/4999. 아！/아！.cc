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
    string s1,s2; cin >> s1 >> s2;
    if(s1.size()>=s2.size()) cout << "go\n";
    else cout << "no\n";
    return 0;
}