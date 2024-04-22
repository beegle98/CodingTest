#include <bits/stdc++.h>
  
using namespace std;
#define FASTIO cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

int main(){
    FASTIO
    int n; cin >> n;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        cout << s[0] << s.back() << '\n';
    }
    return 0;
}