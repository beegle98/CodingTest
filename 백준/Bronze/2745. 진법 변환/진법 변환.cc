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
    string s; cin >> s;
    ll n,m=0,k; cin >> n;
    k=1;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]>='0' && s[i]<='9'){
            m += (s[i]-'0')*k;
        }
        else{//A~Z
            m += (s[i]-'A'+10)*k;
        }
        k*=n;
    }
    cout << m;
    return 0;
}
