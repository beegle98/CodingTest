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
    int n; cin >> n;
    for(int i=0;i<n;i++){
        int a,b,c; cin >> a >> b;
        c=1;
        for(int j=0;j<b;j++){
            c=(c*a)%10;
        }
        if(c==0) cout << "10\n";
        else cout << c << '\n';
    }
    return 0;
}
