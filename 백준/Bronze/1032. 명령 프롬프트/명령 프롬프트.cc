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
    string s,ans;
    int n; cin >> n >> ans;
    for(int i=0;i<n-1;i++){
        cin >> s;
        for(int j=0;j<s.size();j++){
            if(s[j]!=ans[j]) ans[j]='?';
        }
    }
    cout << ans;
}
