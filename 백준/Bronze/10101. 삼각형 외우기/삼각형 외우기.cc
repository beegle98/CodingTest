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
    int a,b,c; cin >> a >> b >> c;
    if(a+b+c==180){
        if(a==b && b==c) cout << "Equilateral\n";
        else if(a==b || b==c || a==c) cout << "Isosceles\n";
        else cout << "Scalene\n";
    }
    else cout << "Error\n";
    return 0;
}