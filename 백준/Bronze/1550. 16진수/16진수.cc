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
    string s;
    cin >> s;

    int t = 1;
    int sum = 0;
    for (int i = s.size()-1; i >= 0;i--){
        if('0'<= s[i] && s[i] <='9')
            sum += (s[i] - '0') * t;
        else
            sum += (s[i] - 'A' + 10) * t;

        t *= 16;
    }
    cout << sum;
    return 0;
}
