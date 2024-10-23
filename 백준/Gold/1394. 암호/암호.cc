#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;

const int MOD = 900528;
unordered_map<char,int> h;

int main(){
    string str, pwd; cin >> str >> pwd;
    int n = str.size();
    for(int i=0;i<n;i++){
        h[str[i]]=i+1;
    }
    int ans = 0;
    for(int i=0;i<pwd.size();i++){
        ans*=n;
        ans+=h[pwd[i]];
        ans%=MOD;
    }
    cout << ans;

    return 0;
}

