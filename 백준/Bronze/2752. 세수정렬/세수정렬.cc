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
    int a[3];
    for(int i=0;i<3;i++) cin >> a[i];
    sort(a,a+3);
    for(int i=0;i<3;i++) cout << a[i] << ' ';
    return 0;
}