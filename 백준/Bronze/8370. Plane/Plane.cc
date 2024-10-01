#include<bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;


int main(){
    FASTIO
    int n1,n2,k1,k2; cin >> n1 >> k1 >> n2 >> k2;
    cout << n1*k1+n2*k2;
    return 0;
}