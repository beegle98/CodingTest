#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;



int main(){
    int ans=0,n; cin >> n;
    string s; cin >> s;
    for(int i=0;i<n;i++){
        if(s[i]=='a' ||s[i]=='i' ||s[i]=='u' ||s[i]=='e' ||s[i]=='o') ans++;
    }
    cout << ans;
    return 0;
}

