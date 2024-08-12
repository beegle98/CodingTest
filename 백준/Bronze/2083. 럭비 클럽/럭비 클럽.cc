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
    string s;
    int a,b;
    while(cin >> s >> a >> b){
        if(s=="#" && !a && !b){
            break;
        }
        cout << s;
        if(a > 17 || b >= 80){
            cout << " Senior\n";
        }
        else cout << " Junior\n";
    }
    return 0;
}