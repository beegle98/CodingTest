#include <bits/stdc++.h>
  
using namespace std;
#define FASTIO cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

ll f(int x){
    if(x<=1) return 1;
    return x*f(x-1);
}

int main(){
    FASTIO
    
    int n; cin >> n;

    cout << f(n);
    return 0;
}