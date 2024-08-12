#include <bits/stdc++.h>

using namespace std;
#define FASTIO  cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

void recur(int n){
    if(n==0){
        cout << "-";
        return;
    }
    recur(n-1);
    for(int i=0;i<(int)pow(3,n-1);i++) cout << ' ';
    recur(n-1);
}

int main()
{
    int n;
    while(cin >> n){
        recur(n);
        cout << '\n';
    }
    return 0;
}