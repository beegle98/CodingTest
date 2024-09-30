#include<bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;


int main(){
    FASTIO
    int n; cin >> n;
    for(int i=0;i<n;i++){
        ll a,b; cin >> a >> b;
        cout << a+b << '\n';
    }
    return 0;
}