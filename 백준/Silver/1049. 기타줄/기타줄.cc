#include <bits/stdc++.h>

using namespace std;
#define FASTIO cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;



int main(){
    FASTIO
    int sum=0,n,m; cin >> n >> m;
    int m1=10000,m2=10000;
    for(int i=0;i<m;i++){
        int x,y; cin >> x >> y;
        m1 = min(x,m1);
        m2 = min(y,m2);
    }
    sum = m2 * n;
    sum = min(n/6*m1+min(n%6*m2, m1), sum);
    cout << sum;
}