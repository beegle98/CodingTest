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
    int a,b,n; cin >> a >> b >> n;
    for(int i=0;i<n;i++){
        a%=b;
        a*=10;
    }
    cout << a/b;
    return 0;
}