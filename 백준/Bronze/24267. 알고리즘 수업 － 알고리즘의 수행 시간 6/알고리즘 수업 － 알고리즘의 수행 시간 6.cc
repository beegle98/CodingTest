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
    ll sum=0,n; cin >> n;
    for(int i=1;i<=n-2;i++){
        sum += (n-i)*(n-i-1)/2;
    }
    cout << sum << "\n3";
    return 0;
}