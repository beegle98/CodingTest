#include <bits/stdc++.h>

using namespace std;
#define FASTIO cin.tie(0);ios::sync_with_stdio(false);
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

void f1(int n){
    if(n==0) return;
    f1(n/2);
    cout << n%2; 
}
void f(int n,int cnt){
    if(cnt==0) return;
    f(n/2,cnt-1);
    cout << n%2; 
}

int main(){
    FASTIO
    string s; cin >> s;
    f1(s[0]-'0');
    if(s[0]-'0'==0) cout << '0';
    for(int i=1;i<s.size();i++){
        int k = s[i]-'0';
        f(k,3);
    }
}
