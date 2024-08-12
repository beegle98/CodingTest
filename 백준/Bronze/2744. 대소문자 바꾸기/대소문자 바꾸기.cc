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
    for(int i=0;i<s.size();i++){
        if(s[i]>='a' && s[i]<='z'){
            cout << char(s[i]-'a'+'A');
        }
        else if(s[i]>='A' && s[i]<='Z'){
            cout << char(s[i]-'A'+'a');
        }
        else cout << s[i];
    }
}
