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
    int a,b;
    while(cin >> a >> b){
        if(a==0 && b==0) break;
        if(a>b) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}