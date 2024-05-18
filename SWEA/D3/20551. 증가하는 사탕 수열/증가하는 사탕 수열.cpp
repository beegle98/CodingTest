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

    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        int ans=0,a,b,c; cin >> a >> b >> c;
        if(b<2 || c<3) ans=-1;
        else{
            if(b>=c){
                ans += b-c+1;
                b=c-1;
            }
            if(a>=b){
                ans += a-b+1;
                a=b-1;
            }
        }
        cout << "#" << t << ' ' << ans << '\n';
    }
    return 0;
}
